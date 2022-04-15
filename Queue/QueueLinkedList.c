#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  15-04-2022
    Language: C
    Content: Queue using Linked List
*/

struct Queue
{
    int data;
    struct Queue *next;
}*front=NULL, *rear=NULL;


int isFull()
{
    struct Queue *current;
    current = (struct Queue *) malloc(sizeof(struct Queue));
    if(current==NULL)
        return 1;
    return 0;
}

int isEmpty()
{
    if(front==NULL)
        return 1;
    return 0;
}

void enqueueElement(int element)
{
    struct Queue *current;
    current = (struct Queue *) malloc(sizeof(struct Queue));
    if(current==NULL)
        printf("\nQueue Overflow (for %d)!!!\n", element);
    else
    {
        current->data = element;
        current->next = NULL;
        if(front==NULL)
            front = rear = current;
        else
        {
            rear->next = current;
            rear = current;
        }
        printf("\t--<%d is enqueued>--\n", element);
    }
}


int dequeueElement()
{
    struct Queue *current;
    current = (struct Queue *) malloc(sizeof(struct Queue));
    int element = -1;

    if(front==NULL)
        printf("\tQueue Underflow!!!\n");
    else
    {
        current = front;
        element = front->data;
        front = front->next;
        free(current);
        printf("\t--<%d is dequeued>--\n", element);
    }
    return element;
}

int frontElement()
{
    return front->data;
}

int rearElement()
{
    return rear->data;
}


void displayQueue()
{
    struct Queue *current = front;
    printf("Displaying queue\n");
    while(current)
    {
        printf("\t%d", current->data);
        current = current->next;
    }
    printf("\n\n");
}

int main()
{
    printf("\t***** An Example of Queue using Linked List in c *****\n\n");

    enqueueElement(10);
    enqueueElement(20);
    enqueueElement(30);
    enqueueElement(40);
    enqueueElement(50);

    printf("\n");
    displayQueue();

    dequeueElement();
    dequeueElement();

    printf("\n");
    displayQueue();

    return 0;
}



