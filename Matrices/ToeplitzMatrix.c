#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  15-02-2022
    Language: C
    Content:  Toeplitz Matrix
*/

struct Matrix
{
    int *A;
    int dimension;
};

void set_value(struct Matrix *m, int i, int j, int value)
{
    if(i==0 || j==0 || i>m->dimension || j>m->dimension)
        printf("Invalid Index!!\n");
    else if(i<=j)
        m->A[j-i] = value;
    else if(i>j)
        m->A[m->dimension + i-j-1] = value;
}


int get_value(struct Matrix m, int i, int j)
{
    if(i==0 || j==0 || i>m.dimension || j>m.dimension)
    {
        printf("Invalid Index!!\n");
        return -1;
    }
    else if(i<=j)
        return m.A[j-i];
    else if(i>j)
        return m.A[m.dimension + i-j-1];
    else
        return 0;
}


void display_matrix(struct Matrix m)
{
    printf("\nPrinting (%d * %d) Toeplitz matrix : \n", m.dimension, m.dimension);
    for(int i=1; i<=m.dimension; i++)
    {
        printf("\t");
        for(int j=1; j<=m.dimension; j++)
            printf("%5d ", get_value(m, i, j));
        printf("\n");
    }
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Toeplitz Matrix in C *****\n\n");

    struct Matrix m;
    int value;

    printf("Enter matrix dimension : ");
    scanf("%d", &m.dimension);
    m.A = (int *) malloc(sizeof(int) * (2*m.dimension-1));

    printf("Enter all values : \n");
    for(int i=1; i<=m.dimension; i++)
    {
        printf("\t");
        for(int j=1; j<=m.dimension; j++)
        {
            scanf("%d", &value);
            set_value(&m, i, j, value);
        }
    }

    display_matrix(m);

    printf("Value in position[0,0] : %d\n\n", get_value(m, 0, 0));
    printf("Setting value in position[0,0] \n");
    set_value(&m, 0, 0, 10);

    free(m.A);
    return 0;
}

