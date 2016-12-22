#!/bin/bash

echo "                                                      ***** RUNNING vm_pid ON HOST 2 *****"

pid=`cat final_pid`

ps -ef > vm_id
cat vm_id | grep $pid | awk '{ print $18  }' > vm_name


