#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  05-02-2022
    Language: C
    Content: Checking Anagram
*/

void anagram(char ch1[], char ch2[])
{
    int hash[26] = {0};
    int i = 0;

    while(ch1[i]!='\0')
    {
        hash[ch1[i]-'a']++;
        ++i;
    }

    i = 0;

    while(ch2[i]!='\0')
    {
        hash[ch2[i]-'a']--;
        ++i;
    }

    for(i=0; i<26; i++)
    {
        if(hash[i]!=0)
        {
            printf("Both are Not Anagram\n\n");
            return;
        }
    }
    printf("Both are Anagram\n\n");
}


void display_string(char ch[])
{
    int i = 0;
    printf("Printing word : \n\t");

    while(ch[i]!='\0')
        printf("%c", ch[i++]);
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Anagram *****\n\n");

    char str1[] = "basiparachromatin";
    char str2[] = "marsipobranchiata";
    char str3[] = "acclimatiser";

    display_string(str1);
    display_string(str2);
    anagram(str1, str2);

    printf("\n");

    display_string(str2);
    display_string(str3);
    anagram(str2, str3);

    return 0;
}

