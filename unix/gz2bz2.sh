#!/bin/bash

ls | grep .gz | while read line
do
   	wc -c $line
	gzip -d $line 
	bzip2  ${line%.*}
	wc -c ${line%.*}.bz2
done 
