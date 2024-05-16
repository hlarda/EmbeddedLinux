#! /bin/bash

set -e

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