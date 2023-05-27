#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>


int main()
 {
pid_t pid;
// fork a child process
    pid = fork();
    int number = 14;

    // error occured
    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    // child process 1
    else if (pid == 0) {
        printf("From child1, pid=%d, init: number=%d\n", getpid(), number);
        execlp("/bin/ls", "ls", NULL);
    }
    //parent process
    else {
        //wait(NULL);
        //sleep(2);
        printf("Child Complete\n");
    }

    return 0;
}