#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  29-01-2022
    Language: C
    Content: Finding Duplicate Elements
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


int max_element(struct Array arr)
{
    int maximum = arr.A[0];

    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] > maximum)
            maximum = arr.A[i];
    }
    return maximum;
}


void duplicate_element_sorted(struct Array arr)
{
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i] == arr.A[i+1])
        {
            int j = i+1;
            while(arr.A[j] == arr.A[i])
                j++;

            printf("\t # Duplicate element is %d appears %d times\n", arr.A[i], j - i);
            i = j - 1;
        }
    }
    printf("\n");
}


void duplicate_element_unsorted(struct Array arr)
{
    for(int i=0; i<arr.length; i++)
    {
        int count = 1;
        if(arr.A[i] != -1)
        {
            for(int j=i+1; j<arr.length; j++)
            {
                if(arr.A[j] == arr.A[i])
                {
                    ++count;
                    arr.A[j] = -1;
                }
            }
            if(count > 1)
            printf("\t # Duplicate element is %d appears %d times\n", arr.A[i], count);
        }
    }
    printf("\n");
}


void duplicate_element_hashing(struct Array arr)
{
    int high = max_element(arr);

    int * hashTable = (int *) malloc(sizeof(int) * high+1);

    for(int i=0; i<=high; i++)
        hashTable[i] = 0;

    for(int i=0; i<arr.length; i++)
        hashTable[arr.A[i]]++;

    for(int i=0; i<=high; i++)
    {
        if(hashTable[i] > 1)
            printf("\t # Duplicate element is %d appears %d times\n", i, hashTable[i]);
    }

    free(hashTable);
    hashTable = NULL;
    printf("\n");
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
    printf("\t***** An Example of Finding Duplicate Elements *****\n\n");

    struct Array arr1 = {{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 20, 10};
    struct Array arr2 = {{6, 8, 6, 5, 4, 8, 10, 6, 7, 12}, 20, 10};

    printf("First Array (sorted) : \n");
    display_array(arr1);
    duplicate_element_sorted(arr1);

    printf("\nFirst Array (using hashing) : \n");
    duplicate_element_hashing(arr1);


    printf("\nSecond Array (unsorted) : \n");
    display_array(arr2);
    duplicate_element_unsorted(arr2);


    printf("\nSecond Array (using hashing) : \n");
    duplicate_element_hashing(arr2);

    return 0;
}

