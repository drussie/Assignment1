#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int debug = 0;

int main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int err = 0; 
    int userInput = 0;
	static char usage[] = "usage: %s yourfirstname\n";

	if (optind < argc)	/* these are the arguments after the command-line options */
		for (; optind < argc; optind++)	//work through the command line options
			userInput = atoi(argv[optind]); // print command line option
            printf("Inside if: %d\n", userInput);
	//exit(0);

    printf("Outside if: %d\n", userInput);

    return 0;
}