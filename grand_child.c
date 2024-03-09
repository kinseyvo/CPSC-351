#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv)

{

    pid_t child_pid;
    child_pid = fork();
    sleep(3);

    if (child_pid == 0)
    {
        pid_t grand_child_pid;
        grand_child_pid = fork();
        sleep(3);
        //Homework Code
        if (grand_child_pid != 0) {
          exit(-1);
        }
        execlp("/bin/firefox", "ls", (char *) 0);

        printf("This is process %d\n", getpid());

    }


    printf("This is process %d\n", getpid());

    sleep(3);
    wait(NULL);

    return 0;
}
