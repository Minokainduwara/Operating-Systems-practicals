#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* routine(){
    
    printf("Testing threads\n");
    printf("Thread ID: %lu\n", pthread_self());
    sleep(10);
    printf("Exiting thread\n");
    printf("Thread ID: %lu\n", pthread_self());
    
}
int main(int argc, char *argv[]){
    pthread_t t1, t2;
    if(pthread_create(&t1, NULL, &routine, NULL) != 0){
        printf("Error creating thread\n");
        return 1;
    }

    if(pthread_create(&t2, NULL, &routine, NULL)  != 0){
        printf("Error creating thread\n");
        return 2;
    }
    if(pthread_join(t1, NULL) != 0){
        printf("Error joining thread\n");
        return 3;
    }
    if(pthread_join(t2, NULL) != 0){
        printf("Error joining thread\n");
        return 3;
    }
    return 0;

}