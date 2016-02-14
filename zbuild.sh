#!/bin/bash
cd `dirname $0`
cur_path=`pwd`

rm -rf "$cur_path/build"

make clean
make
make clean

#execute test
cd $cur_path

./build/test
