#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  01-02-2022
    Language: C
    Content: Char Variable and Array
*/


void display_array(char ch[])
{
    printf("Printing all Characters : \n");
    for(int i=0; i<5; i++)
        printf("\t%c\t", ch[i]);
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Char Variable and Array *****\n\n");

    char singleVariable1 = 'a';
    char singleVariable2 = 65;

    char characterArray1[5] = {'a', 'b', 'c', 'd', 'e'};
    char characterArray2[] = {'A', 'B', 'C', 'D', 'E'};
    char characterArray3[5] = {'a', 'B'};

    printf("Character : %c , and its ASCII Value is : %d\n", singleVariable1, singleVariable1);
    printf("Character : %c , and its ASCII Value is : %d\n\n", singleVariable2, singleVariable2);

    display_array(characterArray1);
    display_array(characterArray2);
    display_array(characterArray3);

    return 0;
}
