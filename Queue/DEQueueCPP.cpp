#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  20-04-2022
    Language: C++
    Content: Double Ended Queue using Linked List
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
    int frontElement();
    int rearElement();
    int queueSize();
    void enqueueElement(int element, int direction);
    int dequeueElement(int direction);
    void displayQueue();
};

Queue :: Queue()
{
    front = NULL;
    rear = NULL;
    size = 0;
    cout << "\t--<Default Constructor called>--" << endl;
}

Queue :: ~Queue()
{
    Node *current;
    while(front)
    {
        current = front->next;
        delete front;
        front = current;
    }
    cout << "\t--<Destructor Called>--" << endl;
}

bool Queue :: isFull()
{
    Node *current = new Node;
    if(current)
    {
        cout << "\t--<Queue is not Full>--" << endl;
        delete current;
        return false;
    }
    cout << "\t--<Queue is Full>--" << endl;
    return true;
}

bool Queue :: isEmpty()
{
    if(front)
    {
        cout << "\t--<Queue is not Empty>--" << endl;
        return false;
    }
    cout << "\t--<Queue is Empty>--" << endl;
    return true;
}

void Queue :: enqueueElement(int element, int direction)
{
    Node *current = new Node;
    if(current==NULL)
        cout << "\t-->Queue Overflow!!!<--" << endl;
    else
    {
        current->data = element;
        current->next = NULL;
        if(front==NULL)
        {
            front = current;
            rear = current;
            cout << "\t--<" << element << " is now front and rear>--\n";
        }
        else if(direction==1)
        {
            rear->next = current;
            rear = current;
            cout << "\t--<" << element << " is enqueued from rear end>--\n";
        }
        else
        {
            current->next = front;
            front = current;
            cout << "\t--<" << element << " is enqueued from front end>--\n";
        }
        ++size;
    }
}

int Queue :: dequeueElement(int direction)
{
    Node *current = new Node;
    int element = INT_MIN;

    if(front==NULL)
        cout << "\t-->Queue Underflow!!!<--" << endl;
    else
    {
        if(front==rear)
        {
            current = front;
            front = NULL;
            rear = NULL;
            element = front->data;
            delete current;
            cout << "\t--<" << element << " is dequeued as last element>--\n";
        }
        else if(direction==1)
        {
            current = front;
            front = front->next;
            element = current->data;
            delete current;
            cout << "\t--<" << element << " is dequeued from front end>--\n";
        }
        else
        {
            current = rear;
            element = current->data;
            Node *temp = front;
            while(temp->next!=rear)
                temp = temp->next;
            rear = temp;
            rear->next = NULL;
            delete current;
            cout << "\t--<" << element << " is dequeued from front end>--\n";
        }
        --size;
    }
    return element;
}

int Queue :: frontElement()
{
    cout << "\t--<Current Front : " << front->data << ">--\n";
    return front->data;
}

int Queue :: rearElement()
{
    cout << "\t--<Current Rear : " << rear->data << ">--\n";
    return rear->data;
}

int Queue :: queueSize()
{
    cout << "\t--<Current Size : " << size << ">--";
    return size;
}

void Queue :: displayQueue()
{
    Node *current = front;
    cout << "Displaying (" << size << " elements) queue:\n";
    while(current)
    {
        cout << "\t" << current->data;
        current = current->next;
    }
    cout << "\n\n";
}

int main()
{
    cout << "\t***** An Example of Double Ended Queue using Linked List in c++ *****\n\n";

    Queue q;

    q.enqueueElement(10, 0);
    q.enqueueElement(20, 0);
    q.enqueueElement(30, 1);
    q.enqueueElement(40, 1);
    q.enqueueElement(50, 0);

    cout << endl;
    q.displayQueue();

    q.dequeueElement(1);
    q.dequeueElement(0);

    cout << endl;
    q.frontElement();
    q.rearElement();

    cout << endl;
    q.queueSize();

    cout << endl;
    q.displayQueue();

    return 0;
}

