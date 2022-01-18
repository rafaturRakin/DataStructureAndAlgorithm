#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  18-01-2022
    Language: C
    Content: Delete from an Array
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


int delete_array(struct Array *arr, int index)
{
    int item = INT_MIN;
    if(arr->length > 0 && index>=0 && index<=arr->length-1)
    {
        item = arr->A[index];
        for(int i=index; i<arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
    }
    return item;
}

void display_array(struct Array arr)
{
    printf("Printing all array elements(%d) : \n", arr.length);
    for(int i=0; i<arr.length; i++)
        printf("\t%d", arr.A[i]);
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Delete from Array *****\n\n");

    int deletedElement;
    struct Array arr = {{10, 20, 30, 40, 50}, 20, 5};

    display_array(arr);

    deletedElement = delete_array(&arr, 2);

    printf("\nDeleted Item = %d\n", deletedElement);
    display_array(arr);

    return 0;
}

