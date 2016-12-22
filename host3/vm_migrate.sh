#!/bin/bash



virtual_name=`cat vm_name`
target_name=`cat target_name`

virsh migrate --live $virtual_name qemu+ssh://$target_name/system 


