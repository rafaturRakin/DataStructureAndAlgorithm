#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"


struct Stack
{
    int stackTop;
    int size;
    struct Node **S;
};

void createStack(struct Stack *st, int sz)
{
    st->size = sz;
    st->stackTop = -1;
    st->S = (struct Node **) malloc(sizeof(struct Node *) * st->size);
}

int isStackFull(struct Stack st)
{
    if(st.stackTop == st.size-1)
        return 1;
    return 0;
}

int isStackEmpty(struct Stack st)
{
    if(st.stackTop==-1)
        return 1;
    return 0;
}

void pushElement(struct Stack *st, struct Node * element)
{
    if(isStackFull(*st))
        printf("\tStack Overflow!!!\n");
    else
    {
        st->stackTop++;
        st->S[st->stackTop] = element;
    }
}


struct Node * popElement(struct Stack *st)
{
    struct Node * element = NULL;
    if(isStackEmpty(*st))
        printf("\tStack Underflow!!!\n");
    else
    {
        element = st->S[st->stackTop];
        st->stackTop--;
    }
    return element;
}

int stackTopPointer(struct Stack st)
{
    return st.stackTop;
}

#endif // STACK_H_INCLUDED
