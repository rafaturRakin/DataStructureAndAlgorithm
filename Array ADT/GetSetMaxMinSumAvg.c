#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  21-01-2022
    Language: C
    Content: Get, Set, Min, Max, Sum, Avg
*/

struct Array
{
    int A[20];
    int size;
    int length;
};


int get_element(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}


void set_element(struct Array *arr, int index, int value)
{
    if(index>=0 && index<arr->length)
        arr->A[index] = value;
    else
        printf("Invalid Index!!!\n\n");
}


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


int sum_elements(struct Array arr)
{
    int total = 0;
    for(int i=0; i<arr.length; i++)
        total += arr.A[i];
    return total;
}


double avg_elements(struct Array arr)
{
    double total = 0.0;
    for(int i=0; i<arr.length; i++)
        total += arr.A[i];
    return total / arr.length;
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
    printf("\t***** An Example of Basic Array Operations *****\n\n");

    struct Array arr = {{12, 7, 1, 127, 40, 26, 5, 100, 2, 11}, 20, 10};

    display_array(arr);

    printf("Value in index 5 : %d\n\n", get_element(arr, 5));

    set_element(&arr, 9, 9);
    printf("After setting index 9: \n");
    display_array(arr);

    printf("Maximum element in array is = %d\n", max_element(arr));
    printf("Minimum element in array is = %d\n", min_element(arr));
    printf("Sum of all elements in array is = %d\n", sum_elements(arr));
    printf("Average of elements in array is = %.2lf\n", avg_elements(arr));

    return 0;
}
