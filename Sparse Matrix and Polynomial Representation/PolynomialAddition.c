#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  02-03-2022
    Language: C
    Content:  Polynomial Addition
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

struct Polynomial * add_polynomial(struct Polynomial *p1, struct Polynomial *p2)
{
    int i, j, k;
    struct Polynomial *sum;

    i = j = k = 0;
    sum = (struct Polynomial *) malloc(sizeof(struct Polynomial) * (p1->total_terms + p2->total_terms));

    while(i<p1->total_terms && j<p2->total_terms)
    {
        if(p1->terms[i].exponent > p2->terms[j].exponent)
            sum->terms[k++] = p1->terms[i++];
        else if(p1->terms[i].exponent < p2->terms[j].exponent)
            sum->terms[k++] = p2->terms[j++];
        else
        {
            sum->terms[k].exponent = p1->terms[i].exponent;
            sum->terms[k++].coefficient = p1->terms[i++].coefficient + p2->terms[j++].coefficient;
        }
    }

    while(i<p1->total_terms)
        sum->terms[k++] = p1->terms[i++];

    while(j<p2->total_terms)
        sum->terms[k++] = p2->terms[j++];

    sum->total_terms = k;
    return sum;
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
    printf("\t***** An Example of Polynomial Addition in C *****\n\n");

    struct Polynomial p1, p2, *sum;

    printf("Creating first polynomial...\n");
    create_polynomial(&p1);

    printf("\nCreating second polynomial...\n");
    create_polynomial(&p2);

    printf("\n");

    sum = add_polynomial(&p1, &p2);

    printf("\t\t *** Displaying Polynomials ***\n");
    display_polynomial(p1);
    display_polynomial(p2);

    printf("\nSum of the 2 polynomials is");
    display_polynomial(*sum);

    free(p1.terms);
    free(p2.terms);
    free(sum);

    sum = NULL;

    return 0;
}

