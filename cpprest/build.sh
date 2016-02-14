#!/bin/bash

cd `dirname $0`
cur_path=`pwd`

tmp_path=`mktemp -d`
echo "move to $tmp_path/build"

mv build $tmp_path/

mkdir -p build/include
mkdir -p build/include/base

make clean
make
make clean

cp *.h build/include/
cp base/*.h build/include/base/

