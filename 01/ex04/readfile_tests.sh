#!/bin/bash
 
COMPILATION_SOURCE=$1
NE_FILE="na"
EMPTY_FILE="empty_file"
BIG_FILE="big_file"
ONE_LINE_FILE="one_line_file"
INVALID_LINE_FILE="invalid_line_file"
FILE_READ="file_read"
FILE_WRITTEN="file_written"
FILE_DENIED="/private/etc/bashrc"
DIR="dir"
 
# Compile test program, resulting in a.out executable.
g++ $COMPILATION_SOURCE
 
# Create test files / directories and put them in the desired state.
touch $EMPTY_FILE
if [[ ! -d $DIR ]]; then
    mkdir $DIR
fi
echo "rofl" > $ONE_LINE_FILE
echo -ne "validline\ninvalidline" > $INVALID_LINE_FILE
echo "i am opened to read from" > $FILE_READ
python -c 'import time; f = open("'$FILE_READ'"); time.sleep(4)' &
echo "i am opened to write to" > $FILE_WRITTEN
python -c 'import time; f = open("'$FILE_WRITTEN'", "a"); time.sleep(4)' & 
 
# Execute test cases.
echo "******** testing on non-existent file.."
./a.out $NE_FILE
echo
echo "******** testing on empty file.."
./a.out $EMPTY_FILE
echo
echo "******** testing on valid file with one line content"
./a.out $ONE_LINE_FILE
echo
echo "******** testing on a file with one valid and one invalid line"
./a.out $INVALID_LINE_FILE
echo
echo "******** testing on a file that is read by another process"
./a.out $FILE_READ
echo
echo "******** testing on a file that is written to by another process"
./a.out $FILE_WRITTEN
echo
echo "******** testing on a /root/.bashrc (access should be denied)"
./a.out $FILE_DENIED
echo
echo "******** testing on a directory"
./a.out $DIR
