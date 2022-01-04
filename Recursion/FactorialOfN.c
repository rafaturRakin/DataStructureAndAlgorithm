#include<stdio.h>

/*
    Author: Rakin
    Date:  04-01-2022
    Language: C
    Content: Factorial of N
*/


int recursive_factorial(int number)
{
    if(number == 0)
        return 1;
    return recursive_factorial(number - 1) * number;
}


int iterative_factorial(int number)
{
    int i, factorial = 1;
    for(i=1; i<=number; i++)
        factorial *= i;
    return factorial;
}


int main()
{
    printf("\t***** An Example of Factorial of first N numbers *****\n\n");

    printf("Factorial of 5 using recursion = %d\n", recursive_factorial(5));
    printf("Factorial of 6 using iteration = %d\n", iterative_factorial(6));

    return 0;
}


