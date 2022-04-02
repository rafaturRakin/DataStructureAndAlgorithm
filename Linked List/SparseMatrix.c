#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  02-04-2022
    Language: C
    Content:  Sparse Matrix using Linked List
*/

struct Node
{
    int row;
    int column;
    int data;
    struct Node *next;
};

struct Node * createMatrix(int elements)
{
    struct Node *first, *currentNode, *temp;
    int r, c, v;
    printf("Enter (row, column, value) elements\n");
    printf("\tEnter element #%d : ", 1);
    scanf("%d %d %d", &r, &c, &v);
    currentNode = (struct Node *) malloc(sizeof(struct Node));
    currentNode->data = v;
    currentNode->row = r;
    currentNode->column = c;
    currentNode->next = NULL;
    first = currentNode;
    for(int i=1; i<elements; i++)
    {
        printf("\tEnter element #%d : ", i+1);
        scanf("%d %d %d", &r, &c, &v);
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = v;
        temp->row = r;
        temp->column = c;
        temp->next = NULL;
        currentNode->next = temp;
        currentNode = temp;
    }
    return first;
}

/*
struct Node * addMatrix(struct Node *first, struct Node *second)
{
    struct Node *third, *currentNode, *temp;
    if(first->row < second->row)
    {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->row = first->row;
        temp->column = first->column;
        temp->data = first->data;
        temp->next = NULL;
        third = temp;
        currentNode = temp;
        first = first->next;
    }
    else if(first->row > second->row)
    {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->row = second->row;
        temp->column = second->column;
        temp->data = second->data;
        temp->next = NULL;
        third = temp;
        currentNode = temp;
        second = second->next;
    }
    else
    {
        if(first->column < second->column)
        {
            temp = (struct Node *) malloc(sizeof(struct Node));
            temp->row = first->row;
            temp->column = first->column;
            temp->data = first->data;
            temp->next = NULL;
            third = temp;
            currentNode = temp;
            first = first->next;
        }
        else if(first->column > second->column)
        {
            temp = (struct Node *) malloc(sizeof(struct Node));
            temp->row = second->row;
            temp->column = second->column;
            temp->data = second->data;
            temp->next = NULL;
            third = temp;
            currentNode = temp;
            second = second->next;
        }
        else
        {
            temp = (struct Node *) malloc(sizeof(struct Node));
            temp->row = second->row;
            temp->column = second->column;
            temp->data = first->data + second->data;
            temp->next = NULL;
            third = temp;
            currentNode = temp;
            first = first->next;
            second = second->next;
        }
    }
    while(first && second)
    {
        if(first->row < second->row)
        {
            temp = (struct Node *) malloc(sizeof(struct Node));
            temp->row = first->row;
            temp->column = first->column;
            temp->data = first->data;
            temp->next = NULL;
            currentNode->next = temp;
            currentNode = temp;
            first = first->next;
        }
        else if(first->row > second->row)
        {
            temp = (struct Node *) malloc(sizeof(struct Node));
            temp->row = second->row;
            temp->column = second->column;
            temp->data = second->data;
            temp->next = NULL;
            currentNode->next = temp;
            currentNode = temp;
            second = second->next;
        }
        else
        {
            if(first->column < second->column)
            {
                temp = (struct Node *) malloc(sizeof(struct Node));
                temp->row = first->row;
                temp->column = first->column;
                temp->data = first->data;
                temp->next = NULL;
                currentNode->next = temp;
                currentNode = temp;
                first = first->next;
            }
            else if(first->column > second->column)
            {
                temp = (struct Node *) malloc(sizeof(struct Node));
                temp->row = second->row;
                temp->column = second->column;
                temp->data = second->data;
                temp->next = NULL;
                currentNode->next = temp;
                currentNode = temp;
                second = second->next;
            }
            else
            {
                temp = (struct Node *) malloc(sizeof(struct Node));
                temp->row = second->row;
                temp->column = second->column;
                temp->data = first->data + second->data;
                temp->next = NULL;
                currentNode->next = temp;
                currentNode = temp;
                first = first->next;
                second = second->next;
            }
        }
    }
    while(first)
    {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->row = first->row;
        temp->column = first->column;
        temp->data = first->data;
        temp->next = NULL;
        currentNode->next = temp;
        currentNode = temp;
        first = first->next;
    }

    while(second)
    {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->row = second->row;
        temp->column = second->column;
        temp->data = second->data;
        temp->next = NULL;
        currentNode->next = temp;
        currentNode = temp;
        second = second->next;
    }

    return third;
}
*/

void displayMatrix(struct Node *first, int row, int col, int nonzero)
{
    struct Node *currentNode = first;
    printf("Printing %d non-zero elements sparse matrix\n");
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            if(currentNode && currentNode->row==i && currentNode->column==j)
            {
                printf("\t%d", currentNode->data);
                currentNode = currentNode->next;
            }
            else
                printf("\t%d", 0);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    printf("\t***** An Example of Sparse Matrix using Linked List in C *****\n\n");

    int row, col, nonZero, value;
    struct Node *first, *second;
    printf("Enter the dimension (row, column) of the matrix : ");
    scanf("%d %d", &row, &col);

    printf("How many Non zero elements? : ");
    scanf("%d", &nonZero);

    first = createMatrix(nonZero);
    displayMatrix(first, row, col, nonZero+nonZero);
    return 0;
}
