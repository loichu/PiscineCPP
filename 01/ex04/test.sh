#!/usr/bin/env bash

EMPTY_FILE=$1
ONE_LINE_FILE=$2
BIG_FILE=$3
INVALID_LINE_FILE=$4
FILE_READ=$5
FILE_WRITTEN=$6
FILE_DENIED=$7
DIR=$8
NORMAL_FILE=$9
FILE_WRITE_DENIED=$NORMAL_FILE.replace

OK="\x1b[32;49mOK\x1b[0m"
KO="\x1b[31;49mKO\x1b[0m"

check_result () {
	./sed $1 $2 $3
	sed "s/$2/$3/g" $1 > $1.check
	if cmp $1.replace $1.check; then
		echo -ne $OK ' '
	else
		echo -ne $KO ' '
	fi
}

echo "Test with non-existent file"
./sed doesnt_exist lol mdr
echo -ne "\n\n"

echo "Test with empty file"
check_result $EMPTY_FILE no no
#check_result $EMPTY_FILE '' HAHA
echo -ne "\n\n"

echo "Test with a single file"
check_result $ONE_LINE_FILE line row
#check_result $ONE_LINE_FILE '' HAHA
echo -ne "\n\n"

echo "Test with a big file"
check_result $BIG_FILE line row
#check_result $BIG_FILE '' HAHA
echo -ne "\n\n"

echo "Test with an interminated line"
check_result $BIG_FILE line row
#check_result $BIG_FILE '' HAHA
echo -ne "\n\n"
