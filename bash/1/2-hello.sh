#!/bin/bash

#set -x
set -e

str=" from hla"
printf "Hello, Bash! %s\n" "$str"

read -rp "Enter your name: " name
echo "Hello, $name! Pls enter ur password: "
read -rs password
echo "thnx $name! ur password is $password"

name="hal rda"
if [ "$name" = "hal rda" ]; then
    echo "usr is hal rda"
else
    echo "too many arguments"
fi

cmd=$(ls -l)
echo "$cmd"

sort << EOF
lilo
hla
ahmd
EOF

touch file.txt
cat << EOF > file.txt
jhncfkjnb
bcjmbnc
EOF

cat file.txt