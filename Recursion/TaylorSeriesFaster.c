#include<stdio.h>

/*
    Author: Rakin
    Date:  06-01-2022
    Language: C
    Content: Taylor Series Horner's Method
*/

double iterative_taylor_series(int x, int n)
{
    double result = 1.0, numerator = 1.0, denominator = 1.0;

    for(int i=1; i<=n; i++)
    {
        numerator *= x;
        denominator *= i;
        result = result + (numerator / denominator);
    }

    return result;
}


double recursive_taylor_series(int x, int n)
{
    static double result = 1.0;

    if(n==0)
        return result;

    result = 1.0 + x*result/n;

    return recursive_taylor_series(x, n-1);
}


int main()
{
    printf("\t***** An Example of Faster Taylor series*****\n\n");

    printf("Result of e^2 using iterative method for 10 terms = %lf\n", iterative_taylor_series(2, 10));
    printf("Result of e^3 using recursive method for 10 terms = %lf\n", recursive_taylor_series(3, 10));

    return 0;
}
