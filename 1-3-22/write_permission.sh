#! /bin/bash

echo -e "Enter the name of file: \c"
read file_name

if [ -f $file_name ] # -d if directory exists or not
then
    if [ -w $file_name ]
    then
        echo "Type. TO quit press CTRL+D"
        cat >> $file_name
    else
        echo "No permission"
else
    echo "$file_name not found"
fi
