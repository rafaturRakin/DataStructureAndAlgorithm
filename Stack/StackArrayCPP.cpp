#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  05-04-2022
    Language: C++
    Content: Stack using Array
*/

class Stack
{
private:
    int length;
    int *S;
    int Top;

public:
    Stack();
    Stack(int length);
    ~Stack();

    void pushElement(int element);
    int popElement();
    int peekElement(int index);
    bool isEmpty();
    bool isFull();
    int stackTop();
    void displayStack();
};

Stack :: Stack()
{
    cout << "\t-<Default Constructor Called>-\n";
    length = 10;
    Top = -1;
    S = new int[length];
}

Stack :: Stack(int length)
{
    cout << "\t-<Constructor with parameter called>-\n";
    this->length = length;
    Top = -1;
    S = new int[length];
}

Stack :: ~Stack()
{
    cout << "\t-<Destructor Called>-\n";
    delete S;
    Top = -1;
    length = 0;
}

int Stack :: stackTop()
{
    return S[Top];
}

bool Stack :: isEmpty()
{
    if(Top == -1)
    {
        cout << "\t-<Stack is Empty>-\n";
        return true;
    }
    else
    {
        cout << "\t-<Stack is not Empty>-\n";
        return false;
    }
}

bool Stack :: isFull()
{
    if(Top == length-1)
    {
        cout << "\t-<Stack is Full>-\n";
        return true;
    }
    else
    {
        cout << "\t-<Stack is not Full>-\n";
        return false;
    }
}

void Stack :: pushElement(int element)
{
    if(isFull())
        cout << "\t-<Stack Overflow!! (" << element << ")>-\n";
    else
    {
        Top++;
        S[Top] = element;
        cout << "\t-<" << element << " is pushed to top>-\n";
    }
}

int Stack :: popElement()
{
    int element = INT_MIN;
    if(isEmpty())
        cout << "\t-<Stack Underflow!! (" << element << " returned)>-\n";
    else
    {
        element = S[Top];
        Top--;
        cout << "\t-<" << element << " popped from stack>-\n";
    }
    return element;
}

int Stack :: peekElement(int index)
{
    int element = INT_MIN;
    if(index<1 || index>length)
        cout << "\t-<Invalid index. Index must be [" << 1 << ", " << Top+1 << "]>-\n";
    else
        element = S[Top-index+1];
    return element;
}

void Stack :: displayStack()
{
    cout << "Displaying " << Top+1 << " element Stack\n";
    for(int i=Top; i>=0; i--)
        cout << "\t" << S[i];
    cout << endl;
}


int main()
{
    cout << "\t***** An Example of Stack using Array in c *****\n\n";
    Stack st;
    st.pushElement(5);
    st.pushElement(6);
    st.pushElement(7);
    st.displayStack();
    return 0;
}
