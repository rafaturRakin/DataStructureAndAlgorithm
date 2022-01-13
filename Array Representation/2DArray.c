#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  13-01-2022
    Language: C
    Content: 2D Array
*/

void method1_2d()
{
    int array[3][4];
    array[2][1] = 5;

    printf("Array Created in Stack(3, 4)...\n");
    printf("\tarray[2][1] = %d\n", array[2][1]);
}


void method2_2d()
{
    int *array[3];
    array[0] = (int *) malloc(sizeof(int) * 4);
    array[1] = (int *) malloc(sizeof(int) * 4);
    array[2] = (int *) malloc(sizeof(int) * 4);

    array[1][3] = 25;
    printf("\nArray of pointers(3) created in stack and array(4) created in heap...\n");
    printf("\tarray[1][3] = %d\n", array[1][3]);

    free(array[0]);
    free(array[1]);
    free(array[2]);
}


void method3_2d()
{
    int **array;
    array = (int **) malloc(sizeof(int *) * 3);

    array[0] = (int *) malloc(sizeof(int) * 4);
    array[1] = (int *) malloc(sizeof(int) * 4);
    array[2] = (int *) malloc(sizeof(int) * 4);

    array[2][2] = 125;
    printf("\nFull array created in heap(3,4)...\n");
    printf("\tarray[2][2] = %d\n", array[2][2]);

    free(array[0]);
    free(array[1]);
    free(array[2]);
    free(array);
}

int main()
{
    printf("\t***** An Example of 2D Array *****\n\n");

    method1_2d();
    method2_2d();
    method3_2d();

    return 0;
}
