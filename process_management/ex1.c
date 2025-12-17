#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    printf("Process ID: %d\n", getpid());
    char *args[] = {"Hello", "Minoka", "Induwara", NULL};
    execv("./ex2", args);
    return 0;
}