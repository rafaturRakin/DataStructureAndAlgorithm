#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Author: Rakin
    Date:  11-04-2022
    Language: C
    Content: Postfix notation evaluation
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


char stackTop()
{
    if(Top)
        return Top->data;
    return ' ';
}

int isOperand(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 0;
    return 1;
}

int precedenceLevel(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/')
        return 2;
    else
        return 0;
}


char * infixToPostfix(char *infix)
{
    int i=0, j=0;
    int length = strlen(infix);
    char *postfix = (char *) malloc(sizeof(char) * (length+1));

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(Top==NULL)
                pushElement(infix[i++]);
            else if(precedenceLevel(infix[i]) > precedenceLevel(Top->data))
                pushElement(infix[i++]);
            else
                postfix[j++] = popElement();
        }
    }
    while(Top)
        postfix[j++] = popElement();
    postfix[j] = '\0';
    return postfix;
}


int evaluatePostfix(char *postfix)
{
    int length = strlen(postfix);
    int first, second, result;

    for(int i=0; i<length; i++)
    {
        if(isOperand(postfix[i]))
            pushElement(postfix[i]);
        else
        {
            second = popElement()-'0';
            first = popElement()-'0';
            switch(postfix[i])
            {
            case '+':
                result = first + second;
                break;
            case '-':
                result = first - second;
                break;
            case '*':
                result = first * second;
                break;
            case '/':
                result = first / second;
                break;
            }
            pushElement(result+'0');
        }
    }
    return Top->data-'0';
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
    printf("\t***** An Example of evaluation of Postfix notation in c *****\n\n");

    char *infix = "3*5+6/2-4";
    char *postfix = infixToPostfix(infix);
    int evaluation = evaluatePostfix(postfix);

    printf("Infix notation : %s\n", infix);
    printf("Postfix notation : %s\n", postfix);
    printf("Evaluated postfix notation : %d\n", evaluation);

    return 0;
}

