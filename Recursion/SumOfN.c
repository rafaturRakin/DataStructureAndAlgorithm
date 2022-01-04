#include<stdio.h>

/*
    Author: Rakin
    Date:  04-01-2022
    Language: C
    Content: Sum of first N numbers
*/

int recursive_sum(int number)
{
    if(number==0)
        return 0;
    return recursive_sum(number - 1) + number;
}


int iterative_sum(int number)
{
    int i, result = 0;
    for(i=1; i<=number; i++)
        result += i;
    return result;
}


int formulated_sum(int number)
{
    return number * (number + 1) / 2;
}


int main()
{
    printf("\t***** An Example of Sum of first N numbers*****\n\n");

    printf("Sum of first 5 numbers using recursion is = %d\n", recursive_sum(5));
    printf("Sum of first 6 numbers using iteration is = %d\n", iterative_sum(6));
    printf("Sum of first 7 numbers using formula is = %d\n", formulated_sum(7));

    return 0;
}

