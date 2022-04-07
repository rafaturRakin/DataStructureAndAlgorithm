#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  07-04-2022
    Language: C++
    Content: Stack using Linked List
*/

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
    int size;

public:
    Stack();
    ~Stack();

    void pushElement(int element);
    int popElement();
    bool isEmpty();
    bool isFull();
    int stackTop();
    int peekElement(int index);
    void displayStack();
};

Stack :: Stack()
{
    top = NULL;
    size = 0;
}

Stack :: ~Stack()
{
    Node *current = top;
    while(current)
    {
        if(top)
            top = top->next;
        delete current;
        current = top;
    }
}

void Stack :: pushElement(int element)
{
    Node *current = new Node;
    if(current)
    {
        current->data = element;
        current->next = top;
        top = current;
        ++size;
        cout << "\t-<..." << element << " is pushed...>-\n";
    }
    else
        cout << "\t-<...Stack is Full!!!...>-\n";
}

int Stack :: popElement()
{
    int element = INT_MIN;
    Node *current;
    if(top)
    {
        current = top;
        element = current->data;
        top = top->next;
        cout << "\t-<..." << element << " popped from Stack...>-\n";
        --size;
        delete current;
    }
    else
        cout << "\t-<...Stack is Empty!!!...>-\n";
    return element;
}

bool Stack :: isFull()
{
    Node *current;
    if(current)
        return false;
    return true;
}

bool Stack :: isEmpty()
{
    if(top)
        return false;
    return true;
}

int Stack :: stackTop()
{
    return top->data;
}

int Stack :: peekElement(int index)
{
    int element = INT_MIN;
    Node *current = top;
    if(index<1 || index>size)
        cout << "\t-<...Invalid Index!!!...>-\n";
    else
    {
        for(int i=0; i<index-1; i++)
            current = current->next;
        element = current->data;
    }
    return element;
}

void Stack :: displayStack()
{
    Node *current = top;
    cout << "\nDisplaying " << size << " element(s) Stack : \n\t";
    while(current)
    {
        cout << current->data << "\t";
        current = current->next;
    }
    cout << endl << endl;
}

int main()
{
    cout << "\t***** An Example of Stack using Linked List in c++ *****\n\n";

    Stack st;
    cout << "Is Full : " << (st.isFull() ? "Yes" : "No") << endl;
    cout << "Is Empty : " << (st.isEmpty() ? "Yes" : "No") << endl;

    st.pushElement(5);
    st.pushElement(15);
    st.pushElement(25);
    st.pushElement(35);
    st.pushElement(45);

    st.displayStack();

    cout << "Stack top is : " << st.stackTop() << endl;
    cout << "Element at index #3 is : " << st.peekElement(3) << endl;

    st.popElement();
    st.popElement();
    st.popElement();

    st.displayStack();

    cout << "Stack top is : " << st.stackTop() << endl;
    cout << "Is Full : " << (st.isFull() ? "Yes" : "No") << endl;
    cout << "Is Empty : " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
