#! /bin/bash

if [ -f "file.txt" ]; then
    echo "File exists"
else
    echo "File does not exist"
fi

## three ways to do multiple tests
if [ -f "file.txt" ] && [ -r "file.txt" ]; then
    echo "File exists and is readable"
else
    echo "File either does not exist or is not readable"
fi
if [ -f "file.txt" -a -r "file.txt" ]; then
    echo "File exists and is readable"
else
    echo "File either does not exist or is not readable"
fi
if [[ -f "file.txt" && -r "file.txt" ]]; then
    echo "File exists and is readable"
else
    echo "File either does not exist or is not readable"
fi


test -f "file.txt" && echo "File exists" || echo "File does not exist"

[ -f "file.txt" ] && echo "File exists" || echo "File does not exist" 

num=1
[ $num -eq 001 ] && echo "true" || echo "false"     # `-eq` is used for integer comparison      >> true
[ $num = 001 ]   && echo "true" || echo "false"     # `=`   is used for string comparison       >> false


