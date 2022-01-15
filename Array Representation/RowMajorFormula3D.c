#include<stdio.h>

/*
    Author: Rakin
    Date:  15-01-2022
    Language: C
    Content: Row Major Formula for 3D Arrays
*/

int main()
{
    printf("\t***** An Example of Row major formula for 3D Arrays s*****\n\n");

    int array[3][4][5];
    int *base, *address, m, n, p, i, j, k, weight;

    printf("Address of array[0][0][3] = %u\n", &array[0][0][3]);

    m = 3;
    n = 4;
    p = 5;

    i = 0;
    j = 0;
    k = 3;

    weight = 1;
    base = (int*) array;

    address = base + (i * m * n + j * n + k) * weight;
    printf("\nUsing row major formula address of array[0][0][3] = %u\n", address);

    return 0;
}

/**
This program contains some bug in memory calculation...
**/

