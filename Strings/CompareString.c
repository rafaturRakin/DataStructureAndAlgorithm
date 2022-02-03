#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  03-02-2022
    Language: C
    Content: String Comparing
*/

void string_compare(char ch1[], char ch2[])
{
    int i = 0, j = 0;

    while(ch1[i]!='\0' && ch2[j]!='\0')
    {
        if(ch1[i] != ch2[j])
            break;
        ++i;
        ++j;
    }

    if( (ch1[i]=='\0' && ch2[j]!='\0') || (ch1[i]<ch2[j]) )
        printf("First String is Smaller\n\n");
    else if( (ch1[i]!='\0' && ch2[j]=='\0') || (ch2[j]<ch1[i]) )
        printf("Second String is Smaller\n\n");
    else
        printf("Both string are equal\n\n");
}


void display_string(char ch[], int number)
{
    int i = 0;
    printf("Printing string #%d: \n\t", number);

    while(ch[i]!='\0')
        printf("%c", ch[i++]);
    printf("\n");
}


int main()
{
    printf("\t***** An Example of String Comparing *****\n\n");

    char str[] = "Python Language";
    char ch[] = "Python";
    char str2[] = "Python";

    display_string(str, 1);
    display_string(ch, 2);
    string_compare(str, ch);

    display_string(ch, 1);
    display_string(str, 2);
    string_compare(ch, str);

    display_string(ch, 1);
    display_string(str2, 2);
    string_compare(ch, str2);

    return 0;
}
