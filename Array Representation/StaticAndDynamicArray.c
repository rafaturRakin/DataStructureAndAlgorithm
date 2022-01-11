#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  11-01-2022
    Language: C
    Content: Static and Dynamic Array
*/

void static_array()
{
    int array[5] = {1, 2, 3, 4, 5};

    printf("Printing Static Array : \n");
    for(int i=0; i<5; i++)
        printf("\tarray[%d] : %d\n", i, array[i]);
}


void dynamic_array()
{
    int *p;
    p = (int *) malloc(sizeof(int) * 5);

    p[0] = 10;
    p[1] = 20;
    p[2] = 30;
    p[3] = 40;
    p[4] = 50;

    printf("\nPrinting Dynamic Array:\n");
    for(int i=0; i<5; i++)
        printf("\tp[%d] : %d\n", i, p[i]);
}

int main()
{
    printf("\t***** An Example of Static and Dynamic Array *****\n\n");

    static_array();

    dynamic_array();

    return 0;
}
