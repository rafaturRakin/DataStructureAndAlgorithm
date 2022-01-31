#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  31-01-2022
    Language: C
    Content: Finding Min and Max
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


void min_max(struct Array arr)
{
    int minimum, maximum;
    minimum = maximum = arr.A[0];

    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] < minimum)
            minimum = arr.A[i];
        else if(arr.A[i] > maximum)
            maximum = arr.A[i];
    }

    printf("\t Minimum is : %d\n", minimum);
    printf("\t Maximum is : %d\n", maximum);
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
    printf("\t***** An Example of finding Min and Max *****\n\n");

    struct Array arr = {{5, 8, 3, 9, 6, 2, 10, 7, -1, 4}, 20, 10};

    display_array(arr);
    min_max(arr);

    return 0;
}

