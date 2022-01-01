#include<stdio.h>

/*
    Author: Rakin
    Date:  01-01-2022
    Language: C
    Content: Tail Recursion
*/


void tail_recursion(int number)
{
    if(number > 0)
    {
        printf("Current number is : %d\n", number);
        tail_recursion(number - 1);
    }
}


int main()
{
    printf("\t***** An Example of Tail Recursion *****\n\n");

    tail_recursion(5);

    return 0;
}

