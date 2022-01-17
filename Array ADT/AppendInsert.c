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


void append_array(struct Array *arr, int element)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = element;
    else
        printf("%d is not appended!!! Array is full now...\n", element);
}


void insert_array(struct Array *arr, int index, int element)
{
    if(arr->length < arr->size && index>=0 && index <= arr->length)
    {
        for(int i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = element;
        arr->length++;
    }
    else
        printf("Invalid Index or Array is Full...%d is not inserted\n", element);
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
    printf("\t***** An Example of Append and Insert in an Array *****\n\n");

    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    display_array(arr);

    append_array(&arr, 7);
    display_array(arr);

    insert_array(&arr, 1, 12);
    display_array(arr);

    return 0;
}
