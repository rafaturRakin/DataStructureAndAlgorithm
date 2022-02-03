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
        {
            printf("Given String is not a Palindrome String\n\n");
            return;
        }
        ++i;
        ++j;
    }
    printf("Given String is a Palindrome String\n\n");
}


void reverse_string(char ch[])
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
    string_compare(ch, str);
}

void palindrome_string(char ch[])
{
    int i = 0, j = 0;
    while(ch[j] != '\0')
        j++;
    --j;
    while(i<j)
    {
        if(ch[i] != ch[j])
        {
            printf("\'%s\' is not Palindrome\n\n", ch);
            return;
        }
        ++i;
        --j;
    }
    printf("\'%s\' is Palindrome\n\n", ch);
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
    printf("\t***** An Example of String Palindrome *****\n\n");

    char str[] = "Python";
    char ch[] = "tattarrattat";

    display_string(str);
    reverse_string(str);

    display_string(ch);
    reverse_string(ch);

    printf("\nUsing second method (palindrome_string): \n\n");

    palindrome_string(str);
    palindrome_string(ch);

    return 0;
}
