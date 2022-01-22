#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  22-01-2022
    Language: C
    Content: Array Reversing
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void reverse_method1(struct Array *arr)
{
    int *B;

    B=(int *) malloc(arr->length * sizeof(int));

    for(int i=arr->length-1, j=0; i>=0; i--, j++)
        B[j] = arr->A[i];

    for(int i=0; i<arr->length; i++)
        arr->A[i] = B[i];
}


void reverse_method2(struct Array *arr)
{
    for(int i=0, j=arr->length-1; i<j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
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
    printf("\t***** An Example of Array Reversing *****\n\n");

    struct Array arr = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};

    display_array(arr);

    printf("\nApplying Method #1:\n");
    reverse_method1(&arr);
    display_array(arr);

    printf("\nApplying Method #2:\n");
    reverse_method2(&arr);
    display_array(arr);

    return 0;
}
