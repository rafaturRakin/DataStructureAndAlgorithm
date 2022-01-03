#include<stdio.h>

/*
    Author: Rakin
    Date:  03-01-2022
    Language: C
    Content: Indirect Recursion
*/

void functionA(int number)
{
    if(number > 0)
    {
        printf("From Function A : %d\n", number);
        functionB(number-1);
    }
}

void functionB(int number)
{
    if(number > 0)
    {
        printf("From Function B : %d\n", number);
        functionA(number / 2);
    }
}

int main()
{
    printf("\t***** An Example of Recursive Function *****\n\n");

    functionA(20);

    return 0;
}
