#!/bin/bash

Usage(){
    echo "bzdir <ディレクトリ名>"
    echo "でディレクトリを圧縮したtar.bz2が作成できます。"
}

#----------------------------------------------#

if [ ! -d  $1 ]; then
    echo "ディレクトリが存在しません。"
elif [ $# -ne '1' ]; then
    Usage
else
    tar -zcvf $1.tar.bz2 $1
fi
