#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  05-02-2022
    Language: C
    Content: Finding Duplicates using bitwise operator
*/

void duplicate_bitwise(char ch[])
{
    int hash=0, x=0, i=0;

    printf("Duplicate characters are : \n");
    while(ch[i]!='\0')
    {
        x = 1;
        x = x << (ch[i]-'a');
        if(hash & x)
            printf("\t %c\n", ch[i]);
        else
            hash = hash | x;
        ++i;
    }
    printf("\n");
}

void display_string(char ch[])
{
    int i = 0;
    printf("Printing word : \n\t");

    while(ch[i]!='\0')
        printf("%c", ch[i++]);
    printf("\n\n");
}


int main()
{
    printf("\t***** An Example of Finding Duplicates using bitwise operator *****\n\n");

    char str[] = "pseudopseudohypoparathyroidism";

    display_string(str);
    duplicate_bitwise(str);

    return 0;
}
