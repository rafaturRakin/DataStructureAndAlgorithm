#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  12-01-2022
    Language: C
    Content: Increase Array Size
*/

void increase_array()
{
    int *p = (int *) malloc(sizeof(int) * 5), *q;

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    printf("Before Increasing Size...\n");
    for(int i=0; i<5; i++)
        printf("\tp[%d] = %d\n", i, p[i]);

    q = (int *) malloc(sizeof(int) * 10);
    for(int i=0; i<5; i++)
        q[i] = p[i];

    free(p);
    p = q;
    q = NULL;

    printf("\nAfter Increasing Size...\n");
    for(int i=0; i<5; i++)
        printf("\tp[%d] = %d\n", i, p[i]);
}

int main()
{
    printf("\t***** An Example of Increasing Array Size *****\n\n");

    increase_array();
    return 0;
}
