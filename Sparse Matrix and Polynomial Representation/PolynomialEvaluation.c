#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  28-02-2022
    Language: C
    Content:  Polynomial Evaluation
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


int power(int base, int exponent)
{
    if(exponent == 0)
        return 1;

    if(exponent%2==1)
        return base * power(base*base, (exponent-1)/2);
    else
        return power(base*base, exponent/2);
}


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


int evaluate_polynomial(struct Polynomial p, int value)
{
    int sum = 0;
    for(int i=0; i<p.total_terms; i++)
        sum += p.terms[i].coefficient * power(value, p.terms[i].exponent);
    return sum;
}


void display_polynomial(struct Polynomial p)
{
    int i, j, k=0;
    printf("\nPrinting %d term(s) polynomial : \n\t", p.total_terms);
    for(i=0; i<p.total_terms; i++)
    {
        printf(" %d", p.terms[i].coefficient);

        if(p.terms[i].exponent==1)
            printf("x");
        else if(p.terms[i].exponent==0)
            printf("");
        else
            printf("x^%d", p.terms[i].exponent);

        if(i+1<p.total_terms && p.terms[i+1].coefficient>0)
            printf(" +");
    }
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Polynomial Evaluation in C *****\n\n");

    struct Polynomial p;
    int value_x;

    create_polynomial(&p);

    printf("\n");

    display_polynomial(p);

    printf("\nEnter the value of x : ");
    scanf("%d", &value_x);

    printf("The value of the polynomial is : %d\n\n", evaluate_polynomial(p, value_x));

    free(p.terms);

    return 0;
}
