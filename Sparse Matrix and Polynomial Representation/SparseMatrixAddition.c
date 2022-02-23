#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  23-02-2022
    Language: C
    Content:  Sparse Matrix Addition
*/

struct Element
{
    int r;
    int c;
    int v;
};

struct SparseMatrix
{
    int row;
    int column;
    int number;
    struct Element *element;
};

void create_matrix(struct SparseMatrix *s)
{
    int i;

    printf("Enter dimension (row, column) : ");
    scanf("%d %d", &s->row, &s->column);

    printf("Enter number of non-zero elements : ");
    scanf("%d", &s->number);

    s->element = (struct Element*) malloc(s->number * sizeof(struct Element));

    printf("Enter non-zero elements (row, column, value)\n");
    for(int i=0; i<s->number; i++)
    {
        printf("\tElement#%d: ", i+1);
        scanf("%d %d %d", &s->element[i].r, &s->element[i].c, &s->element[i].v);
    }
}

struct SparseMatrix * add_matrix(struct SparseMatrix *s1, struct SparseMatrix *s2)
{
    struct SparseMatrix *sum;
    int i, j, k;

    i = j = k = 0;

    if(s1->row!=s2->row || s1->column!=s2->column)
        return NULL;

    sum = (struct SparseMatrix*) malloc(sizeof(struct SparseMatrix));
    sum->element = (struct Element *) malloc(sizeof(struct Element) * (s1->number+s2->number));

    while(i<s1->number && j<s2->number)
    {
        if(s1->element[i].r < s2->element[j].r)
            sum->element[k++] = s1->element[i++];
        else if(s2->element[j].r < s1->element[i].r)
            sum->element[k++] = s2->element[j++];
        else
        {
            if(s1->element[i].c < s2->element[j].c)
                sum->element[k++] = s1->element[i++];
            else if(s2->element[j].c < s1->element[i].c)
                sum->element[k++] = s2->element[j++];
            else
            {
                sum->element[k] = s1->element[i];
                sum->element[k++].v = s1->element[i++].v + s2->element[j++].v;
            }
        }
    }

    while(i<s1->number)
        sum->element[k++] = s1->element[i++];
    while(j<s2->number)
        sum->element[k++] = s2->element[j++];

    sum->row = s1->row;
    sum->column = s2->column;
    sum->number = k;

    return sum;
}

void display_matrix(struct SparseMatrix s)
{
    int i, j, k=0;
    printf("\nPrinting (%d * %d) sparse matrix : \n", s.row, s.column);
    for(i=0; i<s.row; i++)
    {
        printf("\t");
        for(j=0; j<s.column; j++)
        {
            if(i==s.element[k].r && j==s.element[k].c)
                printf("%5d ", s.element[k++].v);
            else
                printf("%5d ", 0);
        }
        printf("\n");
    }
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Sparse Matrix Addition in C *****\n\n");

    struct SparseMatrix s1, s2, *s3;

    create_matrix(&s1);
    printf("\n");
    create_matrix(&s2);

    s3 = add_matrix(&s1, &s2);

    printf("Matrix: #01");
    display_matrix(s1);

    printf("Matrix: #02");
    display_matrix(s2);

    if(s3!=NULL)
    {
        printf("Addition of matrix 1 and 2 is :");
        display_matrix(*s3);
    }


    free(s1.element);
    free(s2.element);
    free(s3);

    return 0;
}

