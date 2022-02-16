#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  16-02-2022
    Language: C
    Content:  Menu Driven (Matrix)
*/

struct Matrix
{
    int *A;
    int dimension;
};

void display_menu()
{
    printf("\t\t***** Matrix Menu *****\n");
    printf("\t1. Create Matrix\n");
    printf("\t2. Get value\n");
    printf("\t3. Set value\n");
    printf("\t4. Display Matrix\n");
    printf("\t5. Exit\n");
}

struct Matrix* create_matrix(int d)
{
  struct Matrix *m = NULL;
  m = (struct Matrix*) malloc(sizeof(struct Matrix));
  m->A = (int *) malloc(sizeof(int) * d);
  m->dimension = d;

  for(int i=0; i<d; i++)
  {
      m->A[i] = 1;
  }
  return m;
}

void set_value(struct Matrix *m, int i, int j, int value)
{
    if(m==NULL)
    {
        printf("Matrix not created\n");
        return;
    }

    if(i==0 || j==0 || i>m->dimension || j>m->dimension)
        printf("Invalid Index!!\n");
    else
        m->A[i-1] = value;
}


int get_value(struct Matrix *m, int i, int j)
{
    if(m==NULL)
    {
        printf("Matrix not created\n");
        return -1;
    }

    if(i==0 || j==0 || i>m->dimension || j>m->dimension)
    {
        printf("Invalid Index!!\n");
        return -1;
    }
    else if(i==j)
        return m->A[i-1];
    else
        return 0;
}


void display_matrix(struct Matrix *m)
{
    if(m==NULL)
    {
        printf("Matrix not created\n");
        return;
    }

    printf("\nPrinting (%d * %d) diagonal matrix : \n", m->dimension, m->dimension);
    for(int i=1; i<=m->dimension; i++)
    {
        printf("\t");
        for(int j=1; j<=m->dimension; j++)
            printf("%5d ", get_value(m, i, j));
        printf("\n");
    }
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Menu Driven Program for Matrix in C *****\n\n");

    struct Matrix *m = NULL;
    int value, dimension, i, j, choice;

    do
    {
        display_menu();
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter matrix dimension : ");
            scanf("%d", &dimension);
            m = create_matrix(dimension);
            break;
        case 2:
            printf("Enter i and j : ");
            scanf("%d %d", &i, &j);
            printf("Value at index [%d , %d] = %d\n", i, j, get_value(m, i, j));
            break;
        case 3:
            printf("Enter i, j and value : ");
            scanf("%d %d %d", &i, &j, &value);
            set_value(m, i, j, value);
            break;
        case 4:
            display_matrix(m);
            break;
        case 5:
            printf("Exiting program...\n\n");
            break;
        default:
            printf("Invalid Input!!");
            break;
        }

    } while(choice>=1  && choice<5);

    printf("Thank You.\n");
    return 0;
}

