#!/bin/bash

> allWiki.txt

for i in {A..Z}
do
	for x in {A..Z}
	do
		wget https://en.wikipedia.org/wiki/$i$x -O base.html
		html2text base.html >> allWiki.txt
	done
done


grep -owi '[a-z]*' allWiki.txt | sort | uniq -c | sort -nr | head -n 5
