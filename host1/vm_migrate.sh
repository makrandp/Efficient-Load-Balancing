#!/bin/bash
CYAN='\033[01;36m'

virtual_name=`cat vm_name`
target_name=`cat target_name`


virsh migrate --live $virtual_name qemu+ssh://$target_name/system

echo "${CYAN} ${BOLD}                                          ***** Successfully tansferred ***** ${NONE} ${NONE}"

tput sgr0
