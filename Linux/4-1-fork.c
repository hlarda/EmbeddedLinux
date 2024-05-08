#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>

/*
both processes continue with the same command but have different PIDs.
    * $./forkProg &
    [1] 15438
    Parent process   PID=15438  PPID=15261
    Child process   PID=15440  PPID=15438

    * $ ps -o ppid,pid,cmd | grep forkProg 
    15261   15438 ./forkProg
    15438   15440 ./forkProg
    15261   15843 grep --color=auto forkProg
*/
int main(int argc, char const *argv[]){
    pid_t pid;
    pid_t child_pid = fork();
    if(child_pid == 0){
        printf("Child process   PID=%d  PPID=%d\n",getpid(),getppid());
        while (1);
    }else{
        printf("Parent process   PID=%d  PPID=%d\n",getpid(),getppid());
        while (1);
    }
    return 0;
}
