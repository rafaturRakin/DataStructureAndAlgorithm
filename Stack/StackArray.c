#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  04-04-2022
    Language: C
    Content: Stack using Array
*/

struct Stack
{
    int stackTop;
    int size;
    int *S;
};

void createStack(struct Stack *st)
{
    printf("Enter size of the stack : ");
    scanf("%d", &st->size);
    st->stackTop = -1;
    st->S = (int *) malloc(sizeof(int) * st->size);
    printf("\n");
}

int isFull(struct Stack st)
{
    if(st.stackTop == st.size-1)
        return 1;
    return 0;
}

int isEmpty(struct Stack st)
{
    if(st.stackTop==-1)
        return 1;
    return 0;
}

void pushElement(struct Stack *st, int element)
{
    if(isFull(*st))
        printf("\tStack Overflow (for %d)!!!\n", element);
    else
    {
        st->stackTop++;
        st->S[st->stackTop] = element;
    }
}


int popElement(struct Stack *st)
{
    int element = -1;
    if(isEmpty(*st))
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

int peekElement(struct Stack *st, int index)
{
    int element = -1;
    if(index>st->size || index<1)
        printf("\tInvalid Index!!!\n");
    else
        element = st->S[st->stackTop-index+1];
    return element;
}

void displayStack(struct Stack st)
{
    printf("Displaying %d element stack\n", st.size);
    for(int i=st.stackTop; i>=0; i--)
        printf("\t%d", st.S[i]);
    printf("\n\n");
}

int main()
{
    printf("\t***** An Example of Stack using Array in c *****\n\n");

    struct Stack st;
    createStack(&st);

    pushElement(&st, 10);
    pushElement(&st, 20);
    pushElement(&st, 30);
    pushElement(&st, 40);
    pushElement(&st, 50);
    pushElement(&st, 60);

    displayStack(st);

    printf("Current stack top : %d\n", stackTopPointer(st));
    printf("4 th element is : %d\n", peekElement(&st, 4));
    printf("0 th element is : %d\n", peekElement(&st, 0));

    return 0;
}

