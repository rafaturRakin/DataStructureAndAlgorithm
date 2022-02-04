#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  04-02-2022
    Language: C
    Content: Finding Duplicates
*/

void duplicate_method1(char ch[])
{
    int len = 0, i = 0, j;
    while(ch[len]!='\0')
        ++len;
    --len;

    while(i<len-1)
    {
        int count = 1;
        j = i + 1;
        while(ch[j]!='\0')
        {
            if(ch[i] == ch[j])
                ++count;
            ++j;
        }

        if(count > 1)
            printf("\t%c is appears %d times\n", ch[i], count);

        ++i;
    }
    printf("\n");
}


void duplicate_hashing(char ch[])
{
    int hash[26] = {0}, i = 0;

    while(ch[i]!='\0')
    {
        hash[ch[i] - 'a']++;
        ++i;
    }

    for(i=0; i<26; i++)
    {
        if(hash[i] > 1)
            printf("\t%c is appears %d times\n", 'a'+i, hash[i]);
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
    printf("\t***** An Example of Finding Duplicates *****\n\n");

    char word[] = "pneumonoultramicroscopicsilicovolcanoconiosis";
    char str[] = "pseudopseudohypoparathyroidism";

    display_string(word);
    printf("Using each character method: \n");
    duplicate_method1(word);

    display_string(str);
    printf("Using hashing: \n");
    duplicate_hashing(str);

    return 0;
}

