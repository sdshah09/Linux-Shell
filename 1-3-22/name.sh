#! /bin/bash 
echo "Enter name: "
#read -a names # -a is array
read   # only read using $REPLY
echo "Names: $REPLY"