#/bin/bash

#It's the homework of cht13
#It's can show all the information of the file which end with .txt
#You can add the path of the directory which you want to set as the main path
#If you don't set path, your path now will be the main path


if [ -d $1 ]
then
	PTH=$1
else
	PTH=`pwd`
fi

cd $PTH

echo "Now the path is `pwd`"
echo "Which do you want to see? size permissions owner group or all?"

read sel

if [ $sel = "size" ]
then
	ls -lh *.txt | awk '{print $9 ":" $5}'
elif [ $sel = "permissions" ]
then
	ls -lh *.txt | awk '{print $9 ":" $1}'
elif [ $sel = "owner" ]
then
	ls -lh *.txt | awk '{print $9 ":" $3}'
elif [ $sel = "group" ]
then
	ls -lh *.txt | awk '{print $9 ":" $4}'
elif [ $sel = "all" ]
then
	ls -lh *.txt | awk '{print $9 ":" $1 "," $3 "," $4 "," $5}'
fi
