#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>

/**/
int main(int argc, char const *argv[]){
    char input[100];
    while (1){
        printf("$");
        fgets(input, 100, stdin);
        if(input[0]=='\n'){
            continue;
        }
        input[strcspn(input,"\n")] = '\0';

        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0){
            printf("bye ysta!\n");
            exit(EXIT_SUCCESS);
            break;
        }
        
        pid_t childPID = fork();
        if(childPID == -1){
            perror("fork() failed");
            exit(EXIT_FAILURE);
        }else if (childPID == 0){
            char *args[10];
            char *token = strtok(input, " ");
            int i = 0;

            while (token != NULL){
                args[i] = token;
                token = strtok(NULL, " ");
                i++;
            }
            args[i] = NULL;

            if(strcmp(args[0], "cd") == 0){
                if (args[1] == NULL) {
                    fprintf(stderr, "cd: expected argument to \"cd\"\n");
                } else if (chdir(args[1]) != 0) {
                perror("cd failed");
                }
            }else {  
                execvp(args[0], args);
                perror("only printed if execvp() fails");
                exit(EXIT_FAILURE);
            }
        }else{
            int status;
            waitpid(childPID, &status, 0);
        }
    }
    return 0;
}