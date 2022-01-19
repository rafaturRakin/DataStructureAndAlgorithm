#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  19-01-2022
    Language: C
    Content: Array ADT
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


int linear_search(struct Array arr, int key)
{
    int index = -1;
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i] == key)
            return index = i;
    }
    return index;
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
    printf("\t***** An Example of Linear Search in Array *****\n\n");

    int index;
    struct Array arr = {{10, 20, 30, 40, 50}, 20, 5};

    display_array(arr);

    index = linear_search(arr, 30);
    printf("Index of value 30 : %d\n", index);

    index = linear_search(arr, 100);
    printf("Index of value 100 : %d\n", index);

    return 0;
}

