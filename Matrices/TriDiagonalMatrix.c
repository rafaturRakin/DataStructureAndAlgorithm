#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  14-02-2022
    Language: C
    Content:  Tridiagonal Matrix
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
    else if(i-j==1)
        m->A[i-2] = value;
    else if(i-j==0)
        m->A[m->dimension-1 + i-1] = value;
    else if(i-j==-1)
        m->A[m->dimension-1 + m->dimension + i-1] = value;
}


int get_value(struct Matrix m, int i, int j)
{
    if(i==0 || j==0 || i>m.dimension || j>m.dimension)
    {
        printf("Invalid Index!!\n");
        return -1;
    }
    else if(i-j==1)
        return m.A[i-2];
    else if(i-j==0)
        return m.A[m.dimension-1 + i-1];
    else if(i-j==-1)
        return m.A[m.dimension-1 + m.dimension + i-1];
    else
        return 0;
}


void display_matrix(struct Matrix m)
{
    printf("\nPrinting (%d * %d) Tridiagonal matrix : \n", m.dimension, m.dimension);
    printf("Total maximum non-zero elements : %d\n\n", 3*m.dimension-2);
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
    printf("\t***** An Example of Tridiagonal Matrix in C *****\n\n");

    struct Matrix m;
    int value, size;

    printf("Enter matrix dimension : ");
    scanf("%d", &m.dimension);

    size = 3*m.dimension - 2;
    m.A = (int *) malloc(sizeof(int) * size);

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
