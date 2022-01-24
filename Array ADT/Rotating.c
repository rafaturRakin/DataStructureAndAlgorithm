#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  24-01-2022
    Language: C
    Content: Array elements rotating
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


void left_rotate(struct Array *arr)
{
    int temp = arr->A[0];
    for(int i=0; i<arr->length-1; i++)
        arr->A[i] = arr->A[i+1];
    arr->A[arr->length-1] = temp;
}


void right_rotate(struct Array *arr)
{
    int temp = arr->A[arr->length-1];
    for(int i=arr->length-1; i>0; i--)
        arr->A[i] = arr->A[i-1];
    arr->A[0] = temp;
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
    printf("\t***** An Example of Array elements rotating *****\n\n");

    struct Array arr = {{10, 20, 30, 40, 50}, 20, 5};

    display_array(arr);

    printf("After rotating elements on left 2 times-> \n");
    left_rotate(&arr);
    left_rotate(&arr);
    display_array(arr);

    printf("After rotating elements on right 1 times -> \n");
    right_rotate(&arr);
    display_array(arr);

    return 0;
}
