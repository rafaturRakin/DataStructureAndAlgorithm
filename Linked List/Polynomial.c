#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
    Author: Rakin
    Date:  03-04-2022
    Language: C
    Content : Polynomial using linked list
*/

struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
} *poly=NULL;


void createPolynomial()
{
    int node;
    struct Term *temp, *last;
    printf("Enter total terms : ");
    scanf("%d", &node);

    printf("Enter the values of terms (coefficient, exponent)\n");
    for(int i=0; i<node; i++)
    {
        printf("\t Term #%d : ", i+1);
        temp = (struct Term *) malloc(sizeof(struct Term));
        scanf("%d %d", &temp->coefficient, &temp->exponent);
        temp->next = NULL;
        if(poly==NULL)
            poly = last = temp;
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    printf("\n");
}


void evaluatePolynomial(int x)
{
    double result = 0.0;
    struct Term *current = poly;
    while(current)
    {
        result += (current->coefficient * pow(x, current->exponent));
        current = current->next;
    }
    printf("\tFor value x = %d , answer is : %.0lf\n", x, result);
}

void displayPolynomial()
{
    struct Term *current = poly;
    printf("Printing polynomial : \n\t");
    while(current)
    {
        printf("%dx^%d", current->coefficient, current->exponent);
        if(current->next)
            printf(" + ");
        current = current->next;
    }
    printf("\n");
}

int main()
{
    printf("\t***** An Example of Circular Doubly Linked List in C *****\n\n");

    createPolynomial();
    displayPolynomial();
    evaluatePolynomial(2);

    return 0;
}
