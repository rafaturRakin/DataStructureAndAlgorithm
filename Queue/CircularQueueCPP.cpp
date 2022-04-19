#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  19-04-2022
    Language: C++
    Content: Circular Queue using Array in C++
*/

class Queue
{
private:
    int size;
    int front;
    int length;
    int rear;
    int *Q;

public:
    Queue();
    Queue(int sz);
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
    size = 10;
    front = 0;
    rear = 0;
    length = 0;
    Q = new int[size];
    cout << "\t--<default constructor called>--" << endl;
}


Queue :: Queue(int sz)
{
    size = sz;
    front = 0;
    rear = 0;
    length = 0;
    Q = new int[size];
    cout << "\t--<constructor with size called>--" << endl;
}

Queue :: ~Queue()
{
    size = 0;
    front = 0;
    rear = 0;
    length = 0;
    delete [] Q;
    cout << "\t--<destructor called>--" << endl;
}

bool Queue :: isFull()
{
    if((rear+1)%size == front)
    {
        cout << "\t--<Queue is Full>--" << endl;
        return true;
    }
    cout << "\t--<Queue is not Full>--" << endl;
    return 0;
}

bool Queue :: isEmpty()
{
    if(front==rear)
    {
        cout << "\t--<Queue is Empty>--" << endl;
        return true;
    }
    cout << "\t--<Queue is not Full>--" << endl;
    return 0;
}

void Queue :: enqueueElement(int element)
{
    if(this->isFull())
        cout << "\nQueue Overflow (for " << element << ")!!!" << endl;
    else
    {
        rear = (rear+1)%size;
        Q[rear] = element;
    }
}


int Queue :: dequeueElement()
{
    int element = -1;
    if(this->isEmpty())
        cout << "\tQueue Underflow!!!\n";
    else
    {
        element = Q[front];
        front = (front+1)%size;
    }
    return element;
}

int Queue :: frontElement()
{
    return Q[front+1];
}

int Queue :: rearElement()
{
    return Q[rear];
}

int Queue :: queueSize()
{
    return size;
}

void Queue :: displayQueue()
{
    cout << "Displaying queue\n\t";
    int i = front+1;
    do
    {
        cout << "\t" << Q[i];
        i = (i+1)%size;
    }while(i!=(rear+1)%size);
    cout << "\n\n";
}

int main()
{
    cout << "\t***** An Example of Circular Queue using Array in c++ *****\n\n";

    Queue q(5);

    q.enqueueElement(10);
    q.enqueueElement(20);
    q.enqueueElement(30);
    q.enqueueElement(40);
    q.enqueueElement(50);
    q.enqueueElement(60);

    q.displayQueue();

    q.dequeueElement();
    q.dequeueElement();

    q.displayQueue();

    q.enqueueElement(50);
    q.enqueueElement(60);

    q.displayQueue();

    cout << "Front = " << q.frontElement() << endl;
    cout << "Rear = " << q.rearElement() << endl;

    return 0;
}


