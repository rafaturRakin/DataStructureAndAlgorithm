#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  01-02-2022
    Language: C
    Content: String in C
*/


void display_string(char ch[])
{
    int i = 0;
    printf("Printing name : \n\t");

    while(ch[i]!='\0')
        printf("%c", ch[i++]);
    printf("\n\n");
}


int main()
{
    printf("\t***** An Example of Strings in C *****\n\n");

    char name1[10] = {'R', 'a', 'k', 'i', 'n', '\0'};
    char name2[] = {'R', 'a', 'f', 'a', 't', 'u', 'r', '\0'};
    char name3[] = "Rafatur Rahman";
    char *name = "Shah Rakin";
    char word[50];

    display_string(name1);
    display_string(name2);
    display_string(name3);
    display_string(name);

    printf("Enter a sentence : ");
    gets(word);
    printf("The sentence you entered is : %s\n\n", word);

    printf("Enter a single word : ");
    scanf("%s", word);
    printf("You entered : %s\n\n", word);

    return 0;
}

