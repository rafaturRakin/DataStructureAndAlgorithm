#include<stdio.h>

#include<stdio.h>

/*
    Author: Rakin
    Date:  10-01-2022
    Language: C
    Content: Array Declaration
*/

void declare_and_initialize_array()
{
    int a[10];  // an array of size 10 and initialized with garbage value
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    // an array of size 10 with corresponding values
    int c[10] = {10, 20, 30};   // an array with size 10 with first 3 corresponding value and rest is 0
    int d[10] = {0};    // an array with size 10 all initialized with 0
    int e[] = {5, 10, 15, 20, 25};  // an array of size 5 with corresponding values
}


void print_array()
{
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {10, 20, 30, 40, 50};
    int array3[5] = {5, 10, 15, 20, 25};

    printf("Using name[index]...\n");
    for(int i=0; i<5; i++)
            printf("\tarray1[%d] = %d\n", i, array1[i]);

    printf("\nUsing index[name]...\n");
    for(int i=0; i<5; i++)
        printf("\tarray2[%d] = %d\n", i, i[array2]);

    printf("\nUsing pointer Arithmetic...\n");
    for(int i=0; i<5; i++)
        printf("\tarray3[%d] = %d\n", i, *(array3+i));
}

void print_array_address()
{
    int array1[5] = {1, 2, 3, 4, 5};
    printf("\nPrinting index addresses...\n");
    for(int i=0; i<5; i++)
        printf("\tAddress of index %d = %u\n", i, &array1[i]);
}

int main()
{
    printf("\t***** An Example of Array Declaration *****\n\n");

    declare_and_initialize_array();
    print_array();
    print_array_address();

    return 0;
}
