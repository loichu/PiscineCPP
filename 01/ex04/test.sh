#!/usr/bin/env bash

EMPTY_FILE=$1
ONE_LINE_FILE=$2
BIG_FILE=$3
INVALID_LINE_FILE=$4
FILE_READ=$5
FILE_WRITTEN=$6
DIR=$7
FILE_DENIED=$8
NORMAL_FILE=$9
FILE_WRITE_DENIED=$NORMAL_FILE.replace
TEST_DIR=${10}

OK="\x1b[32;49mOK\x1b[0m"
KO="\x1b[31;49mKO\x1b[0m"

check_result () {
	echo -n "" > $1.replace
	./sed "$1" "$2" "$3"
	perl -pe "s/$2/$3/g" $1 > $1.check
	if diff $1.replace $1.check > "$1-$2-$3".diff; then
		echo -ne $OK ' '
	else
		echo -ne $KO ' '
	fi
}

echo "Test with non-existent file"
./sed doesnt_exist lol mdr
./sed "" lol mdr
echo -ne "\n\n"

echo "Test with empty file"
check_result $EMPTY_FILE no no
check_result $EMPTY_FILE "" HAHA
check_result $EMPTY_FILE HAHA ""
echo -ne "\n\n"

echo "Test with a single line file"
check_result $ONE_LINE_FILE line row
check_result $ONE_LINE_FILE "" HAHA
check_result $ONE_LINE_FILE HAHA ""
check_result $ONE_LINE_FILE line ""
echo -ne "\n\n"

echo "Test with a big file"
check_result $BIG_FILE line row
check_result $BIG_FILE "" HAHA
check_result $BIG_FILE HAHA ""
check_result $BIG_FILE line ""
echo -ne "\n\n"

echo "Test with an unterminated line"
check_result $INVALID_LINE_FILE line row
check_result $INVALID_LINE_FILE "" HAHA
check_result $INVALID_LINE_FILE HAHA ""
check_result $INVALID_LINE_FILE line ""
echo -ne "\n\n"

echo "Test read from a file opened for reading"
echo "Test read from a file opened for writing"
echo "Test write to a file opened for reading"
echo "Test write to a file opened for writing"


