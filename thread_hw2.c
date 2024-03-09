#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>

int balance = 0;

void *mythread(void *arg) {
  int i;
  for (i = 0; i < 200; i++) {
    balance++;
  }
  printf("Balance is %d\n", balance);
  return NULL;
}

int main(int argc, char** argv) {
  pthread_t p1, p2, p3;
  printf("A");
  pthread_create(&p1, NULL, mythread, "A");
  pthread_join(p1, NULL);
  printf("B");
  pthread_create(&p2, NULL, mythread, "B");
  pthread_join(p2, NULL);
  printf("C");
  pthread_create(&p3, NULL, mythread, "C");
  pthread_join(p3, NULL);
  printf("Final Balance is %d\n", balance);


}
