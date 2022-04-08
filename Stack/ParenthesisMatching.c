#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Author: Rakin
    Date:  08-04-2022
    Language: C
    Content: Parenthesis Matching
*/

struct Node
{
    char data;
    struct Node *next;
} *Top = NULL;


int isFull()
{
    struct Node *current = (struct Node *) malloc(sizeof(struct Node));
    if(current)
    {
        free(current);
        return 0;
    }
    return 1;
}

int isEmpty(struct Node *current)
{
    if(current)
        return 0;
    return 1;
}

void pushElement(char element)
{
    struct Node *current = (struct Node*) malloc(sizeof(struct Node));
    if(current)
    {
        printf("\t-<%c is pushed>-\n", element);
        current->data = element;
        current->next = Top;
        Top = current;
    }
    else
        printf("\t-<Stack Overflow!!>-\n");
}

char popElement()
{
    char x = ' ';
    if(Top)
    {
        struct Node *current = Top;
        Top = Top->next;
        x = current->data;
        printf("\t-<%c is popped from stack>-\n", current->data);
        free(current);
    }
    else
        printf("\t-<Stack Underflow\n>-\n");
    return x;
}


void peekElement(int index)
{
    if(index<1)
    {
        printf("\t-<Invalid Index!!>-\n");
        return;
    }

    struct Node *current = Top;
    for(int i=0; current && i<index-1; i++)
        current = current->next;
    if(current)
        printf("\t%c is in position %d\n", current->data, index);
    else
        printf("\t-<Invalid Index!!\n>-");
}

void stackTop()
{
    if(Top)
        printf("\t%c is stack top\n", Top->data);
    else
        printf("\t-<Stack is Empty>-\n");
}

int isBalanced(char *exp)
{
    int length = strlen(exp);
    for(int i=0; i<length; i++)
    {
        if(exp[i]=='(')
            pushElement(exp[i]);
        else if(exp[i]==')')
        {
            if(Top)
                popElement();
            else
                return 0;
        }
    }

    if(Top==NULL)
        return 1;
    else
        return 0;
}


void displayStack()
{
    struct Node *current = Top;
    printf("\nDisplaying stack...\n");
    while(current)
    {
        printf("\t%c", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    printf("\t***** An Example of Parenthesis Matching in c *****\n\n");

    char *expression = "()()((a+b)-(c*d))()";

    if(isBalanced(expression))
        printf("\n%s is balanced\n", expression);
    else
        printf("\n%s is not balanced\n", expression);

    return 0;
}
