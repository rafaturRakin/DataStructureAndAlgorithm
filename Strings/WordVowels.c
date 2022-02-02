#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  02-02-2022
    Language: C
    Content: Words, Vowels, Consonants
*/


void count_words(char ch[])
{
    int i = 0, words = 1;
    while(ch[i] != '\0')
    {
        if(i>0 && ch[i]==' ' && ch[i-1]!=' ')
            ++words;
        ++i;
    }
    printf("There are total %d words in the string\n\n", words);
}


void count_vowels_consonants(char ch[])
{
    int i, consonants, vowels, specialCharacters;
    i = consonants = vowels = specialCharacters = 0;

    while(ch[i] != '\0')
    {
        if(ch[i]=='A' || ch[i]=='E' || ch[i]=='I' || ch[i]=='O' || ch[i]=='U'  /
           ch[i]=='a' || ch[i]=='e' || ch[i]=='i' || ch[i]=='o' || ch[i]=='u')
            ++vowels;
        else if( (ch[i]>='A' && ch[i]<='Z') || (ch[i]>='a' && ch[i]<='z') )
            ++consonants;
        else
            ++specialCharacters;
        ++i;
    }

    printf("There are total %d vowels\n", vowels);
    printf("There are total %d consonants\n", consonants);
    printf("There are total %d special characters\n\n", specialCharacters);
}


void display_string(char ch[])
{
    int i = 0;
    printf("Printing string : \n\t");

    while(ch[i]!='\0')
        printf("%c", ch[i++]);
    printf("\n\n");
}


int main()
{
    printf("\t***** An Example of Counting Words, Vowels and Consonants *****\n\n");

    char str[] = "Welcome to HSTU, Dinajpur";

    display_string(str);
    count_words(str);
    count_vowels_consonants(str);

    return 0;
}
