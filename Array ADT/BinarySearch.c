#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  20-01-2022
    Language: C
    Content: Binary Search in Array
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


void display_array(struct Array arr)
{
    printf("Printing all array elements(%d) : \n", arr.length);
    for(int i=0; i<arr.length; i++)
        printf("\t%d", arr.A[i]);
    printf("\n\n");
}


int binary_search(struct Array arr, int key)
{
    int low, mid, high;
    low = 0;
    high = arr.length - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}


int recursive_binary_search(int A[], int low, int high, int key)
{
    int mid;
    if(low <= high)
    {
        mid = (low + high) / 2;
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            return recursive_binary_search(A, low, mid-1, key);
        else
            return recursive_binary_search(A, mid+1, high, key);
    }

    return -1;
}

int main()
{
    printf("\t***** An Example of Binary Search in Array *****\n\n");

    struct Array arr = {{10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, 20, 10};

    display_array(arr);

    printf("Index of value 40 is : %d\n", binary_search(arr, 40));
    printf("Index of value 4 is : %d\n", binary_search(arr, 4));

    printf("\n\nIndex of value 100 is : %d\n", recursive_binary_search(arr.A, 0, arr.length-1, 100));
    printf("Index of value 101 is : %d\n", recursive_binary_search(arr.A, 0, arr.length-1, 101));

    return 0;
}

