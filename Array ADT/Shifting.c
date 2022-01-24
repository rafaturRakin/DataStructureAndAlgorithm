#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  24-01-2022
    Language: C
    Content: Array elements shifting
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


void left_shift(struct Array *arr)
{
    for(int i=0; i<arr->length-1; i++)
        arr->A[i] = arr->A[i+1];
    arr->A[arr->length-1] = 0;
}


void right_shift(struct Array *arr)
{
    for(int i=arr->length-1; i>0; i--)
        arr->A[i] = arr->A[i-1];
    arr->A[0] = 0;
}


void display_array(struct Array arr)
{
    printf("Printing all array elements(%d) : \n", arr.length);
    for(int i=0; i<arr.length; i++)
        printf("\t%d", arr.A[i]);
    printf("\n\n");
}


int main()
{
    printf("\t***** An Example of Array elements shifting *****\n\n");

    struct Array arr = {{10, 20, 30, 40, 50}, 20, 5};

    display_array(arr);

    printf("After shifting elements on left -> \n");
    left_shift(&arr);
    display_array(arr);

    printf("After shifting elements on right -> \n");
    right_shift(&arr);
    display_array(arr);

    return 0;
}
