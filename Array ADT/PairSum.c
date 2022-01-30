#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  30-01-2022
    Language: C
    Content: Finding Pair of Elements
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


void pair_element_sorted(struct Array arr, int k)
{
    for(int i=0, j=arr.length-1; i<j; )
    {
        if(arr.A[i] + arr.A[j] == k)
        {
            printf("\t # Pair element is ( %d , %d )\n", arr.A[i], arr.A[j]);
            i++;
            j--;
        }
        else if(arr.A[i] + arr.A[j] < k)
            i++;
        else
            j--;
    }
    printf("\n");
}


void pair_element_unsorted(struct Array arr, int k)
{
    for(int i=0; i<arr.length-1; i++)
    {
        for(int j=i+1; j<arr.length; j++)
        {
            if(arr.A[i] + arr.A[j] == k)
                printf("\t # Pair element is ( %d , %d )\n", arr.A[i], arr.A[j]);
        }
    }
    printf("\n");
}


void pair_element_hashing(struct Array arr, int k)
{
    int high = max_element(arr);

    int * hashTable = (int *) malloc(sizeof(int) * high+1);

    for(int i=0; i<=high; i++)
        hashTable[i] = 0;

    for(int i=0; i<arr.length; i++)
    {
        hashTable[arr.A[i]]++;
        if(arr.A[i]<k && hashTable[k-arr.A[i]]!=0 && arr.A[i]!=k-arr.A[i])
            printf("\t # Pair element is ( %d , %d )\n", arr.A[i], k - arr.A[i]);
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
    printf("\t***** An Example of Finding Pair Elements *****\n\n");

    struct Array arr1 = {{1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, 20, 10};
    struct Array arr2 = {{6, 3, 8, 10, 16, 7, 5, 2, 9, 14}, 20, 10};

    printf("First Array (sorted) : \n");
    display_array(arr1);
    pair_element_sorted(arr1, 10);

    printf("\nFirst Array (using hashing) : \n");
    pair_element_hashing(arr1, 10);


    printf("\nSecond Array (unsorted) : \n");
    display_array(arr2);
    pair_element_unsorted(arr2, 10);


    printf("\nSecond Array (using hashing) : \n");
    pair_element_hashing(arr2, 10);

    return 0;
}

