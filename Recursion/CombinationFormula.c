#include<stdio.h>

/*
    Author: Rakin
    Date:  08-01-2022
    Language: C
    Content: Combination Formula
*/


int recursive_ncr(int n, int r)
{
    if(r==0 || n==r)
        return 1;
    return recursive_ncr(n-1, r-1) + recursive_ncr(n-1, r);
}


int main()
{
    printf("\t***** An Example of Combination Formula *****\n\n");

    printf("C(5, 2) = %d\n", recursive_ncr(5, 2));

    return 0;
}
