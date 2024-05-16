# Compression, Grep

## Compression

### using tar and gzip

`c`  stands for create archive
`z`  stands for compress archive using gzip
`v`  stands for verbose, i.e., show progress in the terminal
`f`  allows to specify the name of the archive

```bash
# compress
$ tar -czvf archive.tar file1 file2 file3
# list
tar -tvf archive.tar
# extract
tar -xvf archive.tar
```

### archiving is not compressing

The statement "archiving is not compressing" refers to the distinction between two different operations that are often used in managing files:

1. **Archiving**: This is the process of collecting multiple files and directories into a single file. An archive can contain many files, directories, and subdirectories, usually preserving the relative relationships and attributes of the files. It's a way to bundle files together. The `tar` command in Unix-based systems (like Linux) is commonly used for this purpose.

2. **Compressing**: This is the process of reducing the size of files to save storage space or speed up file transfer. Compression uses algorithms to shrink the size of files. Tools like `gzip`, `bzip2`, or `zip` are used for this purpose in Unix-based systems.

So, while these two operations are often used together (for example, a `.tar.gz` file is a `tar` archive that has been compressed with `gzip`), they are not the same thing. An archive doesn't reduce the size of the files, it just bundles them together. Compression, on the other hand, actually makes files smaller.

**The following function wrote in .bashrc_aliases file to extract any compressed file** regardless of the compression algorithm used.

```bash
function extract() {
    if [ -f "$1" ]; then
        case "$1" in
            *.tar.bz2)   tar xvjf "$1"    ;;
            *.tar.gz)    tar xvzf "$1"    ;;
            *.tar.xz)    tar xvJf "$1"    ;;
            *.lzma)      unlzma "$1"      ;;
            *.bz2)       bunzip2 "$1"     ;;
            *.rar)       unrar x "$1"     ;;
            *.gz)        gunzip "$1"      ;;
            *.tar)       tar xvf "$1"     ;;
            *.tbz2)      tar xvjf "$1"    ;;
            *.tgz)       tar xvzf "$1"    ;;
            *.zip)       unzip "$1"       ;;
            *.xz)        unxz "$1"        ;;
            *.7z)        7z x "$1"        ;;
            *.Z)         uncompress "$1"  ;;
            *.arj)       unarj "$1"       ;;
            *)           echo "don't know how to extract '$1'" ;;
        esac
    else
        echo "'$1' is not a valid file!"
    fi
}
```

## Grep

### some options

- `-i` : case insensitive
- `-v` : invert match
- `-n` : show line number
- `-c` : count
- `-r` : recursive
- `-l` : show only the file names
- `-w` : match whole word
- `-A` : after
- `-B` : before
- `E` : extended regex

ex: `$ man tar | grep -En "^( {7,})\-a" -C 2`

## sed (lsa 3yza a3rfo)

`sed` is a stream editor that is used to perform basic text transformations on an input stream (a file or input from a pipeline). It is a powerful tool for editing text files, especially when used in combination with other commands like `grep`, `awk`, and `sort`.

```bash
# replace
$ sed 's/hala/hla/' file.txt > newfile.txt
$ sed -i 's/hala/hla/2g' file.txt
# delete
$ sed '/hala/d' file.txt
# insert
$ sed '2i\new line' file.txt
# append
$ sed '2a\new line' file.txt
# print
$ sed -n '2p' file.txt
