#!/bin/bash

if [ -f $1 ] || [ -d $1 ]
then
	if [ -f $1 ]
	then
		echo "$1 is a file"
		size=$(du -b $1 | awk '{print $1}')
		echo "The size of $1 is $size"
		if [ $size -gt 1048576 ]
		then
			echo "$1 is a large sized file"
		elif [ $size -le 1048576 ] && [ $size -gt 102400 ]
		then
			echo "$1 is a medium sized file"
		else
			echo "$1 is a small sized file"
		fi 
	else
		echo "$1 is a directory"
	fi
fi

echo "end"
