#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  03-02-2022
    Language: C
    Content: String Reversing
*/

void reverse_method1(char ch[])
{
    int i = 0, j = 0;
    char str[20];

    while(ch[i] != '\0')
        ++i;

    i = i - 1;
    while(i>=0)
    {
        str[j] = ch[i];
        j++;
        i--;
    }
    str[j] = '\0';
    printf("Reverse string using second array is : \n\t%s\n\n", str);
}


void reverse_method2(char ch[])
{
    int i = 0, j = 0;
    char temp;

    while(ch[j] != '\0')
        ++j;

    j = j - 1;

    while(i<j)
    {
        temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
        i++;
        j--;
    }
    printf("Reverse string using same array is :\n\t%s\n\n", ch);
}

void display_string(char ch[])
{
    int i = 0;
    printf("Printing string : \n\t");

    while(ch[i]!='\0')
        printf("%c", ch[i++]);
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Strings Reversing *****\n\n");

    char str[] = "Python Language";
    char ch[] = "C Compiler";

    display_string(str);
    reverse_method1(str);

    display_string(ch);
    reverse_method2(ch);

    return 0;
}

