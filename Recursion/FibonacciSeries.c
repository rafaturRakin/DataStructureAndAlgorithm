#include<stdio.h>

/*
    Author: Rakin
    Date:  07-01-2022
    Language: C
    Content: Fibonacci Series
*/

int globalFibonacci[15];

int recursive_fibonacci(int term)
{
    if(term<=1)
        return term;
    return recursive_fibonacci(term - 2) + recursive_fibonacci(term - 1);
}


int iterative_fibonacci(int term)
{
    int first = 0, second = 1, fibonacci = term;
    for(int i=2; i<=term; i++)
    {
        fibonacci = first + second;
        first = second;
        second = fibonacci;
    }
    return fibonacci;
}


int memoization_fibonacci(int term)
{
    if(term<=1)
        return globalFibonacci[term] = term;

    if(globalFibonacci[term - 2] == -1)
        globalFibonacci[term - 2] = memoization_fibonacci(term - 2);
    if(globalFibonacci[term - 1] == -1)
        globalFibonacci[term - 1] = memoization_fibonacci(term - 1);

    globalFibonacci[term] = globalFibonacci[term - 2] + globalFibonacci[term - 1];
    return globalFibonacci[term];
}

int main()
{
    printf("\t***** An Example of Fibonacci Series *****\n\n");

    for(int i=0; i<20; i++)
        globalFibonacci[i] = -1;

    printf("6th Fibonacci number using iterative method = %d\n", iterative_fibonacci(6));
    printf("10th Fibonacci number using recursive method = %d\n", recursive_fibonacci(10));
    printf("12th Fibonacci number using memoization method = %d\n", memoization_fibonacci(12));

    return 0;
}
