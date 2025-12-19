#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    pid_t pid;

    pid = fork();
    printf("List down the Content\n");

    if(pid < 0){
        printf("Fork Failed\n");
        return 1;

    }

    else if(pid == 0){
        execlp("ls", "ls", NULL);
        execl("/bin/ls","ls","-l", NULL);
        execl("/bin/pwd","pwd", NULL);
    }
    else{
        wait(NULL);
        printf("Child Complete\n");
    }
    return 0;
}