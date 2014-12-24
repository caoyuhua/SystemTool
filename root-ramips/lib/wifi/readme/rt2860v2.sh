#!/bin/sh
# Copyright (C) 2006 OpenWrt.org
#rootfs/lib/wifi目录下为ralink 5G版本SDK提供的wireless配置文件默认生成和修改脚本
#rootfs/lib/wifi/readme/rt2860v2.sh为ralink 2.4G版本SDK提供的wireless配置文件默认生成和修改脚本
#rootfs/lib/wifi/readme/mac80211.sh为openwrt编写的通用wireless配置文件默认生成和修改脚本(如使用usb口wifi模块时就会用到)
append DRIVERS "rt2860v2"


set_rt2860() {
	sed -i "/^$1=/d" /etc/Wireless/RT2860/RT2860.dat
	echo "$1=""$2" >> /etc/Wireless/RT2860/RT2860.dat
}

add_rt2860() {
	local name="$1"
	local vars="$2"
	sed -i 's/^'"$name"'=\(.*\)/&;'"$vars"'/g' /etc/Wireless/RT2860/RT2860.dat
}


start_rt2860v2_vif() {
	local vif="$1"
	local ifname="$2"

	local net_cfg
	net_cfg="$(find_net_config "$vif")"
	[ -z "$net_cfg" ] || start_net "$ifname" "$net_cfg"
}

find_rt2860v2_phy() {
	local device="$1"

	config_get vifs "$device" vifs
	for vif in $vifs; do
		config_get_bool disabled "$vif" disabled 0
		[ $disabled = 0 ] || continue
		return 0
	done

	return 1
}
reload_rt2860v2() {
	ifconfig ra0 down
	rmmod rt2860v2_ap 

	insmod rt2860v2_ap
	ifconfig ra0 up
}

scan_rt2860v2() {
	local device="$1"
}

enable_rt2860v2() {
	local device="$1"
	config_get channel "$device" channel
	config_get vifs "$device" vifs
	config_get hwmode "$device" hwmode
	config_get ht "$device" ht
	config_get country "$device" country
	config_get txstream "$device" txstream
	config_get rxstream "$device" rxstream
	config_get txpower "$device" txpower
	config_get wmmmode "$device" wmm

	find_rt2860v2_phy "$device" || return 0

	[ -n "$channel" ] && set_rt2860 Channel "$channel"
	[ -n "$txpower" ] && set_rt2860 TxPower "$txpower" 
	[ -n "$wmmmode" ] && {
		if [ "$wmmmode" = "0" ]; then
			set_rt2860 WmmCapable "0;0"
		else
			set_rt2860 WmmCapable "1;1"
		fi
	}
	if [ $channel -eq 0 ]; then
		set_rt2860 AutoChannelSelect 1
	else
		set_rt2860 AutoChannelSelect 0
	fi
	if [ $channel -ge 6 ]; then
		set_rt2860 HT_EXTCHA 0
	else
		set_rt2860 HT_EXTCHA 1
	fi

	case "$hwmode" in
		11b)
			set_rt2860 WirelessMode 1
			;;
		11g) 
			set_rt2860 WirelessMode 4
			;;
		11n)
			set_rt2860 WirelessMode 6
			;;
		11gn)
			set_rt2860 WirelessMode 7
			;;
		11bgn)
			set_rt2860 WirelessMode 9
			;;
	esac
	
	if [ "$ht" = "20" ]; then
		set_rt2860 HT_BW 0 
	elif [ "$ht" = "20+40" ]; then
		set_rt2860 HT_BW	1
		set_rt2860 HT_BSSCoexistence 1
	elif [ "$ht" = "40" ] ; then
		set_rt2860 HT_BW	1 
		set_rt2860 HT_BSSCoexistence 0
	else
		set_rt2860 HT_BW	1 
		set_rt2860 HT_BSSCoexistence 1
	fi
	
 	[ -n "$country" ] && set_rt2860 CountryCode "$country"   
	[ -n "$txstream" ] && set_rt2860 HT_TxStream $txstream
	[ -n "$rxstream" ] && set_rt2860 HT_RxStream $rxstream

	set_rt2860 ApCliEnable 0
	for vif in $vifs; do
		config_get_bool disabled "$vif" disabled 0
		[ $disabled = 0 ] || continue
		
				
		config_get ifname "$vif" ifname
		config_get mode "$vif" mode
		config_get ssid "$vif" ssid
		config_get bssid "$vif" bssid
		config_get macaddr "$vif" macaddr
		config_get hidden "$vif" hidden
		config_get txrate "$vif" txrate
		config_get macfilter "$vif" macfilter_type
		config_get encryption "$vif" encryption
		config_get security_type "$vif" security_type
		config_get key "$vif" key
		config_get key1 "$vif" key1
		config_get rekey "$vif" rekey
		config_get ssidprefix "$vif" ssidprefix
		config_get apcli_encryption "$vif" apcli_encryption
		config_get apcli_index "$vif" apcli_index

		#added by chengwei
		config_get wps_disabled "$vif" wps_disabled
		config_get wps_associate "$vif" wps_associate
		#end,added by chengwei
    
		config_get_bool isolate "$vif" isolate 0
		
		[ "$mode" == "sta" ] && [ "$ifname" = "ra0" ] && {
			set_rt2860 SSID "$ssid"
			case "$encryption" in
			psk-mixed | psk2)
				set_rt2860 AuthMode "WPA2PSK"
				set_rt2860 EncrypType "AES"								
			;;
			psk)
				set_rt2860 AuthMode "WPAPSK"
				set_rt2860 EncrypType "AES"		
			;;
			*)
				set_rt2860 AuthMode "OPEN"
				set_rt2860 EncrypType "NONE"		
			;;
			esac
			[ -n "$key" ] && set_rt2860 WPAPSK "$key"
		}

		[ "$ifname" = "apcli0" ] && {
			set_rt2860 ApCliEnable 1
			set_rt2860 ApCliSsid "$ssid"
			set_rt2860 ApCliBssid "$bssid"
			case "$encryption" in
			psk-mixed | psk2)
				set_rt2860 ApCliAuthMode "WPA2PSK"
				set_rt2860 ApCliEncrypType "AES"
				set_rt2860 ApCliWPAPSK "$key"
			;;
			psk)
				set_rt2860 ApCliAuthMode "WPAPSK"
				set_rt2860 ApCliEncrypType "AES"
				set_rt2860 ApCliWPAPSK "$key"
			;;
			wep)
				set_rt2860 ApCliAuthMode "$apcli_encryption"
				set_rt2860 ApCliEncrypType "WEP"
				set_rt2860 ApCliDefaultKeyID "$apcli_index"
				if [ "$apcli_index" = "1" ]; then
					set_rt2860 ApCliKey1Str "$key1"
					set_rt2860 ApCliKey1Type "0"
				elif [ "$apcli_index" == "2" ]; then
					set_rt2860 ApCliKey2Str "$key1"
					set_rt2860 ApCliKey2Type "0"
				elif [ "$apcli_index" == "3" ]; then
					set_rt2860 ApCliKey3Str "$key1"
					set_rt2860 ApCliKey2Type "0"
				else
					set_rt2860 ApCliKey4Str "$key1"
					set_rt2860 ApCliKey4Type "0"
				fi
			;;
			*)
				set_rt2860 ApCliAuthMode "OPEN"
				set_rt2860 ApCliEncrypType "NONE"
			;;
			esac

			continue
		}

		[ "$mode" == "ap" ] && {
			set_rt2860 BssidNum 1
			[ -n "$ssid" ] && {
				set_rt2860 SSID1 "$ssidprefix""$ssid"
			}
			if [ "$hidden" = "enable" ]; then
				set_rt2860 HideSSID 1
			else
				set_rt2860 HideSSID 0
			fi

			if [ "$macfilter" == "1" ]; then
				set_rt2860 AccessPolicy0 1
				set_rt2860 AccessControlList0 "$macaddr"
			elif [ "$macfilter" == "2" ]; then
				set_rt2860 AccessPolicy0 2
				set_rt2860 AccessControlList0 "$macaddr"
			else
				set_rt2860 AccessPolicy0 0
				set_rt2860 AccessControlList0 ""
			fi
                        
			if [ "$wps_disabled" == "0" ]; then
				set_rt2860 WscConfStatus 2
				set_rt2860 WscConfMode 7
			else
				set_rt2860 WscConfStatus 1
				set_rt2860 WscConfMode 0
			fi

			if [ "$wps_associate" == "1" ]; then
				set_rt2860 WscGetConf 1
			else
				set_rt2860 WscGetConf 0
			fi

			[ -n "$maclist" ] && {
				i=0
                for aclmac in $maclist; do
					if [ $i -eq 0 ]; then
						i=1
						set_rt2860 AccessControlList0 "$aclmac"
					else
						add_rt2860 AccessControlList0 "$aclmac"
					fi
				done
			}

			case "$encryption" in
				psk-mixed*)
					set_rt2860 AuthMode "WPAPSKWPA2PSK"
					set_rt2860 EncrypType "TKIPAES"
					;;
				psk2*)
					set_rt2860 AuthMode "WPA2PSK"
					set_rt2860 EncrypType "AES"
					;;
				psk*)
					set_rt2860 AuthMode "WPAPSK"
					set_rt2860 EncrypType "AES"				
					;;
				*)
					set_rt2860 AuthMode "OPEN"
					set_rt2860 EncrypType "NONE"
				;;
			esac

			if [ "$security_type" == "tkip" ]; then
				set_rt2860 EncrypType "TKIP"
			elif [ "$security_type" == "aes" ]; then
				set_rt2860 EncrypType "AES"
			elif [ "$security_type" == "tkip_aes" ]; then
				set_rt2860 EncrypType "TKIPAES"				
			else
				set_rt2860 EncrypType "NONE"
			fi

			[ -n "$key" ] && {
				set_rt2860 WPAPSK1 "$key"
			}
			[ -n "$rekey" ] && {
				set_rt2860 RekeyInterval "$rekey"
			}
	}
	done

	for vif in $vifs; do
		config_get_bool disabled "$vif" disabled 0
		[ $disabled = 0 ] || continue
		
		config_get ifname "$vif" ifname
		config_get network "$vif" network
		[ "$network" = "lan" ] && {
			start_rt2860v2_vif "$vif" "$ifname"
			set_wifi_up "$vif" "$ifname"
			ifconfig $ifname up
		}
		
	done


	return 0
}

disable_rt2860v2() {
	local device="$1"
	config_get vifs "$device" vifs

	set_wifi_down "$device"

	include /lib/network
	for vif in $vifs; do
		config_get ifname "$vif" ifname
		config_get network "$vif" network
		[ "$network" = "lan" ] && {
			ifconfig $ifname down 2>/dev/null
			if [ $? -eq 0 ]; then
				unbridge $ifname $network
			fi
		}
	done

	return 0
}

detect_rt2860v2() {
	devidx=0
	config_load wireless
	while :; do
		config_get type "radio$devidx" type
		[ -n "$type" ] || break
		devidx=$((devidx + 1))
		[ -n "$type" ] && [ "$type" != "rt2860v2" ] && continue
		[ -n "$type" ] && [ "$type" == "rt2860v2" ] && return
	done

	cat <<EOF
config wifi-device radio$devidx
	option type	rt2860v2
	option channel	11

config wifi-iface
	option device	radio$devidx
	option ifname	ra0
	option network	lan
	option mode	ap
	option ssid	Wulian${devidx#0}_$(dd bs=1 skip=4 count=6 if=/lib/firmware/soc_wmac.eeprom 2>/dev/null | hexdump -v -n 6 -e '5/1 "%02x:" 1/1 "%02x"' | awk -F ":" '{print $4""$5""$6 }'| tr a-z A-Z)
	option encryption none

config wifi-iface
	option device radio0
	option ifname apcli0
	option mode sta
	option ssid	Wulian${devidx#0}_$(dd bs=1 skip=4 count=6 if=/lib/firmware/soc_wmac.eeprom 2>/dev/null | hexdump -v -n 6 -e '5/1 "%02x:" 1/1 "%02x"' | awk -F ":" '{print $4""$5""$6 }'| tr a-z A-Z)
	option encryption none
	option disabled 1
EOF

}
