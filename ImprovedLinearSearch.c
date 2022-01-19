#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  19-01-2022
    Language: C
    Content: Improved Linear Search
*/

struct Array
{
    int A[20];
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linear_search_transposition(struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}

int linear_search_move_to_head(struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(arr->A[i] == key)
        {
            swap(&arr->A[0], &arr->A[i]);
            return 0;
        }
    }
    return -1;
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
    printf("\t***** An Example of Improved Linear Search in Array *****\n\n");

    int index;
    struct Array arr = {{10, 20, 30, 40, 50}, 20, 5};

    display_array(arr);

    index = linear_search_transposition(&arr, 30);
    printf("Index of value 30(transposition) : %d\n", index);
    display_array(arr);

    index = linear_search_move_to_head(&arr, 50);
    printf("Index of value 100(move to head) : %d\n", index);
    display_array(arr);

    return 0;
}


