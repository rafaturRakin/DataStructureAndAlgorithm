#include<stdio.h>

/*
    Author: Rakin
    Date:  03-01-2022
    Language: C
    Content: Indirect Recursion
*/


int nestedRecursion(int number)
{
    if(number > 100)
    {
        printf("If Block -> Number : %d\tReturned : %d\n", number, number - 10);
        return number - 10;
    }
    else
    {
        printf("Else Block -> Number : %d\tPassed : %d\n", number, number + 11);
        return nestedRecursion(nestedRecursion(number + 11));
    }
}


int main()
{
    int result;
    printf("\t***** An Example of Recursive Function *****\n\n");

    result = nestedRecursion(95);

    printf("\nResult of the nested recursion is = %d\n", result);

    return 0;
}
