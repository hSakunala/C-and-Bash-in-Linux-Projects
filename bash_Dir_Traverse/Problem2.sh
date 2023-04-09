#!/bin/bash

myArr=()

cd
cd $1


function reverse(){
	arr=("$@")
	len=${#arr[@]}
	len=$(($len - 1))
	for((i=$len;i>=0;i--))
	do
		echo "${arr[$i]}"
	done
}

num=0
for filename in *
do
	myArr[$num]=$filename
	num=$(($num + 1))
done

echo "Original:"

for i in "${myArr[@]}"
do
	echo "$i"
done

echo " "
echo "Reverese:"


reverse "${myArr[@]}"



