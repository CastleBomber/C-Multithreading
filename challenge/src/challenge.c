#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char *secret;
pthread_mutex_t secret_mutex_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t secret_created_cond = PTHREAD_COND_INITIALIZER;
int msg_initialized = 0;

void *setSecretAndSignal(void *tid){
    secret = "secret stuff";
    printf("%s\n", secret);
}

void *setMutexAndWait(void *tid){
    //pthread_mutex_lock(&secret_mutex_lock);
    //pthread_cond_wait(&secret_created_cond, &secret_mutex_lock);
    printf("Second function\n");
}


int main(){
    pthread_t threadAlpha, threadBeta;
    pthread_create(&threadAlpha, NULL, setSecretAndSignal, (void *)&threadAlpha);
    pthread_create(&threadBeta, NULL, setSecretAndSignal, (void *)&threadBeta);
    
    pthread_exit(NULL);

    printf("yups\n");
    
    return 0;
}