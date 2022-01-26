#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  26-01-2022
    Language: C
    Content: Set operations (sorted)
*/

struct Array
{
    int A[20];
    int size;
    int length;
};

struct Array* set_union(struct Array *arr1, struct Array *arr2)
{
    int i=0, j=0, k=0;
    struct Array *arr3;
    arr3 = (struct Array*) malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    while(i<arr1->length)
        arr3->A[k++] = arr1->A[i++];
    while(j<arr2->length)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = k;
    arr3->size = arr1->size;

    return arr3;
}


struct Array* set_intersection(struct Array *arr1, struct Array *arr2)
{
    int i=0, j=0, k=0;
    struct Array *arr3;
    arr3 = (struct Array*) malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = arr1->size;

    return arr3;
}


struct Array* set_difference(struct Array *arr1, struct Array *arr2)
{
    int i=0, j=0, k=0;
    struct Array *arr3;
    arr3 = (struct Array*) malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    while(i<arr1->length)
        arr3->A[k++] = arr1->A[i++];

    arr3->length = k;
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
    printf("\t***** An Example of Set Operations *****\n\n");

    struct Array arr1 = {{10, 20, 25, 35, 50}, 20, 5};
    struct Array arr2 = {{5, 10, 15, 20, 25}, 20, 5};
    struct Array *arr3;

    printf("First Set : \n");
    display_array(arr1);

    printf("Second Set : \n");
    display_array(arr2);

    arr3 = set_union(&arr1, &arr2);
    printf("Union of First and Second set is : \n");
    display_array(*arr3);

    arr3 = set_intersection(&arr1, &arr2);
    printf("Intersection of First and Second set is : \n");
    display_array(*arr3);

    arr3 = set_difference(&arr1, &arr2);
    printf("Difference of First and Second set is : \n");
    display_array(*arr3);


    free(arr3);
    arr3 = NULL;

    return 0;
}

