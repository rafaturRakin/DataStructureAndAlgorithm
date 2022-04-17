#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  17-04-2022
    Language: C++
    Content: Queue using Linked List
*/

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    Queue();
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueueElement(int element);
    int dequeueElement();
    int frontElement();
    int rearElement();
    int queueSize();
    void displayQueue();

};

Queue :: Queue()
{
    front = NULL;
    rear = NULL;
    size = 0;
    cout << "\t--<default constructor called>--\n";
}

Queue :: ~Queue()
{
    Node *current = front;
    while(current)
    {
        if(front)
            front = front->next;
        delete current;
        current = front;
    }
    cout << "\t--<destructor called>--\n";
}

bool Queue :: isFull()
{
    Node *current = new Node;
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

void Queue :: enqueueElement(int element)
{
    Node *current = new Node;
    if(current==NULL)
        cout << "\nQueue Overflow (for " << element << ")!!!\n";
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
        ++size;
        cout << "\t--<" << element << " is enqueued>--\n";
    }
}


int Queue :: dequeueElement()
{
    Node *current = new Node;
    int element = -1;

    if(front==NULL)
        cout << "\tQueue Underflow!!!\n";
    else
    {
        current = front;
        element = front->data;
        front = front->next;
        free(current);
        cout << "\t--<" << element << " is dequeued>--\n";
        --size;
    }
    return element;
}

int Queue :: frontElement()
{
    return front->data;
}

int Queue :: rearElement()
{
    return rear->data;
}

int Queue :: queueSize()
{
    return size;
}

void Queue :: displayQueue()
{
    Node *current = front;
    cout << "Displaying (" << queueSize() << " nodes) queue\n";
    while(current)
    {
        cout << "\t" << current->data;
        current = current->next;
    }
    cout << "\n\n";
}

int main()
{
    cout << "\t***** An Example of Queue using Linked List in c++ *****\n\n";

    Queue q;

    q.enqueueElement(10);
    q.enqueueElement(20);
    q.enqueueElement(30);
    q.enqueueElement(40);
    q.enqueueElement(50);

    cout << endl;
    q.displayQueue();

    q.dequeueElement();
    q.dequeueElement();

    cout << endl;
    q.displayQueue();

    return 0;
}
