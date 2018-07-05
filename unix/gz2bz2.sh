#!/bin/bash

ls | while read line
do
    if [ ${line##*.} = 'gz' ]; then
	wc -c $line
	gzip -d $line 
	bzip2  ${line%.*}
	wc -c ${line%.*}.bz2
    fi
done 
