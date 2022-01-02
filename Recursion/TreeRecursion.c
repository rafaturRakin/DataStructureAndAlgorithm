#include<stdio.h>

/*
    Author: Rakin
    Date:  02-01-2022
    Language: C
    Content: Recursive Function
*/


void tree_recursion(int number)
{
    if(number > 0)
    {
        printf("Current number is : %d\n", number);
        tree_recursion(number - 1);
        tree_recursion(number - 1);
    }
}


int main()
{
    printf("\t***** An Example of Tree Recursion *****\n\n");

    tree_recursion(4);

    return 0;
}

