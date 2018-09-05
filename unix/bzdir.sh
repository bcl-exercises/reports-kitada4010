#!/bin/bash

Usage(){
    echo "bzdir <ディレクトリ名>"
    echo "でディレクトリを圧縮したtar.bz2が作成できます。"
    exit 0
}

#----------------------------------------------#

if [ ! -d  $1 ]; then
    echo "ディレクトリが存在しません。"
    Usage
elif [ $# -ne '1' ]; then
    Usage
fi
tar -zcvf $1.tar.bz2 $1
