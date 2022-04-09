#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  09-04-2022
    Language: C++
    Content: Bracket Matching
*/

class Node
{
public:
    char data;
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

    void pushElement(char element);
    char popElement();
    bool isEmpty();
    bool isFull();
    char stackTop();
    char peekElement(int index);
    void displayStack();
    bool isBracketMatching(string expression);
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

void Stack :: pushElement(char element)
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

char Stack :: popElement()
{
    char element = ' ';
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

char Stack :: stackTop()
{
    return top->data;
}

char Stack :: peekElement(int index)
{
    char element = ' ';
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

bool Stack :: isBracketMatching(string expression)
{
    int length = expression.size();
    for(int i=0; i<length; i++)
    {
        if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[')
            pushElement(expression[i]);
        else if(expression[i]==')' || expression[i]=='}' || expression[i]==']')
        {
            if(top)
            {
                char ch = popElement();
                if( (expression[i]==')' && expression[i]-ch==1) || (expression[i]-ch==2))
                    continue;
                else
                    return false;
            }
            else
                return false;
        }
    }

    if(top)
        return false;
    else
        return true;
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
    cout << "\t***** An Example of Bracket Matching using Stack in C++ *****\n\n";

    Stack st;
    string expression = "[{()}]([]({[a+b]}){})";
    bool result = st.isBracketMatching(expression);

    cout << "\n\tExpression is : " << expression << endl;
    if(result)
        cout << "\tBracket Matched\n";
    else
        cout << "\tNot matched\n";

    return 0;
}

