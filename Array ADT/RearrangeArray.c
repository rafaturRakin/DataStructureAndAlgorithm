
#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  23-01-2022
    Language: C
    Content: Negatives on Left
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void rearrange_array(struct Array *arr)
{
    int i = 0, j = arr->length-1;

    while(i < j)
    {
        while(arr->A[i] < 0)
            i++;

        while(arr->A[j] >= 0)
            j--;

        if(i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
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
    printf("\t***** An Example of Negative Numbers on left in an Array *****\n\n");

    struct Array arr = {{-6, 3, -8, 10, 5, -7, -9, 12, -4, 2}, 20, 10};

    display_array(arr);

    rearrange_array(&arr);

    display_array(arr);

    return 0;
}
