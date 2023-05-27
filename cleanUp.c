#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
 {
    int i=0;
    pid_t pid1, pid2;
    extern char *optarg;
	extern int optind;
	int err = 0; 
    int userInput = 0;
    int numberChild2 = 0;;
    int n = 0; 

	if (optind < argc)	/* these are the arguments after the command-line options */
		for (; optind < argc; optind++)	//work through the command line options
			userInput = atoi(argv[optind]); // print command line option

            // Project parameters call for a user entered integer between 1 and 39
            if (userInput <= 0 || userInput >= 40) {
                printf("Please enter a number between 1 and 39.\n");
                exit(0);
            }

    printf("\ncollatz%d\n", userInput);
    printf("\n");


    // fork a child process
    pid1 = fork();

    // error occured
    if (pid1 < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    // child process 1
    else if (pid1 == 0) {
        printf("From child1, pid=%d, init: number=%d\n", getpid(), userInput);
        n = userInput;

        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
                printf("From child1: number = %d\n", n);
            } else {
                n = 3 * n + 1;
                 printf("From child1: number = %d\n", n);
            }
        }
        printf("From child1, pid=%d I'm done!\n", getpid());
    }
    // child process 2
    else  {
        pid2 = fork();
        if (pid1 < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    } else if (pid2 == 0) {
        numberChild2 = userInput + 4;
        printf("From child2, pid=%d, init: number=%d\n", getpid(), numberChild2);

         while (numberChild2 > 1) {
            if (numberChild2 % 2 == 0) {
                numberChild2 = numberChild2 / 2;
                printf("From child2: number = %d\n", numberChild2);
            } else {
                numberChild2 = 3 * numberChild2 + 1;
                 printf("From child2: number = %d\n", numberChild2);
            }
        }
        printf("From child2, pid=%d I'm done!\n", getpid());

    }
    //parent process
    else {
        wait(NULL);
        wait(NULL);
        printf("All my children Complete\n");
    }
}

    return 0;
 }