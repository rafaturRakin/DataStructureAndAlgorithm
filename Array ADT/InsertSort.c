#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  23-01-2022
    Language: C
    Content: Insert in a sorted Array
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


void insert_sort(struct Array *arr, int item)
{
    if(arr->length == arr->size)
    {
        printf("Array is full... %d is not inserted!!!\n\n", item);
        return;
    }

    int i = arr->length-1;
    while(i>=0 && item<arr->A[i])
    {
        if(item < arr->A[i])
            arr->A[i+1] = arr->A[i];
        i--;
    }

    arr->A[i+1] = item;
    arr->length++;
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
    printf("\t***** An Example of Insertion Sort *****\n\n");

    struct Array arr = {{2, 3, 5, 10, 15}, 20, 5};

    display_array(arr);

    insert_sort(&arr, 4);
    display_array(arr);

    insert_sort(&arr, 1);
    display_array(arr);

    insert_sort(&arr, 20);
    display_array(arr);

    return 0;
}
