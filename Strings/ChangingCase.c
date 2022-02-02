#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  02-02-2022
    Language: C
    Content: Changing Case of a String
*/


void display_string(char ch[])
{
    int i = 0;
    printf("Printing string : \n\t");

    while(ch[i]!='\0')
        printf("%c", ch[i++]);
    printf("\n");
}


void to_lower_case(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        str[i] += 32;
        i++;
    }

    printf("After changing to lower case : \n\t%s\n\n", str);
}


void to_upper_case(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        str[i] -= 32;
        i++;
    }

    printf("After changing to upper case : \n\t%s\n\n", str);
}


void toggle_case(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i]>=65 && str[i]<=90)
            str[i] += 32;
        else if(str[i]>='a' && str[i]<='z')
            str[i] -= 32;
        i++;
    }

    printf("After toggle case : \n\t%s\n\n", str);
}


int main()
{
    printf("\t***** An Example of Changing Case of a String *****\n\n");

    char upper[] = "WELCOME";
    char lower[] = "programmer";
    char toggle[] = "C is Number #1 Coding Language.";

    display_string(upper);
    to_lower_case(upper);

    display_string(lower);
    to_upper_case(lower);

    display_string(toggle);
    toggle_case(toggle);

    return 0;
}
