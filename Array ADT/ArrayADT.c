#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  17-01-2022
    Language: C
    Content: Array ADT
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


void display_array(struct Array arr)
{
    printf("Printing all array elements(%d) : \n", arr.length);
    for(int i=0; i<arr.length; i++)
        printf("\t%d", arr.A[i]);
}


int main()
{
    printf("\t***** An Example of Array ADT *****\n\n");

    struct Array arr = {{10, 20, 30, 40, 50}, 20, 5};

    display_array(arr);

    return 0;
}
