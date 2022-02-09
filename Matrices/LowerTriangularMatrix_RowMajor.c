#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  09-02-2022
    Language: C
    Content:  Lower Triangular Matrix (Row Major)
*/

struct Matrix
{
    int *A;
    int dimension;
};

void set_value(struct Matrix *m, int i, int j, int value)
{
    int index;
    if(i==0 || j==0 || i>m->dimension || j>m->dimension)
        printf("Value not set!! Invalid Index (%d, %d)!!\n", i, j);
    else if(i>=j)
    {
        index = i*(i-1)/2 + j-1;
        m->A[index] = value;
    }
}


int get_value(struct Matrix m, int i, int j)
{
    int index;
    if(i==0 || j==0 || i>m.dimension || j>m.dimension)
    {
        printf("No value in this Invalid Index(%d, %d)!!\n", i, j);
        return -1;
    }
    else if(i>=j)
    {
        index = i*(i-1)/2 + j-1;
        return m.A[index];
    }
    else
        return 0;
}


void display_matrix(struct Matrix m)
{
    printf("\nPrinting (%d * %d) upper triangular matrix using row major mapping : \n", m.dimension, m.dimension);
    printf("Maximum non-zero elements : %d\n", m.dimension*(m.dimension+1)/2);
    printf("Minimum zero elements : %d\n\n", m.dimension*(m.dimension-1)/2);

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
    printf("\t***** An Example of Lower Triangular Matrix (Row major mapping) in C *****\n\n");

    struct Matrix m;
    int value;

    printf("Enter matrix dimension : ");
    scanf("%d", &m.dimension);
    m.A = (int *) malloc(sizeof(int) * m.dimension*(m.dimension+1)/2);

    printf("Enter values : \n");
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

    printf("main() : Value in position[0,0] : %d\n\n", get_value(m, 0, 0));
    printf("main() : Setting value in position[0,0] \n");
    set_value(&m, 0, 0, 10);

    free(m.A);
    return 0;
}
