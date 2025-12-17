#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Hello from Child Process! PID: %d\n", getpid());
    } else {
        // Parent process
        printf("Hello from Parent Process! PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}