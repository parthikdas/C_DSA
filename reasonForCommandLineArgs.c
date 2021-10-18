#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) // argc - argument count(number of command line arguments), argv - argument vector(stores tje arguments where 0th index is file name and from 1st index data is stored)
//in argv, data is stored as ascii values 
{
    int a;
    /*
        if(arc==1) printf("You forgot");exit(1);
    */
    if(argc>1) a = atoi(argv[1]); // if there is command line args then take it else take input
    else scanf("%d",&a);
    printf("%d",a);
    return 0;
}
