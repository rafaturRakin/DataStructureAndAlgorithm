#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  16-04-2022
    Language: C
    Content: Double Ended Queue using Linked List
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

    free(current);
    return 0;
}

int isEmpty()
{
    if(front==NULL)
        return 1;
    return 0;
}

void enqueueElement(int element, int side)
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
        {
            front = current;
            rear = current;
            printf("\t--<%d is now front and rear>--\n", element);
        }
        else if(side==1)
        {
            rear->next = current;
            rear = current;
            printf("\t--<%d is enqueued in rear end>--\n", element);
        }
        else
        {
            current->next = front;
            front = current;
            printf("\t--<%d is enqueued in front end>--\n", element);
        }
    }
}

int dequeueElement(int side)
{
    struct Queue *current;
    current = (struct Queue *) malloc(sizeof(struct Queue));
    int element = -1;

    if(front==NULL)
        printf("\tQueue Underflow!!!\n");
    else
    {
        if(front==rear)
        {
            current = front;
            element = front->data;
            front = NULL;
            rear = NULL;
            free(current);
            printf("\t--<%d is dequeued as last element>--\n", element);
        }
        else if(side==1)
        {
            current = front;
            element = current->data;
            front = front->next;
            free(current);
            printf("\t--<%d is dequeued from front side>--\n", element);
        }
        else
        {
            current = rear;
            element = current->data;
            struct Queue *temp = front;
            while(temp->next!=rear)
                temp = temp->next;
            rear = temp;
            rear->next = NULL;
            free(current);
            printf("\t--<%d is dequeued from rear side>--\n", element);
        }
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
    printf("\t***** An Example of Double Ended Queue using Linked List in c *****\n\n");

    enqueueElement(10, 0);
    enqueueElement(20, 0);
    enqueueElement(30, 1);
    enqueueElement(40, 1);
    enqueueElement(50, 0);

    printf("\n");
    displayQueue();

    dequeueElement(1);
    dequeueElement(0);

    printf("\n");
    printf("Current front : %d\n", frontElement());
    printf("Current rear : %d\n", rearElement());

    printf("\n");
    displayQueue();

    return 0;
}
