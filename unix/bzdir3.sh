#!/bin/bash

if [ ${1#*.} = 'tar.gz' ] ; then
    echo "${1%%.*}.tar.bz2"
fi
