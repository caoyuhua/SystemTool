/* $Id: simple_pjsua.c 3553 2011-05-05 06:14:19Z nanang $ */
/* 
 * Copyright (C) 2008-2011 Teluu Inc. (http://www.teluu.com)
 * Copyright (C) 2003-2008 Benny Prijono <benny@prijono.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */

/**
 * simple_pjsua.c
 *
 * This is a very simple but fully featured SIP user agent, with the 
 * following capabilities:
 *  - SIP registration
 *  - Making and receiving call
 *  - Audio/media to sound device.
 *
 * Usage:
 *  - To make outgoing call, start simple_pjsua with the URL of remote
 *    destination to contact.
 *    E.g.:
 *	 simpleua sip:user@remote
 *
 *  - Incoming calls will automatically be answered with 200.
 *
 * This program will quit once it has completed a single call.
 */

#include <pjsua-lib/pjsua.h>
#include <curl/curl.h>
#include <libubox/uloop.h>
#include <libubox/utils.h>
#include <libubus.h>
#include <sys/sysinfo.h>


#define THIS_FILE	"Imcenter"

#define SIP_DOMAIN	"wuliangroup.cn"
#define SIP_USER	"1033"
#define SIP_PASSWD	"1033"
#define current_acc	pjsua_acc_get_default()

char *ubus_socket = NULL;
static struct ubus_context *ctx;
static struct uloop_timeout ubus_timer;
static struct blob_buf b;
static int notify;
static struct ubus_context *_ctx;



static void
imcenter_subscribe_cb(struct ubus_context *ctx, struct ubus_object *obj)
{
	notify = obj->has_subscribers;
}

enum {
	BUDDY_ID,
	__BUDDY_MAX
};
static const struct blobmsg_policy buddy_policy[__BUDDY_MAX] = {
	[BUDDY_ID] = { .name = "id", .type = BLOBMSG_TYPE_STRING }
};

static int get_buddy(struct ubus_context *ctx, struct ubus_object *obj,
                struct ubus_request_data *req, const char *method,
                struct blob_attr *msg)
{
	void *c;
	pjsua_buddy_id ids[64];
    int i;
    unsigned count = PJ_ARRAY_SIZE(ids);
	pjsua_enum_buddies(ids, &count);
	blob_buf_init(&b, 0);

	c = blobmsg_open_array(&b, "Buddylist");
	
	if (count == 0)
		blobmsg_add_string(&b, NULL, " -none-");
    else {
		for (i=0; i<(int)count; ++i) {
		    pjsua_buddy_info info;

		    if (pjsua_buddy_get_info(ids[i], &info) != PJ_SUCCESS)
				continue;
			blobmsg_add_string
				(&b, NULL, info.uri.ptr);
		}
    }
	blobmsg_close_array(&b, c);

	ubus_send_reply(ctx, req, b.head);

	return UBUS_STATUS_OK;
}




static int add_buddy(struct ubus_context *ctx, struct ubus_object *obj,
                struct ubus_request_data *req, const char *method,
                struct blob_attr *msg)
{
	struct blob_attr *tb[__BUDDY_MAX];
	char *p = NULL;
	const char *status;
	char out_str[80];

	if (!msg)
		return UBUS_STATUS_INVALID_ARGUMENT;

	blobmsg_parse(buddy_policy, __BUDDY_MAX, tb, blob_data(msg), blob_len(msg));
	if (tb[BUDDY_ID]) {
		p = blobmsg_get_string(tb[BUDDY_ID]);
		
	    pjsua_buddy_config buddy_cfg;
	    pjsua_buddy_id buddy_id;
	    pj_status_t status = PJ_SUCCESS;

	    if (pjsua_verify_url(p) != PJ_SUCCESS) {
			pj_ansi_snprintf(out_str, sizeof(out_str),
					 "Invalid URI '%s'\n", p);
	    } else {
			pj_bzero(&buddy_cfg, sizeof(pjsua_buddy_config));

			buddy_cfg.uri = pj_str(p);
			buddy_cfg.subscribe = PJ_TRUE;

			status = pjsua_buddy_add(&buddy_cfg, &buddy_id);
			if (status == PJ_SUCCESS) {
			    pj_ansi_snprintf(out_str, sizeof(out_str),
					      "New buddy '%s' added at index %d\n",
					      p, buddy_id+1);
			}
	    }
	}

	blob_buf_init(&b, 0);
	blobmsg_add_string(&b, "status", out_str);
	ubus_send_reply(ctx, req, b.head);

	return UBUS_STATUS_OK;
}




static const struct ubus_method buddy_methods[] = {
	UBUS_METHOD("add", add_buddy, buddy_policy),
	UBUS_METHOD_NOARG("get", get_buddy),
};

static struct ubus_object_type buddy_object_type =
	UBUS_OBJECT_TYPE("buddy", buddy_methods);

static struct ubus_object buddy_object = {
	.name = "buddy",
	.type = &buddy_object_type,
	.methods = buddy_methods,
	.n_methods = ARRAY_SIZE(buddy_methods),
	.subscribe_cb = imcenter_subscribe_cb,
};

void ubus_init_buddy(struct ubus_context *ctx)
{
	int ret;

	_ctx = ctx;
	ret = ubus_add_object(ctx, &buddy_object);
	if (ret)
		PJ_LOG(4,(THIS_FILE,"Failed to add object: %s\n", ubus_strerror(ret)));
}

static void
ubus_reconnect_cb(struct uloop_timeout *timeout)
{
	if (!ubus_reconnect(ctx, ubus_socket))
		ubus_add_uloop(ctx);
	else
		uloop_timeout_set(timeout, 2000);
}

static void
ubus_disconnect_cb(struct ubus_context *ctx)
{
	ubus_timer.cb = ubus_reconnect_cb;
	uloop_timeout_set(&ubus_timer, 2000);
}

static void
ubus_connect_cb(struct uloop_timeout *timeout)
{
	ctx = ubus_connect(ubus_socket);

	if (!ctx) {
		PJ_LOG(4, (THIS_FILE,"Connection to ubus failed\n"));
		uloop_timeout_set(&ubus_timer, 1000);
		return;
	}

	ctx->connection_lost = ubus_disconnect_cb;
	ubus_init_buddy(ctx);

	PJ_LOG(2, (THIS_FILE,"Connected to ubus, id=%08x\n", ctx->local_id));
	ubus_add_uloop(ctx);
}

void
imcenter_connect_ubus(void)
{
	ubus_timer.cb = ubus_connect_cb;
	uloop_timeout_set(&ubus_timer, 1000);
}


enum Message {
	INVALID_MESSAGE = 0,
	REQ_MOBILE_TO_HTTP = 1,
	RSP_MOBILE_TO_HTTP = 2,
	REQ_MOBILE_TO_SMART = 3,
	RSP_MOBILE_TO_SMART = 4,
	REQ_SERVER_TO_ROUTER=5,
	RSP_SERVER_TO_ROUTER=6,
	PUSH_SMART_TO_MOBILE = 7,
	PUSH_ROUTER_TO_MOBILE = 8
};

enum ErrorType {
	NO_ERROR = 0,
	UNKNOWN_PROTOCOL_VERSION = 1,
	UNKNOWN_MESSAGE_TYPE_VERSION = 2,
	PARSE_ERROR = 3,
	HTTP_ERROR = 4,
	HTTP_TIMEOUT = 5
};


int stringDecode(char *pData, char *pret, int length)
{
	uint32_t slen = ntohl(*((uint32_t*)(pData)));
	if (slen > length)
	{
		return -1;
	}
	memcpy(pret, pData+4, slen);
	return slen + 4;
}

int stringEncode(char *pData, char *url)
{
	*((uint32_t*)(pData)) = htonl(strlen(url));
	pData += 4;
	memcpy(pData, url, strlen(url));
	return strlen(url) + 4;
}



#define WULIAN_PROTOL_VERSION	1




static void build_rspMsg(pj_str_t *rspMsg, int error_code, uint16_t messtype, char *url, char *result)
{
	char message[1024] = {0};
	char *pstr = rspMsg->ptr;
	int n = 0;
	int msglen = 0;
	if (messtype == REQ_MOBILE_TO_HTTP)
	{
		*((uint16_t*)(pstr)) = htons(RSP_MOBILE_TO_HTTP);
	} else if (messtype == REQ_SERVER_TO_ROUTER)
	{
		*((uint16_t*)(pstr)) = htons(RSP_SERVER_TO_ROUTER);
	}
	msglen +=2;
	pstr += 2;
	*((uint16_t*)(pstr)) = htons(WULIAN_PROTOL_VERSION);
	pstr += 2;
	msglen +=2;

	n = stringEncode(pstr, url);
	pstr += n;
	msglen +=n;
	
	*((uint32_t*)(pstr)) = htonl(error_code);
	pstr += 4;
	msglen +=4;
	
	n = stringEncode(pstr, result);
	pstr += n;
	msglen +=n;
	rspMsg->slen = msglen;
}

static void send_im(pj_str_t *rspMsg, char *url, int error_code)
{
	char *uri_local = NULL;
	char uri_buf[128] = "";
	pjsua_buddy_info binfo;
	pj_str_t tmp_info;
	pjsua_buddy_id ids[64];
	unsigned count = PJ_ARRAY_SIZE(ids);
	pjsua_enum_buddies(ids, &count);
	if (count == 0)
	{
		PJ_LOG(2, (THIS_FILE,"No buddy found\n"));
		return;
	}
	else
	{
		tmp_info.ptr = uri_buf;
		pjsua_buddy_get_info(0, &binfo);
		pj_strncpy_with_null(&tmp_info, &binfo.uri, sizeof(uri_buf));
		uri_local = uri_buf;
		pj_str_t tmp_uri = pj_str(uri_local);

		pjsua_im_typing(current_acc, &tmp_uri, PJ_TRUE, NULL);
		pjsua_im_send(current_acc, &tmp_uri, NULL, rspMsg, NULL, NULL);
	}
}



#define MAXHEADLEN 65536
size_t curlCallback(void *ptr, size_t size, size_t nmemb, void *userp)
{
    strcat( userp, ptr);
    return size * nmemb;     
}


int httpReqToLocal(char *result, char *url, char *params, char *method)
{
	CURL *curl;
	CURLcode res;
	long httpCode = 0;
	char errorBuffer[CURL_ERROR_SIZE + 1];
	char tmp[1024] = {0};
	char base[40] = "http://localhost/cgi-bin/luci/";
	char *p = NULL;
	int pos = 0;
	curl = curl_easy_init();
	if(curl) {
//		curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/cgi-bin/luci/api/wlnetwork/getWanCfg");
		/* example.com is redirected, so we tell libcurl to follow redirection */
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 2000);
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, result);
		
		 if (strcmp(method, "GET") == 0 || strcmp(method, "get") == 0) {
		 	if (params != NULL) {
		 		sprintf(tmp, "%s%s?%s", base, url, params);
		 	} else {
		 		sprintf(tmp, "%s%s", base, url);
		 	}
		    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
		    PJ_LOG(4,(THIS_FILE,"-------------MESSAGE from %s-----------------------", tmp));
		    curl_easy_setopt(curl, CURLOPT_URL, tmp);
		  } else if (strcmp(method, "POST") == 0 || strcmp(method, "post") == 0) {
		  	sprintf(tmp, "%s%s", base, url);	
		    curl_easy_setopt(curl, CURLOPT_POST, 1);
		    curl_easy_setopt(curl, CURLOPT_URL, tmp);
		    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params);
		    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(params));
		  } else {
			PJ_LOG(4,(THIS_FILE,"Unrecognized HTTP method: %s\n", method));
		    return HTTP_ERROR;
		  }
		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &httpCode);
		/* always cleanup */
		curl_easy_cleanup(curl);
		PJ_LOG(4,(THIS_FILE,"httpCode=%lu\n", httpCode));
		if (res != CURLE_OK || httpCode != 200) {
			errorBuffer[CURL_ERROR_SIZE] = '\0';
			if (res == CURLE_OPERATION_TIMEDOUT) {
				if (params != NULL) {
				PJ_LOG(4,(THIS_FILE,"HTTP Request timeout (url: %s params:%s method:%s )\n", url, params, method));
				} else {
				PJ_LOG(4,(THIS_FILE,"HTTP Request timeout (url: %s  method:%s )\n", url, method));
				}
				return HTTP_TIMEOUT;
			}
			else {
				if (params != NULL) {
					PJ_LOG(4,(THIS_FILE,"HTTP Request failure (status code:%d error:%s url:%s params:%s method: %s\n", httpCode, errorBuffer, url, params, method));
				} else {
					PJ_LOG(4,(THIS_FILE,"HTTP Request failure (status code:%d error:%s url:%s  method: %s\n", httpCode, errorBuffer, url, method));
				}
			}
			return HTTP_ERROR;
		}
		else
		{
			//TODO: 返回的结果携带了ending of chunked，使用\0替换，是否好的方法替换?
			p = strstr(result, "\r\n0\r\n");
			if (p)
			{
				pos = p - result;
				result[pos] = '\0';
			}
			PJ_LOG(4,(THIS_FILE,"HTTP Request Success (result:%s)", result));
			return NO_ERROR;
		}		
	}
	return NO_ERROR;
}

int  handle_reqMsg(char *result, char *url, char *ptmp, int pkglen)
{
	int errorcode = NO_ERROR;
	uint16_t version = 0;
	char method[10] = {0};
	char params[256] = {0};
	int n = 0;
	version = ntohs(*((uint16_t*)(ptmp)));
	ptmp += 2 ;
	pkglen -= 2;
	if (version != WULIAN_PROTOL_VERSION )
	{
		strcpy(result, "error version type");
		errorcode = UNKNOWN_PROTOCOL_VERSION;
		PJ_LOG(3,(THIS_FILE,"Error message type version: %d ", version));
		return errorcode;
	}
	
	n = stringDecode(ptmp, url, pkglen);
	ptmp += n;
	pkglen -= n;

	n = stringDecode(ptmp, params, pkglen);
	ptmp += n;
	pkglen -= n;

	n = stringDecode(ptmp, method, pkglen);
	ptmp += n;
	pkglen -= n;
	PJ_LOG(3,(THIS_FILE,"MESSAGE content version=%d,  url=%s, params=%s, method=%s", version, url, params, method));
	errorcode = httpReqToLocal(result, url, params, method);
		
	return errorcode;
}


static void on_pager(pjsua_call_id call_id, const pj_str_t *from, 
		     const pj_str_t *to, const pj_str_t *contact,
		     const pj_str_t *mime_type, const pj_str_t *text)
{
    /* Note: call index may be -1 */
    PJ_UNUSED_ARG(call_id);
    PJ_UNUSED_ARG(to);
    PJ_UNUSED_ARG(contact);
    PJ_UNUSED_ARG(mime_type);
	char url[128] = {0};
	char method[10] = {0};
	char result[1024] = {0};
	uint16_t messtype = 0;
	pj_str_t rspMsg;
	char szRspMsg[1024] = {0};
	rspMsg.ptr = szRspMsg;

	int errorcode = NO_ERROR;
	int n = 0;

	int out_len;
	char *ptmp = text->ptr;
	int pkglen = text->slen;
	


	PJ_LOG(3,(THIS_FILE,"MESSAGE from %.*s to %.*s, body content len: %d ",
	  (int)from->slen, from->ptr, (int)to->slen, to->ptr,
	  (int)text->slen));
	messtype = ntohs(*((uint16_t*)(ptmp)));
	ptmp +=  2;
	pkglen -= 2;

	if (messtype == REQ_SERVER_TO_ROUTER)
	{
		PJ_LOG(3,(THIS_FILE,"Message From Server no need to handle"));
		return;
	}
	else if ((messtype != REQ_MOBILE_TO_HTTP) && (messtype != REQ_MOBILE_TO_SMART ))
	{
		strcpy(result, "error protol message type");
		errorcode = UNKNOWN_MESSAGE_TYPE_VERSION;
		PJ_LOG(3,(THIS_FILE,"Error protol message type from : %d ", messtype));
		goto error;
	}
	errorcode = handle_reqMsg(result, url, ptmp, pkglen);
	build_rspMsg(&rspMsg, errorcode, messtype, url, result);
	
error:
	send_im(&rspMsg, url, errorcode);
}


static void on_typing(pjsua_call_id call_id, const pj_str_t *from,
		      const pj_str_t *to, const pj_str_t *contact,
		      pj_bool_t is_typing)
{
    PJ_UNUSED_ARG(call_id);
    PJ_UNUSED_ARG(to);
    PJ_UNUSED_ARG(contact);

    PJ_LOG(3,(THIS_FILE, "-----------------IM indication: %.*s %s",
	      (int)from->slen, from->ptr,
	      (is_typing?"is typing..":"has stopped typing")));
}
static const pj_str_t STR_MIME_APP	   = { "application", 11 };
static const pj_str_t STR_MIME_ISCOMPOSING = { "im-iscomposing+xml", 18 };

static pj_status_t on_handle_server_msg(pjsip_rx_data *rdata, pjsua_call_id call_id, pj_str_t *pRspMsg)
{
    PJ_UNUSED_ARG(call_id);

    PJ_LOG(3,(THIS_FILE, "----on_handle_server_msg-----"));
	pjsip_msg_body *body = rdata->msg_info.msg->body;
	int errorcode = NO_ERROR;
	char url[128] = {0};

    if (body && pj_stricmp(&body->content_type.type, &STR_MIME_APP)==0 &&
	pj_stricmp(&body->content_type.subtype, &STR_MIME_ISCOMPOSING)==0)
    {
    		PJ_LOG(3,(THIS_FILE, "----STR_MIME_APP-----"));
	    return PJ_EPENDING;
    } else {
	pj_str_t mime_type;
	char buf[256];
	pjsip_media_type *m;
	pj_str_t text_body;
	uint16_t messtype = 0;

	char result[1024] = {0};
	
	/* Save text body */
	if (body) {
		text_body.ptr = (char*)rdata->msg_info.msg->body->data;
		text_body.slen = rdata->msg_info.msg->body->len;
		char *ptmp = text_body.ptr;
		int pkglen = text_body.slen;
		/* Get mime type */
		m = &rdata->msg_info.msg->body->content_type;
		mime_type.ptr = buf;
		mime_type.slen = pj_ansi_snprintf(buf, sizeof(buf),
					      "%.*s/%.*s",
					      (int)m->type.slen,
					      m->type.ptr,
					      (int)m->subtype.slen,
					      m->subtype.ptr);
		if (mime_type.slen < 1)
			mime_type.slen = 0;

		messtype = ntohs(*((uint16_t*)(ptmp)));
		ptmp +=  2;
		pkglen -= 2;
		if (messtype != REQ_SERVER_TO_ROUTER)
		{
			PJ_LOG(3,(THIS_FILE,"Message not from server no need to handle"));
			return;
		}
		PJ_LOG(3,(THIS_FILE, "----handle_reqMsg-----"));
		errorcode = handle_reqMsg(result, url, ptmp, pkglen);
		PJ_LOG(3,(THIS_FILE, "----build_rspMsg-----"));
		build_rspMsg(pRspMsg, errorcode, messtype, url, result);
		
	} else {
		text_body.ptr = mime_type.ptr = "";
		text_body.slen = mime_type.slen = 0;
		 PJ_LOG(3,(THIS_FILE, "Body is NULL"));
	}
	return PJ_SUCCESS;
    }
	
}




/* Display error and exit application */
static void error_exit(const char *title, pj_status_t status)
{
    pjsua_perror(THIS_FILE, title, status);
    pjsua_destroy();
    exit(1);
}

/*
 * main()
 *
 * argv[1] may contain URL to call.
 */
int main(int argc, char *argv[])
{
    pjsua_acc_id acc_id;
    pj_status_t status;

    /* Create pjsua first! */
    status = pjsua_create();
    if (status != PJ_SUCCESS) error_exit("Error in pjsua_create()", status);

    /* If argument is specified, it's got to be a valid SIP URL */
    if (argc > 1) {
	status = pjsua_verify_url(argv[1]);
	if (status != PJ_SUCCESS) error_exit("Invalid URL in argv", status);
    }

    /* Init pjsua */
    {
		pjsua_config cfg;
		pjsua_logging_config log_cfg;

		pjsua_config_default(&cfg);
		cfg.cb.on_pager = &on_pager;
		cfg.cb.on_typing = &on_typing;
		cfg.cb.on_handle_server_msg = &on_handle_server_msg;

		pjsua_logging_config_default(&log_cfg);
		log_cfg.console_level = 4;

		status = pjsua_init(&cfg, &log_cfg, NULL);
		if (status != PJ_SUCCESS) error_exit("Error in pjsua_init()", status);
    }

    /* Add UDP transport. */
    {
		pjsua_transport_config cfg;

		pjsua_transport_config_default(&cfg);
		cfg.port = 5060;
		status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, NULL);
		if (status != PJ_SUCCESS) error_exit("Error creating transport", status);
    }

    /* Initialization is done, now start pjsua */
    status = pjsua_start();
    if (status != PJ_SUCCESS) error_exit("Error starting pjsua", status);

    /* Register to SIP server by creating SIP account. */
    {
		pjsua_acc_config cfg;

		pjsua_acc_config_default(&cfg);
		cfg.id = pj_str("sip:" SIP_USER "@" SIP_DOMAIN);
		cfg.reg_uri = pj_str("sip:" SIP_DOMAIN);
		cfg.cred_count = 1;
		cfg.cred_info[0].realm = pj_str(SIP_DOMAIN);
		cfg.cred_info[0].scheme = pj_str("digest");
		cfg.cred_info[0].username = pj_str(SIP_USER);
		cfg.cred_info[0].data_type = PJSIP_CRED_DATA_PLAIN_PASSWD;
		cfg.cred_info[0].data = pj_str(SIP_PASSWD);

		status = pjsua_acc_add(&cfg, PJ_TRUE, &acc_id);
		if (status != PJ_SUCCESS) error_exit("Error adding account", status);
    }


    imcenter_connect_ubus();
	uloop_run();

    /* Destroy pjsua */
    pjsua_destroy();

    return 0;
}
