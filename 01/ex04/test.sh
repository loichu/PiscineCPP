#!/usr/bin/env bash

EMPTY_FILE=$1
ONE_LINE_FILE=$2
BIG_FILE=$3
INVALID_LINE_FILE=$4
FILE_READ=$5
FILE_WRITTEN=$6
DIR=$7
FILE_DENIED=$8
TEST_DIR=${10}
NORMAL_FILE=$TEST_DIR/$9
FILE_WRITE_DENIED=$NORMAL_FILE.replace

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

check_result_sed () {
	echo -n "" > $1.replace
	./sed "$1" "$2" "$3"
	sed "s/$2/$3/g" $1 > $1.check
	if diff $1.replace $1.check > "$1-$2-$3".diff; then
		echo -ne $OK ' '
	else
		echo -ne $KO ' '
	fi
}

check_fail () {
	./sed "$1" "$2" "$3"
	if [ "$?" -eq "0" ]; then
		echo -ne $KO ' '
	else
		echo -ne $OK ' '
	fi
}

check_success () {
	./sed "$1" "$2" "$3"
	if [ "$?" -eq "0" ]; then
		echo -ne $OK ' '
	else
		echo -ne $KO ' '
	fi
}

echo "Test invalid number of parameters"
check_fail file
check_fail
check_fail file s1 s2 s3

echo "Test with non-existent file"
check_fail doesnt_exist lol mdr
check_fail "" lol mdr
echo -ne "\n\n"

echo "Test with empty file"
check_result $EMPTY_FILE no no
check_result_sed $EMPTY_FILE "" HAHA
check_result $EMPTY_FILE HAHA ""
echo -ne "\n\n"

echo "Test with a single line file"
check_result $ONE_LINE_FILE line row
check_result_sed $ONE_LINE_FILE "" HAHA
check_result $ONE_LINE_FILE HAHA ""
check_result $ONE_LINE_FILE line ""
echo -ne "\n\n"

echo "Test with a big file"
check_result $BIG_FILE line row
check_result_sed $BIG_FILE "" HAHA
check_result $BIG_FILE HAHA ""
check_result $BIG_FILE line ""
echo -ne "\n\n"

echo "Test with an unterminated line"
check_result $INVALID_LINE_FILE line row
check_result_sed $INVALID_LINE_FILE "" HAHA
check_result $INVALID_LINE_FILE HAHA ""
check_result $INVALID_LINE_FILE line ""
echo -ne "\n\n"

echo "Test read from a file opened for reading"
python -c 'import time; f = open("'$FILE_READ'"); time.sleep(4)' &
check_result $FILE_READ "to" "2"
echo -ne "\n\n"

echo "Test read from a file opened for writing"
python -c 'import time; f = open("'$FILE_WRITTEN'", "a"); time.sleep(4)' & 
check_result $FILE_WRITTEN "to" "2"
echo -ne "\n\n"

echo "Test write to a file opened for reading"
python -c 'import time; f = open("'${FILE_READ}_2.replace'"); time.sleep(4)' &
check_result ${FILE_READ}_2 "to" "2"
echo -ne "\n\n"


echo "Test write to a file opened for writing"
python -c 'import time; f = open("'${FILE_WRITTEN}_2.replace'", "a"); time.sleep(4)' & 
check_result ${FILE_WRITTEN}_2 "to" "2"
echo -ne "\n\n"

echo "Test with a directory instead of file"
check_result $DIR "test" "repl"
echo -ne "\n\n"

echo "Test with a file without read permsissions"
check_fail $FILE_DENIED "test" "repl"
echo -ne "\n\n"

echo "Test write result to a file without write permissions"
check_fail $NORMAL_FILE "return" "LOL"
echo -ne "\n\n"



