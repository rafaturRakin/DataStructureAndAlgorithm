#include<stdio.h>

/*
    Author: Rakin
    Date:  01-01-2022
    Language: C
    Content: Head Recursion
*/


void head_recursion(int number)
{
    if(number > 0)
    {
        head_recursion(number - 1);
        printf("Current number is : %d\n", number);
    }
}


int main()
{
    printf("\t***** An Example of Head Recursion *****\n\n");

    head_recursion(5);

    return 0;
}
