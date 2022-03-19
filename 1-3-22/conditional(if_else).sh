#! /bin/bash
#: ' if [ expression ];
 #     then
  #          statements
   #   elif [ expression ];
    #  then
     #       statements
      #else
       #     statements
      #fi'
count=11
if (("$count" > 10))     
then
    echo "condition is true"
fi

word=abc
if [ $word = ab ]
then
    echo "true"
elif [[ $word = abc ]]
then 
    echo "1"
else
    echo "false"
fi
