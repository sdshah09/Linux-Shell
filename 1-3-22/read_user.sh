#!/bin/bash

read -p "Username: " user_var #-p flag for taking input on the same line as    variable

read -sp "Password: " pass_var #-sp flag gives silent input i.e. it will not show in the terminal and which is useful for password

echo " username: " $user_var

echo "password: " $pass_var
