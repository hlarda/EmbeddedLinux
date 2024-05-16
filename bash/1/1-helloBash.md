# Hello Bash

bash is a command language interpreter. It is widely available on various operating systems and is the default shell on Linux and macOS. It is also available on Windows as part of the Windows Subsystem for Linux (WSL).

## We are going through some basic scrypt parts

### Shebang

The shebang is the first line of a script that tells the system which interpreter to use to run the script.  
It starts with `#!` followed by the path to the interpreter.

```bash
#!/bin/bash
```

## `set -x`

This command is used to enable debugging mode in a script. When this command is used, the shell will print each command before executing it.

```terminal
$ ./hello.sh 
+ str=' from hla'
+ printf 'Hello, Bash! %s\n' ' from hla'
Hello, Bash!  from hla
+ read -rp 'Enter your name: ' name
Enter your name: mnna
```

## `set -e`

This command is used to exit the script immediately if any command returns a non-zero exit status.

## "Double quote to prevent globbing and word splitting"

When you use double quotes around a variable, the value of the variable is preserved. This is useful when you want to prevent globbing and word splitting.

## Understanding Variable Expansion and Command Substitution in Bash

In the provided Bash script, there are two main concepts being demonstrated: variable expansion and command substitution.

1. **Variable Expansion**: In Bash, variables are expanded when they are preceded by a dollar sign `$`. If the variable is enclosed in double quotes `"`, the value is preserved as a single string. If it's not enclosed in quotes, the value is split into separate words.

    ```bash
    name="hal rda"
    if [$name = "hal rda"]; then
        echo "yes"
    else
        echo "no"
    fi
    ```

note that in this scanario the script will fail with an warning too many arguments because the variable is not enclosed in double quotes.
    ```terminal
    + name='hal rda'
    + '[' hal rda = 'hal rda' ']'
    ./hello.sh: line 15: [: too many arguments
    + echo 'no'
    no
    ```

To fix this, you can enclose the variable in double quotes to preserve the value as a single string.
    ```bash
    name="hal rda"
    if ["$name" = "hal rda"]; then
        echo "yes"
    else
        echo "no"
    fi
    ```

1. **Command Substitution**: In Bash, command substitution is done by enclosing the command with `$(...)`. The command inside the parentheses is executed and the output is used in place.

    ```bash
    cmd=$(ls )
    echo "$cmd"
    ```
  
## Here Document in Bash

A here document is a way to pass multiple lines of input to a command or script. It is defined by `<<` followed by a delimiter (often `EOF` or `END`) at the beginning and the same delimiter at the end. The text between the delimiters is treated as input.

```terminal
$ ./hello.sh << m7md
> gg
> 37
> m7md
```

or input for a command

```bash
cat << EOF > file.txt
This is line 1
This is line 2
EOF
cat file.txt
```

```bash
sort << EOF
lilo
hla
ahmd
EOF
```

## if and Test

before writing any cmd it's better to to check the syntax using `man test` or `man [`

```bash
if [ -f "file.txt" ]; then
    echo "File exists"
else
    echo "File does not exist"
fi

if [ -f "file.txt" ] && [ -r "file.txt" ]; then
    echo "File exists and is readable"
else
    echo "File either does not exist or is not readable"
fi

test -f "file.txt" && echo "File exists" || echo "File does not exist"

[-f "file.txt" ] && echo "File exists" || echo "File does not exist"
```

## Loops in Bash

### For Loop

```bash
for i in 1 2 3 4 5; do
    echo "Number: $i"
done
```

```bash
for i in {1..5}; do
    echo "$i"
done
```

```bash
str="this is a string"
for i in $str; do
    echo "$i"
```

```bash
x=$(ls)
echo "ls output:"
for i in $x; do
    echo "$i"
done
```

## while - until

```bash
i=0
y=5
while [[ $i -lt $y ]]; do
    echo "$i"
    ((i++))
done
```

```bash
i=0
y=5
until [[ $i -ge $y ]]; do
    echo "$i"
    ((i++))
done
```

## Arithmetic Expansion

addition, subtraction, multiplication, exponentiation and division

```bash
result=$((5 + 3))
((result++))
((result+=5))
```

## Arguments

```bash
echo "$0"
echo "$1"
echo "$2"
echo "$3"
echo "number of arguments:  $#"
echo "Arguments array:  $@"
echo "Arguments string: $*"
```
