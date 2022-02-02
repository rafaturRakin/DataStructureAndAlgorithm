#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  02-02-2022
    Language: C
    Content: Finding length of a string
*/


void display_string(char ch[])
{
    int i = 0;
    printf("Printing name : \n\t");

    while(ch[i]!='\0')
        printf("%c", ch[i++]);
    printf("\n\n");
}


void string_length(char *str)
{
    int i = 0;
    while(str[i] != '\0')
        i++;

    printf("The length of the string is : %d\n", i);
}

int main()
{
    printf("\t***** An Example of Finding String Length *****\n\n");

    char *str = "This is a string variable";

    display_string(str);
    string_length(str);

    return 0;
}


