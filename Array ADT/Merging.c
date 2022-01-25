#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  25-01-2022
    Language: C
    Content: Merging Arrays
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


struct Array* merge_array(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3;
    arr3 = (struct Array *) malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    while(i<arr1->length)
        arr3->A[k++] = arr1->A[i++];

    while(j<arr2->length)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->size;

    return arr3;
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
    printf("\t***** An Example of Array Merging *****\n\n");

    struct Array arr1 = {{2, 6, 10, 15, 25, 27, 33, 40}, 20, 8};
    struct Array arr2 = {{3, 4, 7, 18, 20, 23, 26}, 20, 7};
    struct Array *arr3;

    display_array(arr1);
    display_array(arr2);

    arr3 = merge_array(&arr1, &arr2);
    printf("After Merging 2 arrays\n");
    display_array(*arr3);

    free(arr3);
    arr3 = NULL;

    return 0;
}

