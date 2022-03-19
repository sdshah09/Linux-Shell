#!/bin/bash

# -e flag to determin \c or \t or \n on the same line
#if [ -s $file_name ] to check file empty or not
#if [ -r $file_name ] for read
#if [ -w $file_name ] for write
#if [ -x $file_name ] for execute
echo -e "Enter the name of file: \c"
read file_name

if [ -e $file_name ] # -e if file exists or not
then
    echo "$file_name found"
else
    echo "$file_name not found"
fi
#---------------------------------------------------------------

echo -e "Enter the name of file: \c"
read file_name

if [ -d $file_name ] # -d if directory exists or not
then
    echo "$file_name found"
else
    echo "$file_name not found"
fi
#----------------------------------------------------------

echo -e "Enter the name of file: \c"
read file_name

if [ -f $file_name ] # -f if file is regular used or not
then
    echo "$file_name found"
else
    echo "$file_name not found"
fi

