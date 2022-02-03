#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  03-02-2022
    Language: C
    Content: String Validating
*/

void validate_string(char *ch)
{
    int i = 0;
    while(ch[i] != '\0')
    {
        if( !(ch[i]>='A' && ch[i]<='Z') && !(ch[i]>='a' && ch[i]<='z') && !(ch[i]>='0' && ch[i]<='9') )
        {
            printf("Given string is invalid!! It contains %c\n\n", ch[i]);
            return;
        }
        ++i;
    }

    printf("Given String is Valid.\n\n");
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
    printf("\t***** An Example of Strings Validation *****\n\n");

    char *str = "bangladesh123";
    char *ch = "Bangla-Desh?567";

    display_string(str);
    validate_string(str);

    display_string(ch);
    validate_string(ch);

    return 0;
}

