#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  21-02-2022
    Language: C
    Content:  Sparse Matrix
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
    printf("\t***** An Example of Sparse Matrix in C *****\n\n");

    struct SparseMatrix s1, s2;

    create_matrix(&s1);
    printf("\n");
    create_matrix(&s2);

    printf("Matrix: #01");
    display_matrix(s1);

    printf("Matrix: #02");
    display_matrix(s2);

    free(s1.element);
    free(s2.element);

    return 0;
}
