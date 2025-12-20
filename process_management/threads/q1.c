#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define SIZE 2

void *thread1(){
    int num;
    for(num = 2; num <= 101; num += 2){
        printf("child thread %ld : %d\n",pthread_self(), num);
    }
}

int main(){
    pthread_t tid1[SIZE]; //Create variables for threadid
    int n;
    printf("Enter an integer(n) : ");
    scanf("%d", &n); 
    
    for(int i = 0; i < SIZE; i++){
        //Create child thread
        pthread_create(&tid1[i], NULL, thread1, NULL);
    }

    for(int i = 0; i <= n; i++){
        printf("Main thread %ld : %d\n", pthread_self(), i);
    }
    for(int i = 0; i < SIZE; i++){
        pthread_join(tid1[i], NULL); //wait for child thread to finish
    }
    return 0;
}