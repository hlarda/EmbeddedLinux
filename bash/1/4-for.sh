#! /bin/bash

set -e

for i in 1 2 3 4 5; do
    echo "Number: $i"
done

for i in {1..5}; do
    echo "$i"
done

str="this is a string"
for i in $str; do
    echo "$i"
done

x=$(ls)
echo "ls output:"
for i in $x; do
    echo "$i"
done

echo "-----------------------------------"
echo "cmd: $0"
echo "$1"
echo "$2"
echo "$3"
echo "-----------------------------------"
echo "process id: $$"
echo "-----------------------------------"
echo "exit status of last cmd: "
echo [ "$?" -eq 0 ] && echo "success" || echo "failure"
echo "-----------------------------------"
echo "number of arguments:  $#"
echo "-----------------------------------"
echo "Arguments array:" 
for i in "$@"; do
    echo "$i"
done
echo "$@"
echo "-----------------------------------"
echo "Arguments string: $*"