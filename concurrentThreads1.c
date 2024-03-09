#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int j = 0;

void *thread_func(void *arg){

    j++;

    printf("j is %d\n", j);
    pthread_exit(0);
}

int main(int argc, char *argv[]){
      pthread_t p1, p2;
      pthread_create(&p1, NULL, thread_func, NULL);
      pthread_create(&p2, NULL, thread_func, NULL);
      pthread_join(p1, NULL);
      pthread_join(p2, NULL);
}
