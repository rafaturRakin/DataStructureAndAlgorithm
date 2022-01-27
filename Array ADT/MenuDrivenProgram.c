#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  27-01-2022
    Language: C
    Content: Menu Driven Program
*/

struct Array
{
    int *A;
    int size;
    int length;
};



void insert_array(struct Array *arr, int index, int element)
{
    if(arr->length < arr->size && index>=0 && index <= arr->length)
    {
        for(int i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = element;
        arr->length++;
    }
    else
        printf("Invalid Index!!! Array length is %d...%d is not inserted\n", arr->length, element);
}


int delete_array(struct Array *arr, int index)
{
    int item = INT_MIN;
    if(arr->length > 0 && index>=0 && index<=arr->length-1)
    {
        item = arr->A[index];
        for(int i=index; i<arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
    }
    return item;
}


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


int sum_elements(struct Array arr)
{
    int total = 0;
    for(int i=0; i<arr.length; i++)
        total += arr.A[i];
    return total;
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
    printf("\t***** An Example of Menu Driven Program *****\n\n");

    int index, element, choice;
    struct Array arr;

    printf("Enter the array size : ");
    scanf("%d", &arr.size);
    arr.A = (int *) malloc(sizeof(int) * arr.size);
    arr.length = 0;

    do
    {
        printf("\n***** Menu *****\n");
        printf("\t 1. Insert element\n");
        printf("\t 2. Delete element\n");
        printf("\t 3. Search element\n");
        printf("\t 4. Sum elements\n");
        printf("\t 5. Display elements\n");
        printf("\t 6. Exit\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter the index and element : ");
            scanf("%d %d", &index, &element);
            insert_array(&arr, index, element);
            break;

        case 2:
            printf("Enter the index : ");
            scanf("%d", &index);
            element = delete_array(&arr, index);
            printf("Deleted element from %d index is %d\n", index, element);
            break;

        case 3:
            printf("Enter the element : ");
            scanf("%d", &element);
            index = linear_search(arr, element);
            printf("%d is at location %d\n", element, index);
            break;

        case 4:
            printf("Sum of %d elements in array is %d\n", arr.length, sum_elements(arr));
            break;

        case 5:
            display_array(arr);
            break;

        default:
            printf("Exiting program...\n\n");
            break;
        }
    } while(choice>0 && choice<6);

    return 0;
}
