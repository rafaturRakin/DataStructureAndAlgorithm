#include<stdio.h>

/*
    Author: Rakin
    Date:  09-01-2022
    Language: C
    Content: Tower of Hanoi
*/

void tower_of_hanoi(int number, int tower1, int tower2, int tower3)
{
    if(number>0)
    {
        tower_of_hanoi(number-1, tower1, tower3, tower2);
        printf("Disk : %d is moved from tower: %d using tower: %d to tower: %d\n", number, tower1, tower2, tower3);
        tower_of_hanoi(number-1, tower2, tower1, tower3);
    }
}

int main()
{
    printf("\t***** An Example of Tower of Hanoi *****\n\n");

    tower_of_hanoi(4, 1, 2, 3);

    return 0;
}
