 #include <stdio.h>
 #include <stdlib.h>

int main (int argc, char *argv[])
 {
    int i=0;
    int number=0;

    printf("\ncmdline args count=%d", argc);

    /* First argument is executable name only */
    printf("\nexe name=%s", argv[0]);

    /*for (i=1; i< argc; i++)
    {
       printf("\narg%d=%s", i, argv[i]);
    }
    */
   printf("\narg1=%s", argv[1]);
   //number = atoi(argv[1]);
   printf("%d", number);

    printf("\n");
    return 0;
 }
