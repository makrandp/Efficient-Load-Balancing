#!/bin/bash

./cpu_usage.out

ssh jitesh@client1 './cpu_usage.out'

echo "                                          ***** GETTING cpu_usage FILE FROM HOST 2 *****"

scp jitesh@client1:/home/jitesh/server2_usage server2_usage



ssh server3@client3 './cpu_usage.out'

echo "                                          ***** GETTING cpu_usage FILE FROM HOST 3 *****"

scp server3@client3:/home/server3/server3_usage server3_usage



