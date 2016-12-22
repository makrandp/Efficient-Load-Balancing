#!/bin/bash

echo "RUNNING vm_pid AND vm_migrate ON HOST 1"

pid=`cat final_pid`
ps -ef|grep $pid |awk '{ print $18  }' > vm_name


