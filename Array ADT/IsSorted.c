#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  23-01-2022
    Language: C
    Content: Is array sorted or not
*/

struct Array
{
    int A[20];
    int size;
    int length;
};

void is_sorted(struct Array arr)
{
    int i=0;

    if(arr.A[i] > arr.A[i+1])
    {
        for(i=1; i<arr.length-1; i++)
        {
            if(arr.A[i] < arr.A[i+1])
            {
                printf("Array is not sorted...\n\n");
                return;
            }
        }
        printf("Array is sorted in Descending order\n\n");
    }
    else
    {
        for(i=1; i<arr.length-1; i++)
        {
            if(arr.A[i] > arr.A[i+1])
            {
                printf("Array is not sorted...\n\n");
                return;
            }
        }
        printf("Array is sorted in Ascending order\n\n");
    }
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
    printf("\t***** An Example of is Array Sorted or Not *****\n\n");

    struct Array arr1 = {{2, 3, 5, 10, 15}, 20, 5};
    struct Array arr2 = {{15, 10, 5, 3, 2}, 20, 5};
    struct Array arr3 = {{2, 3, 25, 10, 15}, 20, 5};

    display_array(arr1);
    is_sorted(arr1);

    display_array(arr2);
    is_sorted(arr2);

    display_array(arr3);
    is_sorted(arr3);

    return 0;
}

