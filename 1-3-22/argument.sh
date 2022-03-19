#! /bin/bash

# $@ returns a sequence of strings
# $* returns a single string

echo $0 $1 $2 $3 #arguments of echo and we can pass values in terminal 
                #which will be assigned to individual argument i.e. $0,$1..
args=("$@") #$@ = array

echo "Names: ${args[1]}  ${args[2]}  ${args[3]}"
echo $# #$# goives number of arguments passed