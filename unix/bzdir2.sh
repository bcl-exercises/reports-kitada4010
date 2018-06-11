#!/bin/bash
ls > tamesi.txt
while read line
do
    if [ -d $line ]; then
	tar -zcvf $line.tar.bz2 $line
    fi
done < ./tamesi.txt
rm tamesi.txt