#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>

/*
To prove it's not like fork(), the output is not just two processes with the same command.
Instead, one process continues with the original command, and the other runs the new program image specified in execve().
* $ ps -o ppid,pid,cmd |grep exeProg 
  12478   14181 ./exeProg
  12478   14505 grep --color=auto exeProg
* $ ps -o ppid,pid,cmd |grep sleep
  14181   14183 [sleep] <defunct>
  12478   14532 grep --color=auto sleep
*/
int main(int argc, char const *argv[]){
    char *cmd = "/bin/sleep";
    char *args[] = {cmd, "10", NULL};
    char *env[] = {NULL};

    pid_t childPID = fork();
    if(childPID == 0){
        printf("Child process   PID=%d  PPID=%d\n",getpid(),getppid());
        execve(cmd, args, env);
        perror("only printed if execve() fails");
        exit(EXIT_FAILURE);
    }else{
        int status;
        printf("Parent process   PID=%d  PPID=%d\n",getpid(),getppid());
        //* The parent process will be blocked until the child process with this PID terminates.
        waitpid(childPID, &status, 0);
        printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    return 0;
}
