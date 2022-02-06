#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  06-02-2022
    Language: C
    Content: String Permutation
*/


void string_permutation(char ch[], int k)
{
    static int flag[10] = {0};
    static char result[10];
    int i;

    if(ch[k]=='\0')
    {
        result[k] = '\0';
        printf("\t%s\n", result);
    }
    else
    {
        for(int i=0; ch[i]!='\0'; i++)
        {
            if(flag[i]==0)
            {
                result[k] = ch[i];
                flag[i] = 1;
                string_permutation(ch, k+1);
                flag[i] = 0;
            }
        }
    }
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
    printf("\t***** An Example of Strings Permutation *****\n\n");

    char str[] = "file";

    display_string(str);
    printf("Permutations are : \n");
    string_permutation(str, 0);

    return 0;
}


