#!/bin/bash

#//usr/share/docutils/writers/

function dirPermissions(){
    for file in $1/*
	do
	if [ ! -d "${file}" ]
	then
        usr=$(ls -l "${file}" | awk '{print $3}')
        perm=$(ls -l "${file}" | grep -o '^.\{10\}')
        if [[ "$usr" == "$2" ]] && [[ ${perm:1:1} = 'r' ]] && [[ ${perm:4:1} = 'r' ]] && [[ ${perm:7:1} = 'r' ]]
        then
            # i=$(ls -l "${file}")
            dir=$(ls -l "${file}" | awk '{print $9}')
            time=$(ls -l "${file}" | awk '{print $6" "$7" "$8}')
            # echo $i
            echo '----------------'
            echo "Pathname is $dir"
            echo "Permissions are $perm"
            echo "Time created is $time"
        fi
	else
		dirPermissions "${file}" "$2"
	fi
	done
}

dirPermissions $1 $2
