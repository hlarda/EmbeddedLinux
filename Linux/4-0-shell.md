# SELL

## Difference between zimage, uimage and   vimlinux

`zImage`, `uImage`, and `vmlinux` are all different types of Linux kernel images.

- **zImage**:
  - This is a compressed version of the Linux kernel image that is self-extracting.
  - `zImage` was used in older systems due to its small size (under 512KB).
  - When the system boots, the bootloader loads the `zImage` into memory, and then `zImage` decompresses itself.

- **uImage**:
  - This is a format used by U-Boot (a popular bootloader used in embedded systems).
  - `uImage` contains not only the Linux kernel image (which can be a `zImage` or `bzImage`), but also metadata about the image, such as its type (OS, filesystem, etc.), its load address, and its entry point.
  - This additional information allows U-Boot to be more flexible and powerful.

- **vmlinux**:
  - This is the uncompressed version of the Linux kernel image.
  - It's useful for debugging and development, but it's not typically used for booting a system because its size is much larger than the compressed images.

In summary, `zImage` and `uImage` are both compressed kernel images used for booting a system, with `uImage` being used specifically with the U-Boot bootloader and containing additional metadata. `vmlinux` is an uncompressed image used mainly for debugging and development.

## fork()

`fork()` is a system call that creates a new process by duplicating the calling process.
The new process is called the child process, and the calling process is called the parent process.
The child process is an exact copy of the parent process, except for a few differences:

- The child process has a new process ID (PID).
- The child process has a new parent process ID (PPID) which is the PID of the parent process.
- The child process has its own copy of the parent's file descriptors.
- The child process has its own copy of the parent's memory space (copy-on-write).
- The child process returns 0 from `fork()`, while the parent process returns the PID of the child process.

## execve()

system call is used to execute a program in a new process.

It replaces the current process image with a new process image specified by the path to the executable file.

The `execve()` system call has the following signature:

```c
int execve( char *filename, char *const argv[], char *const envp[]);
```

## built-in shell commands and user-defined shell scripts

- **Built-in shell commands** are commands that are part of the shell itself and are executed directly by the shell without invoking an external program as if u typed a function within the shell's code do all work with the needs to bin files. Examples of built-in shell commands include `cd`, `echo`, `exit`, `pwd`, and `export`.

```bash
$ help
GNU bash, version 5.1.16(1)-release (x86_64-pc-linux-gnu)
These shell commands are defined internally.  Type `help' to see this list.
Type `help name' to find out more about the function `name'.
Use `info bash' to find out more about the shell in general.
Use `man -k' or `info' to find out more about commands not in this list.

A star (*) next to a name means that the command is disabled.

 job_spec [&]                                 history [-c] [-d offset] [n] or history ->
 (( expression ))                             if COMMANDS; then COMMANDS; [ elif COMMAN>
 . filename [arguments]                       jobs [-lnprs] [jobspec ...] or jobs -x co>
 :                                            kill [-s sigspec | -n signum | -sigspec] >
 [ arg... ]                                   let arg [arg ...]
 [[ expression ]]                             local [option] name[=value] ...
 alias [-p] [name[=value] ... ]               logout [n]
 bg [job_spec ...]                            mapfile [-d delim] [-n count] [-O origin]>
 bind [-lpsvPSVX] [-m keymap] [-f filename]>  popd [-n] [+N | -N]
 break [n]                                    printf [-v var] format [arguments]
 builtin [shell-builtin [arg ...]]            pushd [-n] [+N | -N | dir]
 caller [expr]                                pwd [-LP]
 case WORD in [PATTERN [| PATTERN]...) COMM>  read [-ers] [-a array] [-d delim] [-i tex>
 cd [-L|[-P [-e]] [-@]] [dir]                 readarray [-d delim] [-n count] [-O origi>
 command [-pVv] command [arg ...]             readonly [-aAf] [name[=value] ...] or rea>
 compgen [-abcdefgjksuv] [-o option] [-A ac>  return [n]
 complete [-abcdefgjksuv] [-pr] [-DEI] [-o >  select NAME [in WORDS ... ;] do COMMANDS;>
 compopt [-o|+o option] [-DEI] [name ...]     set [-abefhkmnptuvxBCHP] [-o option-name]>
 continue [n]                                 shift [n]
 coproc [NAME] command [redirections]         shopt [-pqsu] [-o] [optname ...]
 declare [-aAfFgiIlnrtux] [-p] [name[=value>  source filename [arguments]
 dirs [-clpv] [+N] [-N]                       suspend [-f]
 disown [-h] [-ar] [jobspec ... | pid ...]    test [expr]
 echo [-neE] [arg ...]                        time [-p] pipeline
 enable [-a] [-dnps] [-f filename] [name ..>  times
 eval [arg ...]                               trap [-lp] [[arg] signal_spec ...]
 exec [-cl] [-a name] [command [argument ..>  true
 exit [n]                                     type [-afptP] name [name ...]
 export [-fn] [name[=value] ...] or export >  typeset [-aAfFgiIlnrtux] [-p] name[=value>
 false                                        ulimit [-SHabcdefiklmnpqrstuvxPT] [limit]
 fc [-e ename] [-lnr] [first] [last] or fc >  umask [-p] [-S] [mode]
 fg [job_spec]                                unalias [-a] name [name ...]
 for NAME [in WORDS ... ] ; do COMMANDS; do>  unset [-f] [-v] [-n] [name ...]
 for (( exp1; exp2; exp3 )); do COMMANDS; d>  until COMMANDS; do COMMANDS; done
 function name { COMMANDS ; } or name () { >  variables - Names and meanings of some sh>
 getopts optstring name [arg ...]             wait [-fn] [-p var] [id ...]
 hash [-lr] [-p pathname] [-dt] [name ...]    while COMMANDS; do COMMANDS; done
 help [-dms] [pattern ...]                    { COMMANDS ; }

$ type cd 
cd is a shell builtin

$ type time
time is a shell keyword

$ type btrfs
btrfs is /usr/bin/btrfs
```
