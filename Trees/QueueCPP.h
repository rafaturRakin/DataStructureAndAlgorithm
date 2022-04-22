#ifndef QUEUECPP_H_INCLUDED
#define QUEUECPP_H_INCLUDED

#include<iostream>

using namespace std;
class Node
{
public:
    Node *leftChild;
    int data;
    Node *rightChild;
};


class Link
{
public:
    Node *node;
    Link *next;
};


class Queue
{
private:
    Link *front;
    Link *rear;
    int size;

public:
    Queue();
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueueElement(Node *element);
    Node * dequeueElement();
    Node * frontElement();
    Node * rearElement();
    int queueSize();
    void displayQueue();
};

Queue :: Queue()
{
    front = NULL;
    rear = NULL;
    size = 0;
}

Queue :: ~Queue()
{
    Link *current = front;
    while(current)
    {
        if(front)
            front = front->next;
        delete current;
        current = front;
    }
}

bool Queue :: isFull()
{
    Link *current = new Link;
    if(current==NULL)
        return true;
    return false;
}

bool Queue :: isEmpty()
{
    if(front==NULL)
        return true;
    return false;
}

void Queue :: enqueueElement(Node * element)
{
    Link *current = new Link;
    if(current==NULL)
        cout << "\nQueue Overflow!!!\n";
    else
    {
        current->node = element;
        current->next = NULL;
        if(front==NULL)
            front = rear = current;
        else
        {
            rear->next = current;
            rear = current;
        }
        ++size;
    }
}


Node * Queue :: dequeueElement()
{
    Link *current = new Link;
    Node * element = NULL;

    if(front==NULL)
        cout << "\tQueue Underflow!!!\n";
    else
    {
        current = front;
        element = front->node;
        front = front->next;
        delete current;
        --size;
    }
    return element;
}

Node * Queue :: frontElement()
{
    return front->node;
}

Node * Queue :: rearElement()
{
    return rear->node;
}

int Queue :: queueSize()
{
    return size;
}

void Queue :: displayQueue()
{
    Link *current = front;
    cout << "Displaying (" << queueSize() << " nodes) queue\n";
    while(current)
    {
        cout << "\t" << current->node->data;
        current = current->next;
    }
    cout << "\n\n";
}
#endif // QUEUECPP_H_INCLUDED
