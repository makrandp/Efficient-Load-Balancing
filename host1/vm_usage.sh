
#!/bin/bash

echo "RUNNING vm_usage ON HOST 1"

ps axu > ps_usage

rm utilization

cat ps_usage | grep 'kvm' | grep 115 | awk '{ print $2,$3 }' >> utilization

