#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  26-02-2022
    Language: C
    Content:  Polynomial Representation
*/

struct Term
{
    int coefficient;
    int exponent;
};

struct Polynomial
{
    int total_terms;
    struct Term *terms;
};

void create_polynomial(struct Polynomial *p)
{
    int i;

    printf("Enter total terms : ");
    scanf("%d", &p->total_terms);

    p->terms = (struct Term *) malloc(sizeof(struct Term) * p->total_terms);


    printf("Enter terms (coefficient, exponent)\n");
    for(int i=0; i<p->total_terms; i++)
    {
        printf("\tTerm#%d: ", i+1);
        scanf("%d %d", &p->terms[i].coefficient, &p->terms[i].exponent);
    }
}

void display_polynomial(struct Polynomial p)
{
    int i, j, k=0;
    printf("\nPrinting %d term(s) polynomial : \n\t", p.total_terms);
    for(i=0; i<p.total_terms; i++)
    {
        printf("%dx", p.terms[i].coefficient);

        if(p.terms[i].exponent!=1 || p.terms[i].exponent!=0)
            printf("^%d", p.terms[i].exponent);

        if(i+1<p.total_terms && p.terms[i+1].coefficient>0)
            printf("+");
    }
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Polynomial Representation in C *****\n\n");

    struct Polynomial p;

    create_polynomial(&p);

    printf("\n");

    display_polynomial(p);

    free(p.terms);

    return 0;
}

