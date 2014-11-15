#!/bin/sh
append DRIVERS "mt7612"

. /lib/wifi/ralink_common.sh

prepare_mt7612() {
	prepare_ralink_wifi mt7612
}

scan_mt7612() {
	scan_ralink_wifi mt7612 mt76x2e
}

disable_mt7612() {
	disable_ralink_wifi mt7612
}

enable_mt7612() {
	enable_ralink_wifi mt7612 mt76x2e
}

detect_mt7612() {
#	detect_ralink_wifi mt7612 mt76x2e
	cd /sys/module/
	[ -d $module ] || return
	[ -e /etc/config/wireless ] && return
	 cat <<EOF
config wifi-device      mt7612
        option type     mt7612
        option vendor   ralink
        option band     5G
        option channel  0
        option autoch   2

config wifi-iface
        option device   mt7612
        option ifname   rai0
        option network  lan
        option mode     ap
        option ssid OpenWrt-mt7612
        option encryption psk2
        option key      12345678
EOF

}


