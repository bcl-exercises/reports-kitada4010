#!/bin/bash
ls | while read line
do
    if [ ${line##*.} = 'gz' ]; then
#	echo "$lineは$(wc -c $line|)バイト"
	wc -c $line
	gzip -d $line 
	bzip2  ${line%.*}
	wc -c ${line%.*}.bz2
#       	echo "${line%.*}.bz2は$(wc -c ${line%.*}.bz2 )バイト"
#	rm gz.txt
    fi
done 
