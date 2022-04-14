#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  14-04-2022
    Language: C
    Content: Circular Queue using Array
*/

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void createStack(struct Queue *q)
{
    printf("Enter size of the queue : ");
    scanf("%d", &q->size);
    q->front = q->rear = 0;
    q->Q = (int *) malloc(sizeof(int) * q->size);
    printf("\n");
}

int isFull(struct Queue q)
{
    if((q.rear+1)%q.size == q.front)
        return 1;
    return 0;
}

int isEmpty(struct Queue q)
{
    if(q.front==q.rear)
        return 1;
    return 0;
}

void enqueueElement(struct Queue *q, int element)
{
    if(isFull(*q))
        printf("\nQueue Overflow (for %d)!!!\n", element);
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = element;
    }
}


int dequeueElement(struct Queue *q)
{
    int element = -1;
    if(isEmpty(*q))
        printf("\tQueue Underflow!!!\n");
    else
    {
        element = q->Q[q->front];
        q->front = (q->front+1)%q->size;
    }
    return element;
}

int frontElement(struct Queue q)
{
    return q.Q[q.front+1];
}

int rearElement(struct Queue q)
{
    return q.Q[q.rear];
}


void displayQueue(struct Queue q)
{
    printf("Displaying queue\n\t");
    int i = q.front+1;
    do
    {
        printf("%d\t", q.Q[i]);
        i = (i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n\n");
}

int main()
{
    printf("\t***** An Example of Circular Queue using Array in c *****\n\n");

    struct Queue q;
    createStack(&q);

    enqueueElement(&q, 10);
    enqueueElement(&q, 20);
    enqueueElement(&q, 30);
    enqueueElement(&q, 40);
    enqueueElement(&q, 50);
    enqueueElement(&q, 60);

    displayQueue(q);

    dequeueElement(&q);
    dequeueElement(&q);

    displayQueue(q);

    enqueueElement(&q, 50);
    enqueueElement(&q, 60);

    displayQueue(q);
    printf("Front = %d\nRear = %d\n", frontElement(q), rearElement(q));

    return 0;
}

