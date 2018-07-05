#!/bin/bash

ls | while read line
do
    if [ -d $line ]; then
	tar -zcvf $line.tar.bz2 $line
    fi
done 
