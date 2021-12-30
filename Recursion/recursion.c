#include<stdio.h>

/*
    Author: Rakin
    Date:  30-12-2021
    Language: C
    Content: Recursive Function
*/


void recursive_function(int number)
{
    if(number > 0)
    {
        printf("Current number is : %d\n", number);
        recursive_function(number - 1);
    }
}


int main()
{
    printf("\t***** An Example of Recursive Function *****\n\n");

    recursive_function(5);

    return 0;
}
