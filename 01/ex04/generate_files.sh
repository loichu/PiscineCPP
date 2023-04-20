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

echo -n "" > $EMPTY_FILE
echo "This is a line" > $ONE_LINE_FILE
yes "This is a line" | head -n 100000 > $BIG_FILE
echo -ne "validline\ninvalidline" > $INVALID_LINE_FILE
echo "i am opened to read from" > $FILE_READ
echo "i am opened to write to" > $FILE_WRITTEN
if [[ ! -d $DIR ]]; then
    mkdir $DIR
fi
rm -f $FILE_WRITE_DENIED
echo "Cannot write to this file" > $FILE_WRITE_DENIED
chmod a-w $FILE_WRITE_DENIED
