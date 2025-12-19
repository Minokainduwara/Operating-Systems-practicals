#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 50

char msg1[] = "Hello World#1";
char msg2[] = "Hello World#2";
char msg3[] = "Hello World#3";

int main() {
    char inbuf[SIZE];
    int fd[2], pid, nbytes;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid > 0) {   // Parent
        close(fd[0]);

        write(fd[1], msg1, strlen(msg1) + 1);
        write(fd[1], msg2, strlen(msg2) + 1);
        write(fd[1], msg3, strlen(msg3) + 1);

        close(fd[1]);
        wait(NULL);
    }
    else {           // Child
        close(fd[1]);

        while ((nbytes = read(fd[0], inbuf, SIZE - 1)) > 0) {
            inbuf[nbytes] = '\0';
            printf("Child read: %s\n", inbuf);
        }

        close(fd[0]);
    }

    return 0;
}
