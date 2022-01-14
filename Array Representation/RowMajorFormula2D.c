#include<stdio.h>

/*
    Author: Rakin
    Date:  14-01-2022
    Language: C
    Content: Row Major Formula for 2D Arrays
*/

int main()
{
    printf("\t***** An Example of Row major formula for 2D Arrays s*****\n\n");

    int array[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {10, 30, 50, 70}};
    int *base, *address, row, column, i, j, weight;

    printf("Content of array[2][3] = %d\n", array[2][3]);
    printf("Address of array[2][3] = %u\n", &array[2][3]);

    row = 3;
    column = 4;
    i = 2;
    j = 3;
    weight = 1;
    base = (int*) array;

    address = (base + ( (i * column) + j) * weight);
    printf("\nUsing row major formula address of array[2][3] = %u\n", address);
    printf("Using row major formula content of array[2][3] = %d\n", *address);

    return 0;
}
