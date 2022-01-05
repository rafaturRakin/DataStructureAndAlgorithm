#include<stdio.h>

/*
    Author: Rakin
    Date:  05-01-2022
    Language: C
    Content: Power of a raise to b
*/

int recursive_power(a, b)
{
    if(b == 0)
        return 1;
    if(b%2 == 0)
        return recursive_power(a*a, b/2);
    return a * recursive_power(a*a, (b-1) / 2);
}


int faster_recursive_power(a, b)
{
    if(b == 0)
        return 1;
    if(b%2 == 0)
        return faster_recursive_power(a*a, b/2);
    return a * faster_recursive_power(a*a, (b-1) / 2);
}


int main()
{
    printf("\t***** An Example of Power (a^b) *****\n\n");

    printf("Power (2, 9) = %d\n", recursive_power(2, 9));
    printf("Power (2, 10) = %d\n", faster_recursive_power(2, 10));

    return 0;
}
