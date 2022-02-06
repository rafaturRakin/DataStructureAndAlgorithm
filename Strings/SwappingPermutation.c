#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  06-02-2022
    Language: C
    Content: String Permutation (swapping)
*/

void swap_characters(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


void string_permutation(char ch[], int low, int high)
{
    if(low==high)
        printf("\t%s\n", ch);
    else
    {
        for(int i=low; i<=high; i++)
        {
            swap_characters(&ch[low], &ch[i]);
            string_permutation(ch, low+1, high);
            swap_characters(&ch[low], &ch[i]);
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
    printf("\t***** An Example of Strings Permutation (swapping) *****\n\n");

    char str[] = "five";

    display_string(str);
    printf("Permutations are : \n");
    string_permutation(str, 0, 3);

    return 0;
}
