# Redirection, Piping, and Wildcards

## Redirection

any workind process has three standard file descriptors:

1. stdin (0)
2. stdout (1)
3. stderr (2)

Redirection is the process of changing the standard file descriptors. The following are the redirection operators:

1. `>`: Redirects stdout to a file. If the file does not exist, it is created. If the file exists, it is overwritten.
2. `>>`: Redirects stdout to a file. If the file does not exist, it is created. If the file exists, the output is appended to the file.
3. `<`: Redirects stdin from a file.
4. `2>`: Redirects stderr to a file. If the file does not exist, it is created. If the file exists, it is overwritten.
5. `2>>`: Redirects stderr to a file. If the file does not exist, it is created. If the file exists, the output is appended to the file.
6. `&>`: Redirects stdout and stderr to a file. If the file does not exist, it is created. If the file exists, it is overwritten.
7. `&>>`: Redirects stdout and stderr to a file. If the file does not exist, it is created. If the file exists, the output is appended to the file.

```bash
$ sleep 1000 &
[2] 11906
$ ls /proc/11906/fd -l
total 0
lrwx------ 1 hala hala 64 May 13 02:54 0 -> /dev/pts/0
lrwx------ 1 hala hala 64 May 13 02:54 1 -> /dev/pts/0
lrwx------ 1 hala hala 64 May 13 02:54 2 -> /dev/pts/0

$ sleep 1000 &> outerr &
[1] 10710
$ ls /proc/10710/fd -l
total 0
lrwx------ 1 hala hala 64 May 13 02:51 0 -> /dev/pts/0
l-wx------ 1 hala hala 64 May 13 02:51 1 -> /home/hala/Documents/trash/outerr
l-wx------ 1 hala hala 64 May 13 02:51 2 -> /home/hala/Documents/trash/outerr
```

## Piping

Piping is the process of connecting the stdout of one command to the stdin of another command. The pipe operator is `|`.

## Wildcards and regex

[Quiz Link](https://regex101.com/quiz/3)

1. match `word` insensitively
`.`: any character
`*`: zero or more of the preceding character
`\b` : word boundary
`i` : case insensitive

   ```regex
   .*\b[Ww][Oo][Rr][Dd]\b.*
   \bword\b/i
   ```

2. Use substitution to replace every occurrence of the word `i` with the word `I`. E.g.: i'm replacing it. am i not? -> I'm replacing it. am I not?.
`g` modifier: global. All matches (don't return after first match)

   ```regex
    .*\b[Ww][Oo][Rr][Dd]\b.*
    \bword\b/g
    ```

3. With regex you can count the number of matches. Can you make it return the number of uppercase consonants (B,C,D,F,..,X,Y,Z) in a given string? E.g.: it should return 3 with the text ABcDeFO!. Note: Only ASCII. We consider Y to be a consonant!

   ```regex
   [BCDFGHJKLMNPQRSTVWXYZ]
   [B-DF-HJ-NP-TV-Z]
   ```

4. Count the number of integers in a given string. Integers are, for example: 1, 2, 65, 2579, etc.

    ```regex
    \d+
    ```

5. Find all occurrences of 4 or more whitespace characters in a row throughout the string.

    ```regex
    \s{4,}
    ```

