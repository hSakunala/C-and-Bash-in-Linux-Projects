#!/bin/bash

#/home/HrishikeshSakunala/cs288/testdir

function emptyFileDelete(){
	for file in $1/*
	do
	if [ ! -d "${file}" ]
	then
		if [ ! -s ${file} ]
		then
			rm "${file}"
		fi
	else
		emptyFileDelete "${file}"
	fi
	done
}

emptyFileDelete $1
