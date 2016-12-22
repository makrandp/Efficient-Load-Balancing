#!/bin/bash

top -b -n 2 > top_usage

string=`cat top_usage | grep 'Cpu' | head -2 | tail -1 | awk '{ print $2, $3, $4  }'`

usr=`echo $string | cut -d',' -f 1 | cut -d '%' -f 1`
sys=`echo $string | cut -d',' -f 2 | cut -d '%' -f 1`
nic=`echo $string | cut -d',' -f 3 | cut -d '%' -f 1`


#cpu=`expr $usr + $sys + $nic`


cpu=`echo $usr + $sys + $nic | bc`


echo $cpu > cpu.temp

