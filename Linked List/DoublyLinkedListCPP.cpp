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

int main()
{
    cout << "\t***** An Example of Doubly Linked List in C++ *****\n\n";

    int fixed_array[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    DoublyLinkedList ll(fixed_array, 12);
    ll.displayList();

    return 0;
}
