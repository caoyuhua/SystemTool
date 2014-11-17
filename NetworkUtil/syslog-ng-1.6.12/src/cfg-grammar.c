/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_SOURCE = 258,
     KW_DESTINATION = 259,
     KW_LOG = 260,
     KW_OPTIONS = 261,
     KW_FILTER = 262,
     KW_INTERNAL = 263,
     KW_FILE = 264,
     KW_PIPE = 265,
     KW_UNIX_STREAM = 266,
     KW_UNIX_DGRAM = 267,
     KW_UDP = 268,
     KW_TCP = 269,
     KW_USER = 270,
     KW_SPOOF_SOURCE = 271,
     KW_SO_RCVBUF = 272,
     KW_DOOR = 273,
     KW_SUN_STREAMS = 274,
     KW_PROGRAM = 275,
     KW_REMCTRL = 276,
     KW_FLAGS = 277,
     KW_CATCHALL = 278,
     KW_FALLBACK = 279,
     KW_FINAL = 280,
     KW_FSYNC = 281,
     KW_MARK_FREQ = 282,
     KW_SYNC_FREQ = 283,
     KW_STATS_FREQ = 284,
     KW_CHAIN_HOSTNAMES = 285,
     KW_KEEP_HOSTNAME = 286,
     KW_CHECK_HOSTNAME = 287,
     KW_BAD_HOSTNAME = 288,
     KW_LOG_FIFO_SIZE = 289,
     KW_LOG_MSG_SIZE = 290,
     KW_TIME_REOPEN = 291,
     KW_TIME_REAP = 292,
     KW_TIME_SLEEP = 293,
     KW_USE_TIME_RECVD = 294,
     KW_USE_DNS = 295,
     KW_USE_FQDN = 296,
     KW_GC_BUSY_THRESHOLD = 297,
     KW_GC_IDLE_THRESHOLD = 298,
     KW_CREATE_DIRS = 299,
     KW_SANITIZE_FILENAMES = 300,
     KW_DIR_OWNER = 301,
     KW_DIR_GROUP = 302,
     KW_DIR_PERM = 303,
     KW_TEMPLATE = 304,
     KW_TEMPLATE_ESCAPE = 305,
     KW_OWNER = 306,
     KW_GROUP = 307,
     KW_PERM = 308,
     KW_KEEP_ALIVE = 309,
     KW_TCP_KEEP_ALIVE = 310,
     KW_MAX_CONNECTIONS = 311,
     KW_LOCALIP = 312,
     KW_IP = 313,
     KW_LOCALPORT = 314,
     KW_PORT = 315,
     KW_DESTPORT = 316,
     KW_COMPRESS = 317,
     KW_MAC = 318,
     KW_AUTH = 319,
     KW_ENCRYPT = 320,
     KW_DNS_CACHE = 321,
     KW_DNS_CACHE_SIZE = 322,
     KW_DNS_CACHE_EXPIRE = 323,
     KW_DNS_CACHE_EXPIRE_FAILED = 324,
     KW_REMOVE_IF_OLDER = 325,
     KW_LOG_PREFIX = 326,
     KW_PAD_SIZE = 327,
     KW_FACILITY = 328,
     KW_LEVEL = 329,
     KW_NETMASK = 330,
     KW_HOST = 331,
     KW_MATCH = 332,
     KW_YES = 333,
     KW_NO = 334,
     KW_REQUIRED = 335,
     KW_ALLOW = 336,
     KW_DENY = 337,
     DOTDOT = 338,
     IDENTIFIER = 339,
     NUMBER = 340,
     STRING = 341,
     KW_OR = 342,
     KW_AND = 343,
     KW_NOT = 344
   };
#endif
/* Tokens.  */
#define KW_SOURCE 258
#define KW_DESTINATION 259
#define KW_LOG 260
#define KW_OPTIONS 261
#define KW_FILTER 262
#define KW_INTERNAL 263
#define KW_FILE 264
#define KW_PIPE 265
#define KW_UNIX_STREAM 266
#define KW_UNIX_DGRAM 267
#define KW_UDP 268
#define KW_TCP 269
#define KW_USER 270
#define KW_SPOOF_SOURCE 271
#define KW_SO_RCVBUF 272
#define KW_DOOR 273
#define KW_SUN_STREAMS 274
#define KW_PROGRAM 275
#define KW_REMCTRL 276
#define KW_FLAGS 277
#define KW_CATCHALL 278
#define KW_FALLBACK 279
#define KW_FINAL 280
#define KW_FSYNC 281
#define KW_MARK_FREQ 282
#define KW_SYNC_FREQ 283
#define KW_STATS_FREQ 284
#define KW_CHAIN_HOSTNAMES 285
#define KW_KEEP_HOSTNAME 286
#define KW_CHECK_HOSTNAME 287
#define KW_BAD_HOSTNAME 288
#define KW_LOG_FIFO_SIZE 289
#define KW_LOG_MSG_SIZE 290
#define KW_TIME_REOPEN 291
#define KW_TIME_REAP 292
#define KW_TIME_SLEEP 293
#define KW_USE_TIME_RECVD 294
#define KW_USE_DNS 295
#define KW_USE_FQDN 296
#define KW_GC_BUSY_THRESHOLD 297
#define KW_GC_IDLE_THRESHOLD 298
#define KW_CREATE_DIRS 299
#define KW_SANITIZE_FILENAMES 300
#define KW_DIR_OWNER 301
#define KW_DIR_GROUP 302
#define KW_DIR_PERM 303
#define KW_TEMPLATE 304
#define KW_TEMPLATE_ESCAPE 305
#define KW_OWNER 306
#define KW_GROUP 307
#define KW_PERM 308
#define KW_KEEP_ALIVE 309
#define KW_TCP_KEEP_ALIVE 310
#define KW_MAX_CONNECTIONS 311
#define KW_LOCALIP 312
#define KW_IP 313
#define KW_LOCALPORT 314
#define KW_PORT 315
#define KW_DESTPORT 316
#define KW_COMPRESS 317
#define KW_MAC 318
#define KW_AUTH 319
#define KW_ENCRYPT 320
#define KW_DNS_CACHE 321
#define KW_DNS_CACHE_SIZE 322
#define KW_DNS_CACHE_EXPIRE 323
#define KW_DNS_CACHE_EXPIRE_FAILED 324
#define KW_REMOVE_IF_OLDER 325
#define KW_LOG_PREFIX 326
#define KW_PAD_SIZE 327
#define KW_FACILITY 328
#define KW_LEVEL 329
#define KW_NETMASK 330
#define KW_HOST 331
#define KW_MATCH 332
#define KW_YES 333
#define KW_NO 334
#define KW_REQUIRED 335
#define KW_ALLOW 336
#define KW_DENY 337
#define DOTDOT 338
#define IDENTIFIER 339
#define NUMBER 340
#define STRING 341
#define KW_OR 342
#define KW_AND 343
#define KW_NOT 344




/* Copy the first part of user declarations.  */
#line 26 "cfg-grammar.y"


#include "cfgfile.h"
#include "filters.h"
#include "syslog-names.h"
#include "format.h"
#include "afinter.h"
#include "affile.h"
#include "afsocket.h"
#include "afuser.h"
#include "afstreams.h"
#include "afprogram.h"
#include "afremctrl.h"

#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

void yyerror(char *msg);
int yylex();

static struct log_source_driver *last_source_driver;
static struct log_dest_driver *last_dest_driver;
UINT8 *last_prefix = NULL;
UINT32 last_pad_size;

UINT8 *
get_last_log_prefix(void)
{
	UINT8 *res = last_prefix;
	last_prefix = NULL;
	return res;
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 62 "cfg-grammar.y"
typedef union YYSTYPE {
	UINT32 num;
	char *cptr;
	void *ptr;
	struct filter_expr_node *node;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 306 "cfg-grammar.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 318 "cfg-grammar.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   570

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  93
/* YYNRULES -- Number of rules. */
#define YYNRULES  240
/* YYNRULES -- Number of states. */
#define YYNSTATES  636

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   344

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      93,    94,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    90,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,     2,    92,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     9,    10,    13,    16,    19,    22,
      25,    30,    35,    40,    44,    48,    49,    51,    53,    55,
      57,    61,    67,    73,    76,    77,    82,    87,    92,    97,
     102,   107,   108,   112,   113,   117,   120,   121,   126,   131,
     136,   138,   139,   142,   145,   146,   148,   153,   158,   163,
     168,   173,   178,   183,   184,   187,   190,   191,   193,   198,
     203,   208,   213,   218,   223,   225,   230,   235,   240,   241,
     245,   248,   249,   254,   258,   259,   261,   263,   265,   267,
     269,   271,   276,   281,   282,   286,   289,   290,   292,   297,
     302,   307,   312,   317,   322,   327,   332,   337,   342,   347,
     352,   357,   362,   367,   368,   372,   375,   376,   381,   386,
     391,   396,   401,   406,   411,   416,   421,   426,   431,   434,
     435,   436,   440,   441,   445,   446,   450,   453,   454,   456,
     461,   466,   471,   476,   481,   486,   488,   493,   498,   503,
     508,   509,   513,   516,   517,   519,   524,   529,   534,   539,
     544,   549,   554,   559,   564,   565,   569,   574,   579,   582,
     583,   588,   589,   593,   598,   603,   606,   607,   611,   615,
     616,   621,   626,   631,   637,   638,   641,   642,   644,   646,
     648,   652,   653,   658,   663,   668,   673,   678,   683,   688,
     693,   698,   703,   708,   713,   718,   723,   728,   733,   738,
     743,   748,   753,   758,   763,   768,   773,   778,   783,   788,
     793,   798,   804,   806,   809,   813,   817,   821,   826,   831,
     836,   841,   846,   851,   856,   861,   864,   866,   868,   871,
     873,   877,   879,   881,   883,   885,   887,   889,   891,   893,
     895
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
      96,     0,    -1,    97,    -1,    98,    90,    97,    -1,    -1,
       3,    99,    -1,     4,   100,    -1,     5,   101,    -1,     7,
     178,    -1,     6,   102,    -1,   187,    91,   103,    92,    -1,
     187,    91,   131,    92,    -1,    91,   171,   173,    92,    -1,
      91,   176,    92,    -1,   104,    90,   103,    -1,    -1,   105,
      -1,   106,    -1,   109,    -1,   126,    -1,     8,    93,    94,
      -1,     9,    93,   187,   107,    94,    -1,    10,    93,   187,
     107,    94,    -1,   108,   107,    -1,    -1,    71,    93,   187,
      94,    -1,    72,    93,    85,    94,    -1,    12,    93,   110,
      94,    -1,    11,    93,   112,    94,    -1,    13,    93,   116,
      94,    -1,    14,    93,   121,    94,    -1,    -1,   187,   111,
     114,    -1,    -1,   187,   113,   114,    -1,   115,   114,    -1,
      -1,    51,    93,   187,    94,    -1,    52,    93,   187,    94,
      -1,    53,    93,    85,    94,    -1,   125,    -1,    -1,   117,
     118,    -1,   119,   118,    -1,    -1,   120,    -1,    59,    93,
     187,    94,    -1,    60,    93,   187,    94,    -1,    17,    93,
      85,    94,    -1,    57,    93,   187,    94,    -1,    59,    93,
      85,    94,    -1,    60,    93,    85,    94,    -1,    58,    93,
     187,    94,    -1,    -1,   122,   123,    -1,   124,   123,    -1,
      -1,   120,    -1,    55,    93,   185,    94,    -1,    59,    93,
     187,    94,    -1,    60,    93,   187,    94,    -1,    64,    93,
     186,    94,    -1,    63,    93,   186,    94,    -1,    65,    93,
     186,    94,    -1,   125,    -1,    54,    93,   185,    94,    -1,
      56,    93,    85,    94,    -1,    19,    93,   127,    94,    -1,
      -1,   187,   128,   129,    -1,   130,   129,    -1,    -1,    18,
      93,   187,    94,    -1,   132,    90,   131,    -1,    -1,   134,
      -1,   139,    -1,   144,    -1,   160,    -1,   165,    -1,   170,
      -1,    34,    93,    85,    94,    -1,     9,    93,   135,    94,
      -1,    -1,   187,   136,   137,    -1,   138,   137,    -1,    -1,
     133,    -1,    28,    93,    85,    94,    -1,    62,    93,   185,
      94,    -1,    65,    93,   185,    94,    -1,    51,    93,   187,
      94,    -1,    52,    93,   187,    94,    -1,    53,    93,    85,
      94,    -1,    46,    93,   187,    94,    -1,    47,    93,   187,
      94,    -1,    48,    93,    85,    94,    -1,    44,    93,   185,
      94,    -1,    70,    93,    85,    94,    -1,    49,    93,   187,
      94,    -1,    50,    93,   185,    94,    -1,    26,    93,   185,
      94,    -1,    10,    93,   140,    94,    -1,    -1,   187,   141,
     142,    -1,   143,   142,    -1,    -1,    51,    93,   187,    94,
      -1,    52,    93,   187,    94,    -1,    53,    93,    85,    94,
      -1,    49,    93,   187,    94,    -1,    50,    93,   185,    94,
      -1,    12,    93,   147,    94,    -1,    11,    93,   149,    94,
      -1,    13,    93,   151,    94,    -1,    14,    93,   156,    94,
      -1,    49,    93,   187,    94,    -1,    50,    93,   185,    94,
      -1,   146,   145,    -1,    -1,    -1,   187,   148,   146,    -1,
      -1,   187,   150,   146,    -1,    -1,   187,   152,   153,    -1,
     153,   155,    -1,    -1,   133,    -1,    57,    93,   187,    94,
      -1,    59,    93,    85,    94,    -1,    60,    93,    85,    94,
      -1,    61,    93,    85,    94,    -1,    49,    93,   187,    94,
      -1,    50,    93,   185,    94,    -1,   154,    -1,    59,    93,
     187,    94,    -1,    60,    93,   187,    94,    -1,    61,    93,
     187,    94,    -1,    16,    93,   185,    94,    -1,    -1,   187,
     157,   158,    -1,   158,   159,    -1,    -1,   154,    -1,    55,
      93,   185,    94,    -1,    59,    93,   187,    94,    -1,    60,
      93,   187,    94,    -1,    61,    93,   187,    94,    -1,    63,
      93,   185,    94,    -1,    64,    93,   185,    94,    -1,    65,
      93,   185,    94,    -1,    28,    93,    85,    94,    -1,    15,
      93,   161,    94,    -1,    -1,   187,   162,   164,    -1,    49,
      93,   187,    94,    -1,    50,    93,   185,    94,    -1,   164,
     163,    -1,    -1,    20,    93,   166,    94,    -1,    -1,   187,
     167,   169,    -1,    49,    93,   187,    94,    -1,    50,    93,
     185,    94,    -1,   169,   168,    -1,    -1,    21,    93,    94,
      -1,   172,    90,   171,    -1,    -1,     3,    93,   187,    94,
      -1,     7,    93,   187,    94,    -1,     4,    93,   187,    94,
      -1,    22,    93,   174,    94,    90,    -1,    -1,   175,   174,
      -1,    -1,    23,    -1,    24,    -1,    25,    -1,   177,    90,
     176,    -1,    -1,    27,    93,    85,    94,    -1,    28,    93,
      85,    94,    -1,    29,    93,    85,    94,    -1,    30,    93,
     185,    94,    -1,    31,    93,   185,    94,    -1,    32,    93,
     185,    94,    -1,    33,    93,    86,    94,    -1,    39,    93,
     185,    94,    -1,    41,    93,   185,    94,    -1,    40,    93,
     185,    94,    -1,    36,    93,    85,    94,    -1,    38,    93,
      85,    94,    -1,    37,    93,    85,    94,    -1,    34,    93,
      85,    94,    -1,    42,    93,    85,    94,    -1,    43,    93,
      85,    94,    -1,    44,    93,   185,    94,    -1,    45,    93,
     185,    94,    -1,    51,    93,   187,    94,    -1,    52,    93,
     187,    94,    -1,    53,    93,    85,    94,    -1,    46,    93,
     187,    94,    -1,    47,    93,   187,    94,    -1,    48,    93,
      85,    94,    -1,    66,    93,   185,    94,    -1,    67,    93,
      85,    94,    -1,    68,    93,    85,    94,    -1,    69,    93,
      85,    94,    -1,    35,    93,    85,    94,    -1,   187,    91,
     179,    90,    92,    -1,   180,    -1,    89,   179,    -1,   179,
      87,   179,    -1,   179,    88,   179,    -1,    93,   179,    94,
      -1,    73,    93,   181,    94,    -1,    73,    93,    85,    94,
      -1,    74,    93,   183,    94,    -1,    20,    93,   187,    94,
      -1,    75,    93,   187,    94,    -1,    76,    93,   187,    94,
      -1,    77,    93,   187,    94,    -1,     7,    93,   187,    94,
      -1,   182,   181,    -1,   182,    -1,    84,    -1,   184,   183,
      -1,   184,    -1,    84,    83,    84,    -1,    84,    -1,    78,
      -1,    79,    -1,    85,    -1,    80,    -1,    81,    -1,    82,
      -1,    84,    -1,    86,    -1,    85,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   171,   171,   175,   176,   180,   181,   182,   183,   184,
     188,   192,   196,   200,   204,   205,   209,   210,   211,   212,
     216,   220,   225,   233,   234,   238,   239,   243,   244,   245,
     246,   251,   250,   262,   261,   273,   274,   278,   279,   280,
     281,   286,   286,   295,   296,   300,   301,   302,   303,   307,
     308,   309,   310,   315,   315,   324,   325,   329,   330,   331,
     332,   333,   334,   335,   336,   340,   341,   345,   350,   349,
     358,   359,   363,   367,   368,   372,   373,   374,   375,   376,
     377,   381,   385,   390,   389,   399,   400,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   422,   427,   426,   436,   437,   441,   442,   443,
     444,   445,   450,   451,   452,   453,   458,   459,   463,   464,
     468,   468,   477,   477,   487,   486,   497,   498,   502,   503,
     504,   505,   506,   507,   508,   512,   513,   514,   515,   516,
     521,   520,   531,   532,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   548,   552,   552,   557,   558,   562,   563,
     567,   571,   571,   576,   577,   581,   582,   586,   590,   591,
     595,   596,   597,   601,   602,   607,   608,   612,   613,   614,
     618,   619,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     652,   656,   660,   661,   662,   663,   664,   668,   669,   670,
     671,   672,   673,   674,   675,   679,   680,   684,   699,   700,
     704,   724,   739,   740,   741,   745,   746,   747,   751,   752,
     753
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_SOURCE", "KW_DESTINATION", "KW_LOG",
  "KW_OPTIONS", "KW_FILTER", "KW_INTERNAL", "KW_FILE", "KW_PIPE",
  "KW_UNIX_STREAM", "KW_UNIX_DGRAM", "KW_UDP", "KW_TCP", "KW_USER",
  "KW_SPOOF_SOURCE", "KW_SO_RCVBUF", "KW_DOOR", "KW_SUN_STREAMS",
  "KW_PROGRAM", "KW_REMCTRL", "KW_FLAGS", "KW_CATCHALL", "KW_FALLBACK",
  "KW_FINAL", "KW_FSYNC", "KW_MARK_FREQ", "KW_SYNC_FREQ", "KW_STATS_FREQ",
  "KW_CHAIN_HOSTNAMES", "KW_KEEP_HOSTNAME", "KW_CHECK_HOSTNAME",
  "KW_BAD_HOSTNAME", "KW_LOG_FIFO_SIZE", "KW_LOG_MSG_SIZE",
  "KW_TIME_REOPEN", "KW_TIME_REAP", "KW_TIME_SLEEP", "KW_USE_TIME_RECVD",
  "KW_USE_DNS", "KW_USE_FQDN", "KW_GC_BUSY_THRESHOLD",
  "KW_GC_IDLE_THRESHOLD", "KW_CREATE_DIRS", "KW_SANITIZE_FILENAMES",
  "KW_DIR_OWNER", "KW_DIR_GROUP", "KW_DIR_PERM", "KW_TEMPLATE",
  "KW_TEMPLATE_ESCAPE", "KW_OWNER", "KW_GROUP", "KW_PERM", "KW_KEEP_ALIVE",
  "KW_TCP_KEEP_ALIVE", "KW_MAX_CONNECTIONS", "KW_LOCALIP", "KW_IP",
  "KW_LOCALPORT", "KW_PORT", "KW_DESTPORT", "KW_COMPRESS", "KW_MAC",
  "KW_AUTH", "KW_ENCRYPT", "KW_DNS_CACHE", "KW_DNS_CACHE_SIZE",
  "KW_DNS_CACHE_EXPIRE", "KW_DNS_CACHE_EXPIRE_FAILED",
  "KW_REMOVE_IF_OLDER", "KW_LOG_PREFIX", "KW_PAD_SIZE", "KW_FACILITY",
  "KW_LEVEL", "KW_NETMASK", "KW_HOST", "KW_MATCH", "KW_YES", "KW_NO",
  "KW_REQUIRED", "KW_ALLOW", "KW_DENY", "DOTDOT", "IDENTIFIER", "NUMBER",
  "STRING", "KW_OR", "KW_AND", "KW_NOT", "';'", "'{'", "'}'", "'('", "')'",
  "$accept", "start", "stmts", "stmt", "source_stmt", "dest_stmt",
  "log_stmt", "options_stmt", "source_items", "source_item",
  "source_afinter", "source_affile", "source_affile_options",
  "source_affile_option", "source_afsocket", "source_afunix_dgram_params",
  "@1", "source_afunix_stream_params", "@2", "source_afunix_options",
  "source_afunix_option", "source_afinet_udp_params", "@3",
  "source_afinet_udp_options", "source_afinet_udp_option",
  "source_afinet_option", "source_afinet_tcp_params", "@4",
  "source_afinet_tcp_options", "source_afinet_tcp_option",
  "source_afsocket_stream_params", "source_afstreams",
  "source_afstreams_params", "@5", "source_afstreams_options",
  "source_afstreams_option", "dest_items", "dest_item", "dest_item_option",
  "dest_affile", "dest_affile_params", "@6", "dest_affile_options",
  "dest_affile_option", "dest_afpipe", "dest_afpipe_params", "@7",
  "dest_afpipe_options", "dest_afpipe_option", "dest_afsocket",
  "dest_afunix_option", "dest_afunix_options", "dest_afunix_dgram_params",
  "@8", "dest_afunix_stream_params", "@9", "dest_afinet_udp_params", "@10",
  "dest_afinet_udp_options", "dest_afinet_option",
  "dest_afinet_udp_option", "dest_afinet_tcp_params", "@11",
  "dest_afinet_tcp_options", "dest_afinet_tcp_option", "dest_afuser",
  "dest_afuser_params", "@12", "dest_afuser_option", "dest_afuser_options",
  "dest_afprogram", "dest_afprogram_params", "@13",
  "dest_afprogram_option", "dest_afprogram_options", "dest_afremctrl",
  "log_items", "log_item", "log_flags", "log_flags_items",
  "log_flags_item", "options_items", "options_item", "filter_stmt",
  "filter_expr", "filter_simple_expr", "filter_fac_list", "filter_fac",
  "filter_level_list", "filter_level", "yesno", "tripleoption", "string", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
      59,   123,   125,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    95,    96,    97,    97,    98,    98,    98,    98,    98,
      99,   100,   101,   102,   103,   103,   104,   104,   104,   104,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   109,
     109,   111,   110,   113,   112,   114,   114,   115,   115,   115,
     115,   117,   116,   118,   118,   119,   119,   119,   119,   120,
     120,   120,   120,   122,   121,   123,   123,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125,   126,   128,   127,
     129,   129,   130,   131,   131,   132,   132,   132,   132,   132,
     132,   133,   134,   136,   135,   137,   137,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   139,   141,   140,   142,   142,   143,   143,   143,
     143,   143,   144,   144,   144,   144,   145,   145,   146,   146,
     148,   147,   150,   149,   152,   151,   153,   153,   154,   154,
     154,   154,   154,   154,   154,   155,   155,   155,   155,   155,
     157,   156,   158,   158,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   160,   162,   161,   163,   163,   164,   164,
     165,   167,   166,   168,   168,   169,   169,   170,   171,   171,
     172,   172,   172,   173,   173,   174,   174,   175,   175,   175,
     176,   176,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   178,   179,   179,   179,   179,   179,   180,   180,   180,
     180,   180,   180,   180,   180,   181,   181,   182,   183,   183,
     184,   184,   185,   185,   185,   186,   186,   186,   187,   187,
     187
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     3,     0,     2,     2,     2,     2,     2,
       4,     4,     4,     3,     3,     0,     1,     1,     1,     1,
       3,     5,     5,     2,     0,     4,     4,     4,     4,     4,
       4,     0,     3,     0,     3,     2,     0,     4,     4,     4,
       1,     0,     2,     2,     0,     1,     4,     4,     4,     4,
       4,     4,     4,     0,     2,     2,     0,     1,     4,     4,
       4,     4,     4,     4,     1,     4,     4,     4,     0,     3,
       2,     0,     4,     3,     0,     1,     1,     1,     1,     1,
       1,     4,     4,     0,     3,     2,     0,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     3,     2,     0,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     2,     0,
       0,     3,     0,     3,     0,     3,     2,     0,     1,     4,
       4,     4,     4,     4,     4,     1,     4,     4,     4,     4,
       0,     3,     2,     0,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     3,     4,     4,     2,     0,
       4,     0,     3,     4,     4,     2,     0,     3,     3,     0,
       4,     4,     4,     5,     0,     2,     0,     1,     1,     1,
       3,     0,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     1,     2,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     1,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,     2,     0,   238,
     240,   239,     5,     0,     6,     0,   169,     7,   181,     9,
       8,     0,     1,     4,    15,    74,     0,     0,     0,   174,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,     0,     0,     0,     0,     0,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   212,     0,     0,     0,     0,     0,    41,    53,
       0,    10,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    74,     0,     0,     0,   176,    12,   168,
       0,     0,     0,   232,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
     213,     0,     0,     0,     0,    20,    24,    24,     0,    33,
       0,    31,     0,    44,     0,    56,     0,    68,    14,     0,
      83,     0,   103,     0,   122,     0,   120,     0,   124,     0,
     140,     0,   154,     0,   161,   167,    73,   170,   172,   171,
     177,   178,   179,     0,   176,   182,   183,   184,   185,   186,
     187,   188,   195,   210,   192,   194,   193,   189,   191,   190,
     196,   197,   198,   199,   203,   204,   205,   200,   201,   202,
     206,   207,   208,   209,     0,     0,   227,     0,     0,   226,
     231,     0,   229,     0,     0,     0,   216,   214,   215,   211,
       0,     0,     0,    24,     0,    28,    36,    27,    36,    29,
       0,     0,     0,     0,     0,    42,    44,    45,    30,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    54,    56,
      64,    67,    71,    82,    86,   102,   106,   113,   119,   112,
     119,   114,   127,   115,   143,   153,   159,   160,   166,     0,
     175,   224,   220,   218,   217,   225,     0,   219,   228,   221,
     222,   223,     0,     0,    21,    23,    22,     0,     0,     0,
      34,    36,    40,    32,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      69,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    84,    86,
       0,     0,     0,     0,     0,   104,   106,   123,   121,   125,
     141,   155,   162,   173,   230,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,   236,   237,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,   105,     0,     0,   118,     0,     0,     0,     0,
       0,     0,     0,   128,   135,   126,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   142,     0,     0,   158,     0,
       0,   165,    25,    26,     0,     0,     0,    48,    49,    52,
      50,    46,    51,    47,    65,    58,    66,    59,    60,    62,
      61,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,    72,   101,    88,
      81,    97,    94,    95,    96,    99,   100,    91,    92,    93,
      89,    90,    98,   110,   111,   107,   108,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,   117,   139,   133,   134,   129,   130,   136,
     131,   137,   132,   138,   152,   145,   146,   147,   148,   149,
     150,   151,   156,   157,   163,   164
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     6,     7,     8,    12,    14,    17,    19,    72,    73,
      74,    75,   302,   303,    76,   220,   308,   218,   306,   370,
     371,   222,   223,   315,   316,   317,   224,   225,   328,   329,
     372,    77,   226,   332,   390,   391,    87,    88,   407,    89,
     229,   334,   408,   409,    90,   231,   336,   415,   416,    91,
     475,   417,   235,   340,   233,   338,   237,   342,   419,   484,
     485,   239,   344,   420,   495,    92,   241,   346,   498,   421,
      93,   243,   348,   501,   422,    94,    29,    30,    99,   253,
     254,    60,    61,    20,   141,   142,   288,   289,   291,   292,
     176,   446,    13
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -304
static const short int yypact[] =
{
      62,    -8,    -8,   -83,   -80,    -8,    20,  -304,   -60,  -304,
    -304,  -304,  -304,   -53,  -304,   -49,    15,  -304,   181,  -304,
    -304,   -34,  -304,    62,   101,    14,   -12,     8,    35,    70,
      17,    37,    43,    53,    56,    57,    67,    72,    73,    85,
     100,   104,   107,   111,   137,   138,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   165,   166,
      40,   109,    -3,  -304,   170,   171,   172,   173,   174,   175,
     176,   177,    55,   182,  -304,  -304,  -304,  -304,   178,   180,
     183,   184,   185,   186,   187,   188,   189,   191,   194,  -304,
    -304,  -304,  -304,  -304,  -304,    -8,    -8,    -8,   192,   195,
      15,   190,   201,   203,   -69,   -69,   -69,   108,   204,   205,
     206,   207,   208,   -69,   -69,   -69,   209,   210,   -69,   -69,
      -8,    -8,   211,    -8,    -8,   212,   -69,   213,   214,   215,
    -304,   181,   216,   217,   218,   219,   220,   221,   222,    -3,
      -3,   -37,  -304,   223,    -8,    -8,    -8,    -8,  -304,  -304,
      -8,  -304,   101,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,   224,  -304,    14,   225,   226,   227,   102,  -304,  -304,
     228,   229,   230,  -304,  -304,  -304,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,  -304,    -8,    -8,   -71,   112,    -8,    -8,    -8,
    -304,   -51,    -3,    -3,   259,  -304,   -25,   -25,   258,  -304,
     260,  -304,   261,     4,   262,   197,   263,  -304,  -304,   264,
    -304,   265,  -304,   267,  -304,   268,  -304,   269,  -304,   270,
    -304,   271,  -304,   272,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,   273,   102,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,   274,   275,  -304,   276,   277,   288,
     295,   285,   112,   289,   290,   292,  -304,   299,  -304,  -304,
     298,   300,   294,   -25,   301,  -304,    31,  -304,    31,  -304,
     303,   304,   305,   306,   307,  -304,     4,  -304,  -304,   308,
     309,   310,   311,   312,   313,   314,   315,  -304,  -304,   197,
    -304,  -304,   283,  -304,   133,  -304,    47,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,   302,
    -304,  -304,  -304,  -304,  -304,  -304,   325,  -304,  -304,  -304,
    -304,  -304,    -8,   326,  -304,  -304,  -304,   317,   319,   320,
    -304,    31,  -304,  -304,   329,    -8,    -8,    78,    84,  -304,
     -69,   -69,   330,    78,    84,    91,    91,    91,  -304,   323,
    -304,   283,   324,   327,   328,   331,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,  -304,  -304,   133,
     345,   346,   347,   348,   349,  -304,    47,     5,     5,    -1,
      74,    39,    54,  -304,  -304,   350,   351,    -8,    -8,   333,
    -304,   352,   354,   355,   356,   357,   358,   361,   363,   366,
     367,   368,   369,  -304,  -304,  -304,   370,   372,   375,    -8,
    -304,   -69,   387,   389,   -69,    -8,    -8,   390,    -8,   -69,
      -8,    -8,   391,   -69,   -69,   392,  -304,    -8,   -69,    -8,
      -8,   393,  -304,   388,   395,  -304,   397,   398,   399,   400,
     401,   402,   403,  -304,  -304,  -304,   404,   405,   406,   407,
     408,   409,   410,   411,  -304,  -304,   412,   413,  -304,   414,
     415,  -304,  -304,  -304,   386,   416,   417,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,    -8,   -69,   -69,    -8,   -69,    -8,    90,
     103,   106,   448,   -69,    90,   103,   106,   -69,   -69,   -69,
      -8,   -69,    -8,   -69,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,   440,   441,
     442,   443,   444,   445,   446,   449,   451,   456,   457,   461,
     462,   463,   465,   467,   468,   469,   470,   471,   472,   473,
     474,   475,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -304,  -304,   279,  -304,  -304,  -304,  -304,  -304,   122,  -304,
    -304,  -304,  -212,  -304,  -304,  -304,  -304,  -304,  -304,  -296,
    -304,  -304,  -304,   -13,  -304,  -224,  -304,  -304,   -24,  -304,
    -223,  -304,  -304,  -304,   -87,  -304,   280,  -304,  -303,  -304,
    -304,  -304,  -101,  -304,  -304,  -304,  -304,  -100,  -304,  -304,
    -304,    13,  -304,  -304,  -304,  -304,  -304,  -304,  -304,     2,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,   382,  -304,  -304,   169,
    -304,   378,  -304,  -304,  -133,  -304,   130,  -304,   278,  -304,
     -74,  -246,    -2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
      15,   327,   330,    21,   132,   304,   210,   211,    16,   173,
     174,    18,   373,   286,   287,   476,   175,   133,    26,    27,
      22,   310,    28,    78,    79,    80,    81,    82,    83,    84,
      23,   177,   178,   394,    85,    86,   212,   213,    24,   185,
     186,   187,    25,   296,   190,   191,   300,   301,   477,   478,
     212,   213,   198,   214,   473,   474,   479,    62,   480,   481,
     482,   311,   312,   313,   314,     1,     2,     3,     4,     5,
     134,   135,   136,   137,   138,   430,     9,    10,    11,   297,
     298,    95,   367,   368,   369,   319,   139,   321,   496,   497,
     140,   365,    98,   164,   165,   166,   410,   411,   412,   413,
     414,    96,   486,   499,   500,   327,   330,   100,   394,    64,
      65,    66,    67,    68,    69,    70,   483,   483,   192,   193,
      71,   195,   196,   477,   478,   250,   251,   252,    97,   487,
     101,   479,   130,   488,   489,   490,   102,   491,   492,   493,
     447,   448,   216,   217,   219,   221,   103,   151,   227,   104,
     105,   230,   232,   234,   236,   238,   240,   242,   244,   392,
     106,   393,     9,   434,    11,   107,   108,   394,     9,   436,
      11,   443,   444,   445,     9,   594,    11,   395,   109,   396,
     397,   398,   399,   400,   401,   402,   403,     9,   596,    11,
       9,   598,    11,   110,   179,   404,   290,   111,   405,   131,
     112,   284,   285,   406,   113,   293,   294,   295,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
     114,   115,    53,    54,    55,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    56,    57,    58,
      59,   319,   320,   321,   311,   312,   322,   323,   128,   129,
     324,   325,   326,   143,   144,   145,   146,   147,   148,   149,
     150,   153,   152,   154,   228,   170,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   167,   171,   168,   172,   180,
     181,   182,   183,   184,   188,   189,   194,   197,   199,   200,
     201,   389,    63,   379,   450,   388,   438,   439,   466,   203,
     204,   205,   206,   207,   208,   209,   472,   215,   245,   247,
     248,   249,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   299,   305,   418,   307,   309,   318,   331,   333,   335,
     425,   337,   339,   341,   343,   345,   347,   349,   351,   352,
     353,   354,   286,   432,   433,   435,   437,   523,   356,   357,
     526,   441,   442,   359,   360,   531,   361,   213,   364,   535,
     536,   362,   423,   363,   539,   366,   374,   375,   376,   377,
     378,   380,   381,   382,   383,   384,   385,   386,   387,   424,
     427,   426,   428,   429,   431,   440,   449,   451,   506,   355,
     452,   453,   494,   350,   454,   504,   505,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   467,   468,
     469,   470,   471,   246,   502,   503,   507,   522,   508,   509,
     510,   511,   512,   527,   528,   513,   530,   514,   532,   533,
     515,   516,   517,   518,   519,   538,   520,   540,   541,   521,
     589,   590,   524,   592,   525,   529,   534,   537,   542,   601,
     564,   543,   169,   605,   606,   607,     0,   609,   544,   611,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   202,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   600,   612,   613,   614,   615,   616,   617,
     618,   588,     0,   619,   591,   620,   593,   595,   597,   599,
     621,   622,   602,   603,   604,   623,   624,   625,   608,   626,
     610,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     358
};

static const short int yycheck[] =
{
       2,   225,   225,     5,     7,   217,   139,   140,    91,    78,
      79,    91,   308,    84,    85,    16,    85,    20,     3,     4,
       0,    17,     7,     9,    10,    11,    12,    13,    14,    15,
      90,   105,   106,    34,    20,    21,    87,    88,    91,   113,
     114,   115,    91,    94,   118,   119,    71,    72,    49,    50,
      87,    88,   126,    90,    49,    50,    57,    91,    59,    60,
      61,    57,    58,    59,    60,     3,     4,     5,     6,     7,
      73,    74,    75,    76,    77,   371,    84,    85,    86,   212,
     213,    93,    51,    52,    53,    54,    89,    56,    49,    50,
      93,   303,    22,    95,    96,    97,    49,    50,    51,    52,
      53,    93,    28,    49,    50,   329,   329,    90,    34,     8,
       9,    10,    11,    12,    13,    14,   419,   420,   120,   121,
      19,   123,   124,    49,    50,    23,    24,    25,    93,    55,
      93,    57,    92,    59,    60,    61,    93,    63,    64,    65,
     386,   387,   144,   145,   146,   147,    93,    92,   150,    93,
      93,   153,   154,   155,   156,   157,   158,   159,   160,    26,
      93,    28,    84,    85,    86,    93,    93,    34,    84,    85,
      86,    80,    81,    82,    84,    85,    86,    44,    93,    46,
      47,    48,    49,    50,    51,    52,    53,    84,    85,    86,
      84,    85,    86,    93,    86,    62,    84,    93,    65,    90,
      93,   203,   204,    70,    93,   207,   208,   209,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      93,    93,    51,    52,    53,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    66,    67,    68,
      69,    54,    55,    56,    57,    58,    59,    60,    93,    93,
      63,    64,    65,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    90,    93,   152,    85,    93,    93,    93,    93,
      93,    93,    93,    92,    90,    93,    85,    92,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    18,    23,   316,   391,   329,   380,   381,   409,    93,
      93,    93,    93,    93,    93,    93,   416,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    92,    94,   340,    94,    94,    94,    94,    94,    94,
     362,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    84,   375,   376,   377,   378,   451,    83,    94,
     454,   383,   384,    94,    94,   459,    94,    88,    94,   463,
     464,    93,    90,    93,   468,    94,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    84,
      93,    85,    93,    93,    85,    85,    93,    93,    85,   289,
      93,    93,   420,   254,    93,   427,   428,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,   163,    94,    94,    94,   449,    94,    94,
      94,    94,    94,   455,   456,    94,   458,    94,   460,   461,
      94,    94,    94,    94,    94,   467,    94,   469,   470,    94,
     544,   545,    85,   547,    85,    85,    85,    85,    85,   553,
      94,    93,   100,   557,   558,   559,    -1,   561,    93,   563,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,   131,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    85,    94,    94,    94,    94,    94,    94,
      94,   543,    -1,    94,   546,    94,   548,   549,   550,   551,
      94,    94,   554,   555,   556,    94,    94,    94,   560,    94,
     562,    94,    94,    94,    94,    94,    94,    94,    94,    94,
     292
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     7,    96,    97,    98,    84,
      85,    86,    99,   187,   100,   187,    91,   101,    91,   102,
     178,   187,     0,    90,    91,    91,     3,     4,     7,   171,
     172,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    51,    52,    53,    66,    67,    68,    69,
     176,   177,    91,    97,     8,     9,    10,    11,    12,    13,
      14,    19,   103,   104,   105,   106,   109,   126,     9,    10,
      11,    12,    13,    14,    15,    20,    21,   131,   132,   134,
     139,   144,   160,   165,   170,    93,    93,    93,    22,   173,
      90,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      92,    90,     7,    20,    73,    74,    75,    76,    77,    89,
      93,   179,   180,    93,    93,    93,    93,    93,    93,    93,
      93,    92,    90,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    92,    90,   187,   187,   187,    93,    92,   171,
      85,    85,    85,    78,    79,    85,   185,   185,   185,    86,
      85,    85,    85,    85,    85,   185,   185,   185,    85,    85,
     185,   185,   187,   187,    85,   187,   187,    85,   185,    85,
      85,    85,   176,    93,    93,    93,    93,    93,    93,    93,
     179,   179,    87,    88,    90,    94,   187,   187,   112,   187,
     110,   187,   116,   117,   121,   122,   127,   187,   103,   135,
     187,   140,   187,   149,   187,   147,   187,   151,   187,   156,
     187,   161,   187,   166,   187,    94,   131,    94,    94,    94,
      23,    24,    25,   174,   175,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,   187,   187,    84,    85,   181,   182,
      84,   183,   184,   187,   187,   187,    94,   179,   179,    92,
      71,    72,   107,   108,   107,    94,   113,    94,   111,    94,
      17,    57,    58,    59,    60,   118,   119,   120,    94,    54,
      55,    56,    59,    60,    63,    64,    65,   120,   123,   124,
     125,    94,   128,    94,   136,    94,   141,    94,   150,    94,
     148,    94,   152,    94,   157,    94,   162,    94,   167,    94,
     174,    94,    94,    94,    94,   181,    83,    94,   183,    94,
      94,    94,    93,    93,    94,   107,    94,    51,    52,    53,
     114,   115,   125,   114,    93,    93,    93,    93,    93,   118,
      93,    93,    93,    93,    93,    93,    93,    93,   123,    18,
     129,   130,    26,    28,    34,    44,    46,    47,    48,    49,
      50,    51,    52,    53,    62,    65,    70,   133,   137,   138,
      49,    50,    51,    52,    53,   142,   143,   146,   146,   153,
     158,   164,   169,    90,    84,   187,    85,    93,    93,    93,
     114,    85,   187,   187,    85,   187,    85,   187,   185,   185,
      85,   187,   187,    80,    81,    82,   186,   186,   186,    93,
     129,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,   137,    93,    93,    93,
      93,    93,   142,    49,    50,   145,    16,    49,    50,    57,
      59,    60,    61,   133,   154,   155,    28,    55,    59,    60,
      61,    63,    64,    65,   154,   159,    49,    50,   163,    49,
      50,   168,    94,    94,   187,   187,    85,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,   187,   185,    85,    85,   185,   187,   187,    85,
     187,   185,   187,   187,    85,   185,   185,    85,   187,   185,
     187,   187,    85,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,   187,   185,
     185,   187,   185,   187,    85,   187,    85,   187,    85,   187,
      85,   185,   187,   187,   187,   185,   185,   185,   187,   185,
     187,   185,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 180 "cfg-grammar.y"
    { add_source_group((yyvsp[0].ptr)); }
    break;

  case 6:
#line 181 "cfg-grammar.y"
    { add_dest_group((yyvsp[0].ptr)); }
    break;

  case 7:
#line 182 "cfg-grammar.y"
    { add_log_connection((yyvsp[0].ptr)); }
    break;

  case 8:
#line 183 "cfg-grammar.y"
    { add_filter_rule((yyvsp[0].ptr)); }
    break;

  case 9:
#line 184 "cfg-grammar.y"
    {  }
    break;

  case 10:
#line 188 "cfg-grammar.y"
    { (yyval.ptr) = make_source_group((yyvsp[-3].cptr), (yyvsp[-1].ptr)); free((yyvsp[-3].cptr)); }
    break;

  case 11:
#line 192 "cfg-grammar.y"
    { (yyval.ptr) = make_dest_group((yyvsp[-3].cptr), (yyvsp[-1].ptr)); free((yyvsp[-3].cptr)); }
    break;

  case 12:
#line 196 "cfg-grammar.y"
    { (yyval.ptr) = make_log_connection((yyvsp[-2].ptr), (yyvsp[-1].num)); }
    break;

  case 13:
#line 200 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 14:
#line 204 "cfg-grammar.y"
    { append_source_driver((yyvsp[-2].ptr), (yyvsp[0].ptr)); (yyval.ptr) = (yyvsp[-2].ptr); }
    break;

  case 15:
#line 205 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 16:
#line 209 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[0].ptr); }
    break;

  case 17:
#line 210 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[0].ptr); }
    break;

  case 18:
#line 211 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[0].ptr); }
    break;

  case 19:
#line 212 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[0].ptr); }
    break;

  case 20:
#line 216 "cfg-grammar.y"
    { (yyval.ptr) = make_afinter_source(); }
    break;

  case 21:
#line 221 "cfg-grammar.y"
    { 
        	(yyval.ptr) = make_affile_source((yyvsp[-2].cptr), 0, get_last_log_prefix(), last_pad_size); 
		free((yyvsp[-2].cptr)); 
	  }
    break;

  case 22:
#line 226 "cfg-grammar.y"
    { 
		(yyval.ptr) = make_affile_source((yyvsp[-2].cptr), AFFILE_PIPE, get_last_log_prefix(), last_pad_size); 
		free((yyvsp[-2].cptr)); 
	  }
    break;

  case 25:
#line 238 "cfg-grammar.y"
    { last_prefix = (UINT8 *) (yyvsp[-1].cptr); }
    break;

  case 26:
#line 239 "cfg-grammar.y"
    { last_pad_size = (yyvsp[-1].num); }
    break;

  case 27:
#line 243 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 28:
#line 244 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 29:
#line 245 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 30:
#line 246 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 31:
#line 251 "cfg-grammar.y"
    { 
	    last_source_driver = make_afunix_source(
		&make_unix_address_c((yyvsp[0].cptr))->super, 
		AFSOCKET_DGRAM); 
	    free((yyvsp[0].cptr)); 
	  }
    break;

  case 32:
#line 257 "cfg-grammar.y"
    { (yyval.ptr) = last_source_driver; }
    break;

  case 33:
#line 262 "cfg-grammar.y"
    { 
	    last_source_driver = make_afunix_source(
		&make_unix_address_c((yyvsp[0].cptr))->super,
		AFSOCKET_STREAM | AFSOCKET_KEEP_ALIVE);
	    free((yyvsp[0].cptr));
	  }
    break;

  case 34:
#line 268 "cfg-grammar.y"
    { (yyval.ptr) = last_source_driver; }
    break;

  case 37:
#line 278 "cfg-grammar.y"
    { afunix_set_owner(last_source_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 38:
#line 279 "cfg-grammar.y"
    { afunix_set_group(last_source_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 39:
#line 280 "cfg-grammar.y"
    { afunix_set_perm(last_source_driver, (yyvsp[-1].num)); }
    break;

  case 40:
#line 281 "cfg-grammar.y"
    {}
    break;

  case 41:
#line 286 "cfg-grammar.y"
    { 
	    last_source_driver = make_afinet_source(
			&make_inet_address_c("0.0.0.0", "514")->super, 
			AFSOCKET_DGRAM);
	  }
    break;

  case 42:
#line 291 "cfg-grammar.y"
    { (yyval.ptr) = last_source_driver; }
    break;

  case 46:
#line 301 "cfg-grammar.y"
    { afinet_src_set_localport(last_source_driver, 0, (yyvsp[-1].cptr) ,"udp"); free((yyvsp[-1].cptr)); }
    break;

  case 47:
#line 302 "cfg-grammar.y"
    { afinet_src_set_localport(last_source_driver, 0, (yyvsp[-1].cptr), "udp"); free((yyvsp[-1].cptr)); }
    break;

  case 48:
#line 303 "cfg-grammar.y"
    { afinet_src_set_so_rcvbuf(last_source_driver, (yyvsp[-1].num)); }
    break;

  case 49:
#line 307 "cfg-grammar.y"
    { afinet_src_set_localip(last_source_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 50:
#line 308 "cfg-grammar.y"
    { afinet_src_set_localport(last_source_driver, (yyvsp[-1].num), NULL, NULL); }
    break;

  case 51:
#line 309 "cfg-grammar.y"
    { afinet_src_set_localport(last_source_driver, (yyvsp[-1].num), NULL, NULL); }
    break;

  case 52:
#line 310 "cfg-grammar.y"
    { afinet_src_set_localip(last_source_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 53:
#line 315 "cfg-grammar.y"
    { 
	    last_source_driver = make_afinet_source(
			&make_inet_address_c("0.0.0.0", "514")->super,
			AFSOCKET_STREAM);
	  }
    break;

  case 54:
#line 320 "cfg-grammar.y"
    { (yyval.ptr) = last_source_driver; }
    break;

  case 58:
#line 330 "cfg-grammar.y"
    { afinet_src_set_tcp_keepalive(last_source_driver, (yyvsp[-1].num)); }
    break;

  case 59:
#line 331 "cfg-grammar.y"
    { afinet_src_set_localport(last_source_driver, 0, (yyvsp[-1].cptr), "tcp"); free((yyvsp[-1].cptr)); }
    break;

  case 60:
#line 332 "cfg-grammar.y"
    { afinet_src_set_localport(last_source_driver, 0, (yyvsp[-1].cptr), "tcp"); free((yyvsp[-1].cptr)); }
    break;

  case 61:
#line 333 "cfg-grammar.y"
    { afinet_src_set_auth(last_source_driver, (yyvsp[-1].num)); }
    break;

  case 62:
#line 334 "cfg-grammar.y"
    { afinet_src_set_mac(last_source_driver, (yyvsp[-1].num)); }
    break;

  case 63:
#line 335 "cfg-grammar.y"
    { afinet_src_set_encrypt(last_source_driver, (yyvsp[-1].num)); }
    break;

  case 64:
#line 336 "cfg-grammar.y"
    {}
    break;

  case 65:
#line 340 "cfg-grammar.y"
    { afsocket_src_set_keep_alive(last_source_driver, (yyvsp[-1].num)); }
    break;

  case 66:
#line 341 "cfg-grammar.y"
    { afsocket_src_set_max_connections(last_source_driver, (yyvsp[-1].num)); }
    break;

  case 67:
#line 345 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 68:
#line 350 "cfg-grammar.y"
    { 
	    last_source_driver = make_afstreams_source((yyvsp[0].cptr)); 
	    free((yyvsp[0].cptr)); 
	  }
    break;

  case 69:
#line 354 "cfg-grammar.y"
    { (yyval.ptr) = last_source_driver; }
    break;

  case 72:
#line 363 "cfg-grammar.y"
    { afstreams_set_sundoor(last_source_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 73:
#line 367 "cfg-grammar.y"
    { append_dest_driver((yyvsp[-2].ptr), (yyvsp[0].ptr)); (yyval.ptr) = (yyvsp[-2].ptr); }
    break;

  case 74:
#line 368 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 75:
#line 372 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[0].ptr); }
    break;

  case 76:
#line 373 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[0].ptr); }
    break;

  case 77:
#line 374 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[0].ptr); }
    break;

  case 78:
#line 375 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[0].ptr); }
    break;

  case 79:
#line 376 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[0].ptr); }
    break;

  case 80:
#line 377 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[0].ptr); }
    break;

  case 81:
#line 381 "cfg-grammar.y"
    { last_dest_driver->log_fifo_size = (yyvsp[-1].num); }
    break;

  case 82:
#line 385 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 83:
#line 390 "cfg-grammar.y"
    { 
	    last_dest_driver = make_affile_dest((yyvsp[0].cptr), 0); 
	    free((yyvsp[0].cptr)); 
	  }
    break;

  case 84:
#line 395 "cfg-grammar.y"
    { (yyval.ptr) = last_dest_driver; }
    break;

  case 88:
#line 405 "cfg-grammar.y"
    { affile_set_syncfreq(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 89:
#line 406 "cfg-grammar.y"
    { affile_set_compress(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 90:
#line 407 "cfg-grammar.y"
    { affile_set_encrypt(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 91:
#line 408 "cfg-grammar.y"
    { affile_set_owner(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 92:
#line 409 "cfg-grammar.y"
    { affile_set_group(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 93:
#line 410 "cfg-grammar.y"
    { affile_set_perm(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 94:
#line 411 "cfg-grammar.y"
    { affile_set_dir_owner(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 95:
#line 412 "cfg-grammar.y"
    { affile_set_dir_group(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 96:
#line 413 "cfg-grammar.y"
    { affile_set_dir_perm(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 97:
#line 414 "cfg-grammar.y"
    { affile_set_create_dirs(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 98:
#line 415 "cfg-grammar.y"
    { affile_set_remove_if_older(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 99:
#line 416 "cfg-grammar.y"
    { affile_set_file_template(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 100:
#line 417 "cfg-grammar.y"
    { affile_set_template_escape(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 101:
#line 418 "cfg-grammar.y"
    { affile_set_fsync(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 102:
#line 422 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 103:
#line 427 "cfg-grammar.y"
    { 
	    last_dest_driver = make_affile_dest((yyvsp[0].cptr), AFFILE_NO_EXPAND | AFFILE_PIPE);
	    affile_set_syncfreq(last_dest_driver, 0);
	    free((yyvsp[0].cptr)); 
	  }
    break;

  case 104:
#line 432 "cfg-grammar.y"
    { (yyval.ptr) = last_dest_driver; }
    break;

  case 107:
#line 441 "cfg-grammar.y"
    { affile_set_owner(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 108:
#line 442 "cfg-grammar.y"
    { affile_set_group(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 109:
#line 443 "cfg-grammar.y"
    { affile_set_perm(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 110:
#line 444 "cfg-grammar.y"
    { affile_set_file_template(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 111:
#line 445 "cfg-grammar.y"
    { affile_set_template_escape(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 112:
#line 450 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 113:
#line 451 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 114:
#line 452 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 115:
#line 453 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 116:
#line 458 "cfg-grammar.y"
    { afunix_dest_set_template(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 117:
#line 459 "cfg-grammar.y"
    { afunix_dest_set_template_escape(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 120:
#line 468 "cfg-grammar.y"
    { last_dest_driver = make_afunix_dest(
							&make_unix_address_c((yyvsp[0].cptr))->super, 
							AFSOCKET_DGRAM);
							free((yyvsp[0].cptr));
						}
    break;

  case 121:
#line 473 "cfg-grammar.y"
    { (yyval.ptr) = last_dest_driver; }
    break;

  case 122:
#line 477 "cfg-grammar.y"
    { last_dest_driver = make_afunix_dest(
							&make_unix_address_c((yyvsp[0].cptr))->super, 
							AFSOCKET_STREAM);
							free((yyvsp[0].cptr));
						}
    break;

  case 123:
#line 482 "cfg-grammar.y"
    { (yyval.ptr) = last_dest_driver; }
    break;

  case 124:
#line 487 "cfg-grammar.y"
    { 
	    last_dest_driver = make_afinet_dest(
			&make_inet_address_c((yyvsp[0].cptr), "514")->super, 
			AFSOCKET_DGRAM);
	    free((yyvsp[0].cptr));
	  }
    break;

  case 125:
#line 493 "cfg-grammar.y"
    { (yyval.ptr) = last_dest_driver; }
    break;

  case 129:
#line 503 "cfg-grammar.y"
    { afinet_dest_set_localip(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 130:
#line 504 "cfg-grammar.y"
    { afinet_dest_set_localport(last_dest_driver, (yyvsp[-1].num), NULL, NULL); }
    break;

  case 131:
#line 505 "cfg-grammar.y"
    { afinet_dest_set_destport(last_dest_driver, (yyvsp[-1].num), NULL, NULL); }
    break;

  case 132:
#line 506 "cfg-grammar.y"
    { afinet_dest_set_destport(last_dest_driver, (yyvsp[-1].num), NULL, NULL); }
    break;

  case 133:
#line 507 "cfg-grammar.y"
    { afinet_dest_set_template(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 134:
#line 508 "cfg-grammar.y"
    { afinet_dest_set_template_escape(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 136:
#line 513 "cfg-grammar.y"
    { afinet_dest_set_localport(last_dest_driver, 0, (yyvsp[-1].cptr), "udp"); free((yyvsp[-1].cptr)); }
    break;

  case 137:
#line 514 "cfg-grammar.y"
    { afinet_dest_set_destport(last_dest_driver, 0, (yyvsp[-1].cptr), "udp"); free((yyvsp[-1].cptr)); }
    break;

  case 138:
#line 515 "cfg-grammar.y"
    { afinet_dest_set_destport(last_dest_driver, 0, (yyvsp[-1].cptr), "udp"); free((yyvsp[-1].cptr)); }
    break;

  case 139:
#line 516 "cfg-grammar.y"
    { afinet_dest_set_spoof_source(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 140:
#line 521 "cfg-grammar.y"
    { 
	    last_dest_driver = make_afinet_dest(
			&make_inet_address_c((yyvsp[0].cptr), "514")->super, 
			AFSOCKET_STREAM); 
	    free((yyvsp[0].cptr));
	  }
    break;

  case 141:
#line 527 "cfg-grammar.y"
    { (yyval.ptr) = last_dest_driver; }
    break;

  case 145:
#line 537 "cfg-grammar.y"
    { afinet_dest_set_tcp_keepalive(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 146:
#line 538 "cfg-grammar.y"
    { afinet_dest_set_localport(last_dest_driver, 0, (yyvsp[-1].cptr), "tcp"); free((yyvsp[-1].cptr)); }
    break;

  case 147:
#line 539 "cfg-grammar.y"
    { afinet_dest_set_destport(last_dest_driver, 0, (yyvsp[-1].cptr), "tcp"); free((yyvsp[-1].cptr)); }
    break;

  case 148:
#line 540 "cfg-grammar.y"
    { afinet_dest_set_destport(last_dest_driver, 0, (yyvsp[-1].cptr), "tcp"); free((yyvsp[-1].cptr)); }
    break;

  case 152:
#line 544 "cfg-grammar.y"
    { afinet_dest_set_syncfreq(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 153:
#line 548 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 154:
#line 552 "cfg-grammar.y"
    { last_dest_driver = make_afuser_dest((yyvsp[0].cptr)); free((yyvsp[0].cptr)); }
    break;

  case 155:
#line 553 "cfg-grammar.y"
    { (yyval.ptr) = last_dest_driver; }
    break;

  case 156:
#line 557 "cfg-grammar.y"
    { afuser_dest_set_template(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 157:
#line 558 "cfg-grammar.y"
    { afuser_dest_set_template_escape(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 160:
#line 567 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-1].ptr); }
    break;

  case 161:
#line 571 "cfg-grammar.y"
    { last_dest_driver = make_afprogram_dest((yyvsp[0].cptr)); free((yyvsp[0].cptr)); }
    break;

  case 162:
#line 572 "cfg-grammar.y"
    { (yyval.ptr) = last_dest_driver; }
    break;

  case 163:
#line 576 "cfg-grammar.y"
    { afprogram_dest_set_template(last_dest_driver, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 164:
#line 577 "cfg-grammar.y"
    { afprogram_dest_set_template_escape(last_dest_driver, (yyvsp[-1].num)); }
    break;

  case 167:
#line 586 "cfg-grammar.y"
    { (yyval.ptr) = make_afremctrl_dest(); }
    break;

  case 168:
#line 590 "cfg-grammar.y"
    { append_endpoint_info((yyvsp[-2].ptr), (yyvsp[0].ptr)); (yyval.ptr) = (yyvsp[-2].ptr); }
    break;

  case 169:
#line 591 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 170:
#line 595 "cfg-grammar.y"
    { (yyval.ptr) = make_log_endpoint_info(EP_SOURCE, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 171:
#line 596 "cfg-grammar.y"
    { (yyval.ptr) = make_log_endpoint_info(EP_FILTER, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 172:
#line 597 "cfg-grammar.y"
    { (yyval.ptr) = make_log_endpoint_info(EP_DESTINATION, (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 173:
#line 601 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[-2].num); }
    break;

  case 174:
#line 602 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 175:
#line 607 "cfg-grammar.y"
    { (yyval.num) |= (yyvsp[0].num); }
    break;

  case 176:
#line 608 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 177:
#line 612 "cfg-grammar.y"
    { (yyval.num) = LOG_CONN_CATCHALL; }
    break;

  case 178:
#line 613 "cfg-grammar.y"
    { (yyval.num) = LOG_CONN_FALLBACK; }
    break;

  case 179:
#line 614 "cfg-grammar.y"
    { (yyval.num) = LOG_CONN_FINAL; }
    break;

  case 180:
#line 618 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[-2].ptr); }
    break;

  case 181:
#line 619 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 182:
#line 623 "cfg-grammar.y"
    { configuration->mark_freq = (yyvsp[-1].num); }
    break;

  case 183:
#line 624 "cfg-grammar.y"
    { configuration->sync_freq = (yyvsp[-1].num); }
    break;

  case 184:
#line 625 "cfg-grammar.y"
    { configuration->stats_freq = (yyvsp[-1].num); }
    break;

  case 185:
#line 626 "cfg-grammar.y"
    { configuration->chain_hostnames = (yyvsp[-1].num); }
    break;

  case 186:
#line 627 "cfg-grammar.y"
    { configuration->keep_hostname = (yyvsp[-1].num); }
    break;

  case 187:
#line 628 "cfg-grammar.y"
    { configuration->check_hostname = (yyvsp[-1].num); }
    break;

  case 188:
#line 629 "cfg-grammar.y"
    { cfg_set_bad_hostname((yyvsp[-1].cptr)); }
    break;

  case 189:
#line 630 "cfg-grammar.y"
    { configuration->use_time_recvd = (yyvsp[-1].num); }
    break;

  case 190:
#line 631 "cfg-grammar.y"
    { configuration->use_fqdn = (yyvsp[-1].num); }
    break;

  case 191:
#line 632 "cfg-grammar.y"
    { configuration->use_dns = (yyvsp[-1].num); }
    break;

  case 192:
#line 633 "cfg-grammar.y"
    { configuration->time_reopen = (yyvsp[-1].num); }
    break;

  case 193:
#line 634 "cfg-grammar.y"
    { configuration->time_sleep = (yyvsp[-1].num); }
    break;

  case 194:
#line 635 "cfg-grammar.y"
    { configuration->time_reap = (yyvsp[-1].num); }
    break;

  case 195:
#line 636 "cfg-grammar.y"
    { configuration->log_fifo_size = (yyvsp[-1].num); }
    break;

  case 196:
#line 637 "cfg-grammar.y"
    { configuration->gc_busy_threshold = (yyvsp[-1].num); }
    break;

  case 197:
#line 638 "cfg-grammar.y"
    { configuration->gc_idle_threshold = (yyvsp[-1].num); }
    break;

  case 198:
#line 639 "cfg-grammar.y"
    { configuration->create_dirs = (yyvsp[-1].num); }
    break;

  case 199:
#line 640 "cfg-grammar.y"
    { configuration->sanitize_filenames = (yyvsp[-1].num); }
    break;

  case 200:
#line 641 "cfg-grammar.y"
    { cfg_set_owner((yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 201:
#line 642 "cfg-grammar.y"
    { cfg_set_group((yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 202:
#line 643 "cfg-grammar.y"
    { cfg_set_perm((yyvsp[-1].num)); }
    break;

  case 203:
#line 644 "cfg-grammar.y"
    { cfg_set_dir_owner((yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 204:
#line 645 "cfg-grammar.y"
    { cfg_set_dir_group((yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 205:
#line 646 "cfg-grammar.y"
    { cfg_set_dir_perm((yyvsp[-1].num)); }
    break;

  case 206:
#line 647 "cfg-grammar.y"
    { configuration->dns_cache = (yyvsp[-1].num); }
    break;

  case 207:
#line 648 "cfg-grammar.y"
    { configuration->dns_cache_size = (yyvsp[-1].num); }
    break;

  case 208:
#line 649 "cfg-grammar.y"
    { configuration->dns_cache_expire = (yyvsp[-1].num); }
    break;

  case 209:
#line 651 "cfg-grammar.y"
    { configuration->dns_cache_expire_failed = (yyvsp[-1].num); }
    break;

  case 210:
#line 652 "cfg-grammar.y"
    { configuration->log_msg_size = (yyvsp[-1].num); }
    break;

  case 211:
#line 656 "cfg-grammar.y"
    { (yyval.ptr) = make_filter_rule((yyvsp[-4].cptr), (yyvsp[-2].node)); free((yyvsp[-4].cptr)); }
    break;

  case 212:
#line 660 "cfg-grammar.y"
    { (yyval.node) = (yyvsp[0].node); if (!(yyvsp[0].node)) return 1; }
    break;

  case 213:
#line 661 "cfg-grammar.y"
    { (yyvsp[0].node)->comp = !((yyvsp[0].node)->comp); (yyval.node) = (yyvsp[0].node); }
    break;

  case 214:
#line 662 "cfg-grammar.y"
    { (yyval.node) = make_filter_or((yyvsp[-2].node), (yyvsp[0].node)); }
    break;

  case 215:
#line 663 "cfg-grammar.y"
    { (yyval.node) = make_filter_and((yyvsp[-2].node), (yyvsp[0].node)); }
    break;

  case 216:
#line 664 "cfg-grammar.y"
    { (yyval.node) = (yyvsp[-1].node); }
    break;

  case 217:
#line 668 "cfg-grammar.y"
    { (yyval.node) = make_filter_facility((yyvsp[-1].num));  }
    break;

  case 218:
#line 669 "cfg-grammar.y"
    { (yyval.node) = make_filter_facility(0x80000000 | (yyvsp[-1].num)); }
    break;

  case 219:
#line 670 "cfg-grammar.y"
    { (yyval.node) = make_filter_level((yyvsp[-1].num)); }
    break;

  case 220:
#line 671 "cfg-grammar.y"
    { (yyval.node) = make_filter_prog((yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 221:
#line 672 "cfg-grammar.y"
    { (yyval.node) = make_filter_netmask((yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 222:
#line 673 "cfg-grammar.y"
    { (yyval.node) = make_filter_host((yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 223:
#line 674 "cfg-grammar.y"
    { (yyval.node) = make_filter_match((yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 224:
#line 675 "cfg-grammar.y"
    { (yyval.node) = make_filter_call((yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
    break;

  case 225:
#line 679 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[-1].num) + (yyvsp[0].num); }
    break;

  case 226:
#line 680 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[0].num); }
    break;

  case 227:
#line 685 "cfg-grammar.y"
    { 
	    int n = syslog_lookup_facility((yyvsp[0].cptr));
	    if (n == -1)
	      {
	        werror("Warning: Unknown facility %z\n", (yyvsp[0].cptr));
	        (yyval.num) = 0;
	      }
	    else
	      (yyval.num) = (1 << n); 
	    free((yyvsp[0].cptr)); 
	  }
    break;

  case 228:
#line 699 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[-1].num) + (yyvsp[0].num); }
    break;

  case 229:
#line 700 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[0].num); }
    break;

  case 230:
#line 705 "cfg-grammar.y"
    { 
	    int r1, r2;
	    r1 = syslog_lookup_level((yyvsp[-2].cptr));
	    if (r1 == -1)
	      werror("Warning: Unknown priority level %z\n", (yyvsp[-2].cptr));
	    else
	      r1 = sl_levels[r1].value;
	    r2 = syslog_lookup_level((yyvsp[0].cptr));
	    if (r2 == -1)
	      werror("Warning: Unknown priority level %z\n", (yyvsp[-2].cptr));
	    else
	      r2 = sl_levels[r2].value;
	    if (r1 != -1 && r2 != -1)
	      (yyval.num) = syslog_make_range(r1, r2); 
	    else
	      (yyval.num) = 0;
	    free((yyvsp[-2].cptr)); 
	    free((yyvsp[0].cptr)); 
	  }
    break;

  case 231:
#line 725 "cfg-grammar.y"
    { 
	    int n = syslog_lookup_level((yyvsp[0].cptr)); 
	    if (n == -1)
	      {
	        werror("Warning: Unknown priority level %z\n", (yyvsp[0].cptr));
	        (yyval.num) = 0;
	      }
	    else
	      (yyval.num) = 1 << sl_levels[n].value; 
	    free((yyvsp[0].cptr)); 
	  }
    break;

  case 232:
#line 739 "cfg-grammar.y"
    { (yyval.num) = 1; }
    break;

  case 233:
#line 740 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 234:
#line 741 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[0].num); }
    break;

  case 235:
#line 745 "cfg-grammar.y"
    { (yyval.num) = 2; }
    break;

  case 236:
#line 746 "cfg-grammar.y"
    { (yyval.num) = 1; }
    break;

  case 237:
#line 747 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 240:
#line 753 "cfg-grammar.y"
    { char buf[32]; snprintf(buf, sizeof(buf), "%d", (yyvsp[0].num)); (yyval.cptr) = strdup(buf); }
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 2956 "cfg-grammar.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 756 "cfg-grammar.y"


extern int linenum;

void yyerror(char *msg)
{
	fprintf(stderr, "%s at %d\n", msg, linenum);
}

