#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  28-01-2022
    Language: C
    Content: Finding Missing Elements
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


int min_element(struct Array arr)
{
    int minimum = arr.A[0];

    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] < minimum)
            minimum = arr.A[i];
    }
    return minimum;
}


void single_missing_element(struct Array arr)
{
    int difference = arr.A[0];

    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]-i != difference)
        {
            printf("\t # Missing element : %d\n\n", difference+i);
            break;
        }
    }
}


void multiple_missing_element(struct Array arr)
{
    int difference = arr.A[0];

    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]-i != difference)
        {
            while(difference < arr.A[i]-i)
            {
                printf("\t # Missing element : %d\n", i+difference);
                ++difference;
            }
        }
    }
    printf("\n");
}


void missing_element_unsorted(struct Array arr)
{
    int low, high;
    low = min_element(arr);
    high = max_element(arr);

    int * hashTable = (int *) malloc(sizeof(int) * high+1);

    for(int i=0; i<=high; i++)
        hashTable[i] = 0;

    for(int i=0; i<arr.length; i++)
        hashTable[arr.A[i]]++;

    for(int i=low; i<=high; i++)
    {
        if(hashTable[i] == 0)
            printf("\t # Missing element : %d\n", i);
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
    printf("\t***** An Example of Finding Missing Elements *****\n\n");

    struct Array arr1 = {{6, 7, 8, 9, 10, 11, 13, 14, 15, 16}, 20, 10};
    struct Array arr2 = {{6, 7, 8, 9, 11, 12, 13, 16, 17, 18}, 20, 10};
    struct Array arr3 = {{3, 7, 1, 9, 6, 12, 10, 8, 4, 11}, 20, 10};

    printf("First Array (sorted single element missing) : \n");
    display_array(arr1);
    single_missing_element(arr1);


    printf("\nSecond Array (sorted multiple elements missing) : \n");
    display_array(arr2);
    multiple_missing_element(arr2);


    printf("\nThird Array (unsorted multiple element missing) : \n");
    display_array(arr3);
    missing_element_unsorted(arr3);

    return 0;
}
