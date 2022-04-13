#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  13-04-2022
    Language: C++
    Content: Queue using Array
*/

template<class T>
class Queue
{
private:
    int size;
    int front;
    int rear;
    T *Q;
    int qLength;

public:
    Queue();
    Queue(int length);
    ~Queue();

    void enqueueElement(T x);
    T dequeElement();
    T frontElement();
    T rearElement();
    int queueSize();
    int queueLength();
    void displayQueue();
};

template <class T>
Queue<T> :: Queue()
{
    front = -1;
    rear = -1;
    size = 10;
    qLength = 0;
    Q = new T[size];
    cout << "\t--<Constructor with no parameter called>--\n";
}

template<class T>
Queue<T> :: Queue(int length)
{
    front = -1;
    rear = -1;
    size = length;
    qLength = 0;
    Q = new T[size];
    cout << "\t--<Constructor with parameter called>--\n";
}

template<class T>
Queue<T> :: ~Queue()
{
    front = -1;
    rear = -1;
    size = 0;
    qLength = 0;
    delete [] Q;
    cout << "\t--<Destructor called>--\n";
}

template<class T>
void Queue<T> :: enqueueElement(T element)
{
    if(rear == size-1)
        cout << "\t...Queue Overflow!!! " << element << " not queued...\n";
    else
    {
        ++rear;
        Q[rear] = element;
        ++qLength;
        cout << "\t--< " << element << " queued>--\n";
    }
}

template<class T>
T Queue<T> :: dequeElement()
{
    T element;
    if(front == rear)
        cout << "\t...Queue Underflow!!! Nothing is dequeued...\n";
    else
    {
        front++;
        --qLength;
        element = Q[front];
    }
    cout << "\t--< " << element << " dequeued>--\n";
    return element;
}

template<class T>
T Queue<T> :: frontElement()
{
    T element;
    if(front==rear)
        element = -1;
    else
        element = Q[front+1];
    cout << "\t--< " << element << " is front element>--\n";
    return element;
}

template<class T>
T Queue<T> :: rearElement()
{
    T element;
    if(front==rear)
        element = -1;
    else
        element = Q[rear];
    cout << "\t--< " << element << " is rear element>--\n";
    return element;
}

template<class T>
int Queue<T> :: queueSize()
{
    cout << "\t--< " << size << " is queue size>--\n";
    return size;
}

template<class T>
void Queue<T> :: displayQueue()
{
    cout << "Displaying " << qLength << " element Queue\n";
    for(int i=front+1; i<=rear; i++)
        cout << "\t" << Q[i] << " ";
    cout << endl << endl;
}

int main()
{
    cout << "\t***** An Example of Queue using Array in c++ *****\n\n";
    Queue<string> q(5);

    q.enqueueElement("1");
    q.enqueueElement("2");
    q.enqueueElement("3");
    q.enqueueElement("r");
    q.enqueueElement("a");
    q.enqueueElement("c");

    cout << endl;
    q.frontElement();
    q.rearElement();

    cout << endl;
    q.displayQueue();


    q.dequeElement();
    q.dequeElement();

    cout << endl;
    q.frontElement();
    q.rearElement();

    cout << endl;
    q.displayQueue();

    cout << endl;
    q.dequeElement();
    q.dequeElement();
    q.dequeElement();
    q.dequeElement();

    cout << endl;
    q.frontElement();
    q.rearElement();

    cout << endl;
    q.displayQueue();

    return 0;
}
