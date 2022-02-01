#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  01-02-2022
    Language: C
    Content: ASCII Codes
*/


void display_codes()
{
    printf("Printing all ASCII Codes and Characters : \n");
    for(int i=0; i<128; i++)
        printf("\t%d \t - \t %c\n", i, i);
}


int main()
{
    printf("\t***** An Example of ASCII Codes *****\n\n");

    display_codes();

    return 0;
}

