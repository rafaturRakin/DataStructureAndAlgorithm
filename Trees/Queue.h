#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *leftChild;
    int data;
    struct Node *rightChild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node ** Q;
};

void createQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **) malloc(sizeof(struct Node *) * q->size);
}

int isFull(struct Queue *q)
{
    if((q->rear+1)%q->size == q->front)
        return 1;
    return 0;
}

int isEmpty(struct Queue *q)
{
    if(q->front==q->rear)
        return 1;
    return 0;
}

void enqueueElement(struct Queue *q, struct Node *node)
{
    if(isFull(q))
        printf("\t--<Queue Overflow>--\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = node;
    }
}


struct Node * dequeueElement(struct Queue *q)
{
    struct Node * node = NULL;
    if(isEmpty(q))
        printf("\t--<Queue Underflow>--\n");
    else
    {
        q->front = (q->front+1)%q->size;
        node = q->Q[q->front];
    }
    return node;
}

struct Node * frontElement(struct Queue *q)
{
    return q->Q[(q->front+1)%q->size];
}

struct Node * rearElement(struct Queue *q)
{
    return q->Q[q->rear];
}


#endif // QUEUE_H_INCLUDED
