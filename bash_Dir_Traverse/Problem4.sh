#!/bin/bash

letters=()
count=()

i=0
for fLett in {a..z}
do
	letters[$i]=$fLett
	count[$i]=$(ls /bin | grep -c "^$fLett")
	i=$(($i + 1))
done



for j in {0..25}
do
	echo "${letters[$j]} ${count[$j]}"
done
