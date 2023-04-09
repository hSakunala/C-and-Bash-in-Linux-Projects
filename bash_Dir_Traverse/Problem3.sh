#!/bin/bash


myArr=($@)

echo "Original Array:"
echo ${myArr[*]}


function sorting(){
	arr=("$@")
	len=${#arr[@]}
	#echo $len
	for ((i=1;i<$len;i++))
	do
		key=${arr[$i]}
		j=$(($i - 1))
		#echo "j is $j with the ${arr[$j]} and key is $key"
		#echo "key is $key and arr element is ${arr[$j]}"
		while [ $j -ge 0 ] && [ $key -lt ${arr[$j]} ]
		do
			num=$(($j + 1))
			arr[$num]=${arr[$j]}
			j=$(($j - 1))
		done
		num2=$(($j + 1))
		arr[$num2]=$key
	done
	echo ${arr[*]}


}


echo "-----------------"
echo "Sorted Numbers:"
sorting "${myArr[@]}"

