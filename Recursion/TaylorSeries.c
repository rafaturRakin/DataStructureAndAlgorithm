#include<stdio.h>

/*
    Author: Rakin
    Date:  06-01-2022
    Language: C
    Content: Taylor Series
*/


double taylor_series(int x, int n)
{
    static double power = 1.0, factorial = 1.0;
    double result;

    if(n == 0)
        return 1.0;

    result = taylor_series(x, n-1);
    power *= x;
    factorial *= n;
    return result + (power / factorial);
}


int main()
{
    printf("\t***** An Example of Taylor Series *****\n\n");

    printf("Value of e^5 for 20 terms is = %lf\n", taylor_series(5, 20));

    return 0;
}
