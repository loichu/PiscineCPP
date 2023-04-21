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
TEST_DIR=${10}
FILE_WRITE_DENIED=$TEST_DIR/$NORMAL_FILE.replace

echo -n "" > $EMPTY_FILE
echo "This is a line" > $ONE_LINE_FILE
yes "This is a line" | head -n 100000 > $BIG_FILE
echo -ne "validline\ninvalidline" > $INVALID_LINE_FILE
echo "i am opened to read from" > $FILE_READ
echo "i am opened to read from" > ${FILE_READ}_2
cp ${FILE_READ}_2 ${FILE_READ}_2.replace
echo "i am opened to write to" > $FILE_WRITTEN
echo "i am opened to write to" > ${FILE_WRITTEN}_2
cp ${FILE_WRITTEN}_2 ${FILE_WRITTEN}_2.replace
if [[ ! -d $DIR ]]; then
    mkdir $DIR
fi
cp $NORMAL_FILE $TEST_DIR
echo "Cannot write to this file" > $FILE_WRITE_DENIED
chmod a-w $FILE_WRITE_DENIED
