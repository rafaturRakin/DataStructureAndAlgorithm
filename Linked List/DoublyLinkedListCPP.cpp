#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  27-03-2022
    Language: C++
    Content:  Doubly Linked List
*/


class Node
{
public:
    Node *previous;
    Node *next;
    int data;
};

class DoublyLinkedList
{
private:
    Node *first;
    Node *last;
    int length;

public:
    DoublyLinkedList();
    DoublyLinkedList(int len);
    DoublyLinkedList(int arr[], int len);

    ~DoublyLinkedList();

    void displayList();
    int sum();
    double average();
    int maximum();
    int minimum();
    bool searchNode(int key);
    void insertNode(int index, int value);
    int removeNode(int index);
    void reverseList();
    bool isSorted();
    bool hasLoop();
};


DoublyLinkedList :: DoublyLinkedList()
{
    first = NULL;
    last = NULL;
    length = 0;
    cout << "Default Constructor Called. " << length << " length linked list created\n\n";
}


DoublyLinkedList :: DoublyLinkedList(int len)
{
    if(len > 0)
    {
        int value;
        Node * current_node;
        cout << "\tEnter value of #1 node : ";
        cin >> value;

        length = len;
        first = new Node;
        first->data = value;
        first->previous = NULL;
        first->next = NULL;
        last = first;

        for(int i=1; i<length; i++)
        {
            cout << "\tEnter value of #" << i+1 << " node : ";
            cin >> value;
            current_node = new Node;
            current_node->data = value;
            current_node->previous = last;
            current_node->next = NULL;
            last->next = current_node;
            last = current_node;
        }

        cout << "Constructor with length value called. " << length << " length linked list created\n" << endl;
    }
    else
    {
        cout << "Invalid Length!!! 0 length list created...\n\n";
        first = NULL;
        last = NULL;
        length = 0;
    }
}


DoublyLinkedList :: DoublyLinkedList(int arr[], int len)
{
    if(len > 0)
    {
        Node * current_node;

        first = new Node;
        first->data = arr[0];
        first->previous = NULL;
        first->next = NULL;
        last = first;

        for(int i=1; i<len; i++)
        {
            current_node = new Node;
            current_node->data = arr[i];
            current_node->next = NULL;
            current_node->previous = last;
            last->next = current_node;
            last = current_node;
        }

        length = len;
        cout << "Constructor with array called. " << length << " length linked list created\n\n";
    }
    else
    {
        cout << "Invalid Length value!!! 0 length linked list created\n\n";
        first = NULL;
        last = NULL;
        length = 0;
    }
}



DoublyLinkedList :: ~DoublyLinkedList()
{
    Node *current_node;
    while(first)
    {
        current_node = first;
        first = first->next;
        delete current_node;
    }
}


void DoublyLinkedList :: displayList()
{
    Node *current_node = first;

    cout << "Displaying " << length << " node doubly linked list\n";
    while(current_node)
    {
        cout << "\t" << current_node->data;
        current_node = current_node->next;
    }
    cout << endl;
}

int DoublyLinkedList :: sum()
{
    Node *current_node = first;
    int total = 0;
    while(current_node)
    {
        total += current_node->data;
        current_node = current_node->next;
    }
    cout << "\tTotal = " << total << endl;
    return total;
}


double DoublyLinkedList :: average()
{
    int total = sum();
    double avg = double(total) / double(length);
    cout << "\tAverage = " << avg << endl;
    return avg;
}


int DoublyLinkedList :: maximum()
{
    Node * current_node = first;
    int maxValue = first->data;
    while(current_node)
    {
        if(current_node->data > maxValue)
            maxValue = current_node->data;
        current_node = current_node->next;
    }
    cout << "\tMaximum = " << maxValue << endl;
    return maxValue;
}


int DoublyLinkedList :: minimum()
{
    Node *current_node = first;
    int minValue = first->data;
    while(current_node)
    {
        if(current_node->data < minValue)
            minValue = current_node->data;
        current_node = current_node->next;
    }
    cout << "\tMinimum = " << minValue << endl;
    return minValue;
}

bool DoublyLinkedList :: searchNode(int key)
{
    Node *current_node = first;
    int counter = 1;
    while(current_node)
    {
        if(current_node->data == key)
        {
            cout << "\tFound at node #" << counter << endl;
            return true;
        }
        current_node = current_node->next;
        ++counter;
    }
    cout << "\t" << key << " is not a node in the list" << endl;
    return false;
}


void DoublyLinkedList :: insertNode(int index, int value)
{
    if(index<0 || index>length)
    {
        cout << "\tInvalid Index!!! Index must be between [0, " << length << "]\n";
        return;
    }

    Node * current_node = new Node;
    if(first==NULL)
    {
        current_node->data = value;
        current_node->previous = NULL;
        current_node->next = NULL;
        first = current_node;
        last = first;
        cout << "\t" << value << " inserted as first and last node\n";
    }
    else if(index==0)
    {
        current_node->data = value;
        current_node->previous = NULL;
        current_node->next = first;
        first->previous = current_node;
        first = current_node;
        cout << "\t" << value << " inserted as first node\n";
    }
    else if(index==length)
    {
        current_node->data = value;
        current_node->next = NULL;
        current_node->previous = last;
        last->next = current_node;
        last = current_node;
        cout << "\t" << value << " inserted as last node\n";
    }
    else
    {
        Node *temp_node = first;
        for(int i=0; i<index-1; i++)
            temp_node = temp_node->next;
        current_node->data = value;
        current_node->previous = temp_node;
        current_node->next = temp_node->next;
        temp_node->next->previous = current_node;
        temp_node->next = current_node;
        cout << "\t" << value << " inserted after node #" << index << "\n";
    }
    ++length;
}

int DoublyLinkedList :: removeNode(int index)
{
    if(first==NULL)
    {
        cout << "\tUnderflow!!! List is currently empty.\n";
        return -1;
    }

    if(index<1 || index>length)
    {
        cout << "\tInvalid Index!!! Index must be between [1, " << length << "]\n";
        return -1;
    }

    Node *current_node = new Node;
    int deletedValue;

    if(index==1)
    {
        current_node = first;
        first = first->next;
        if(first)
            first->previous = NULL;
        cout << "\t" << current_node->data << " is deleted\n";
        deletedValue = current_node->data;
        delete current_node;
    }
    else if(index==length)
    {
        current_node = last;
        last = last->previous;
        last->next = NULL;
        cout << "\t" << current_node->data << " is deleted\n";
        deletedValue = current_node->data;
        delete current_node;
    }
    else
    {
        current_node = first;
        for(int i=0; i<index-1; i++)
            current_node = current_node->next;
        current_node->previous->next = current_node->next;
        current_node->next->previous = current_node->previous;
        cout << "\t" << current_node->data << " is deleted\n";
        deletedValue = current_node->data;
        delete current_node;
    }
    --length;
    return deletedValue;
}

void DoublyLinkedList :: reverseList()
{
    if(first==NULL)
        cout << "\tEmpty list can't be reversed\n";
    else if(first==last)
        cout << "\tSingle Element list. Reverse is same\n";
    else
    {
        Node *current_node;
        last = first;
        while(first)
        {
            current_node = first;
            first = first->next;
            current_node->next = current_node->previous;
            current_node->previous = first;
        }
        first = current_node;
        cout << "\tReversed first is : " << first->data << endl;
        cout << "\tReversed last is : " << last->data << endl;
    }
}

bool DoublyLinkedList :: isSorted()
{
    Node *current_node = first;
    int value = first->data;
    while(current_node)
    {
        if(value > current_node->data)
        {
            cout << "\tList is not sorted\n";
            return false;
        }
        value = current_node->data;
        current_node = current_node->next;
    }
    cout << "\tList is sorted\n";
    return true;
}

bool DoublyLinkedList :: hasLoop()
{
    Node *singleStep = first, *doubleStep = first;
    if(first==NULL)
    {
        cout << "\tEmpty List! No Loop possible\n";
        return false;
    }
    do
    {
        singleStep = singleStep->next;
        doubleStep = doubleStep->next;
        doubleStep = doubleStep ? doubleStep->next : doubleStep;
    } while(singleStep && doubleStep && singleStep!=doubleStep);

    if(singleStep==doubleStep)
    {
        cout << "\tList has a loop\n";
        return true;
    }
    else
    {
        cout << "\tList is linear\n";
        return false;
    }
}

int main()
{
    cout << "\t***** An Example of Doubly Linked List in C++ *****\n\n";

    int fixed_array[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    DoublyLinkedList ll(fixed_array, 7);
    ll.displayList();
    ll.hasLoop();
    return 0;
}
