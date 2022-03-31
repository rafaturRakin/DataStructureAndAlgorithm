#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  31-03-2022
    Language: C++
    Content: Circular Doubly Linked List
*/


class Node
{
public:
    Node *previous;
    Node *next;
    int data;
};

class CircularDoublyLinkedList
{
private:
    Node *head;
    int length;

public:
    CircularDoublyLinkedList();
    CircularDoublyLinkedList(int len);
    CircularDoublyLinkedList(int arr[], int len);

    ~CircularDoublyLinkedList();

    void displayList();
    int sum();
    double average();
    int maximum();
    int minimum();
    bool searchNode(int key);
    void insertNode(int index, int value);
    int removeNode(int index);
    bool isSorted();
};


CircularDoublyLinkedList :: CircularDoublyLinkedList()
{
    head = NULL;
    length = 0;
    cout << "Default Constructor Called. " << length << " length linked list created\n\n";
}


CircularDoublyLinkedList :: CircularDoublyLinkedList(int len)
{
    if(len > 0)
    {
        int value;
        Node * current_node, *last;
        cout << "\tEnter value of #1 node : ";
        cin >> value;

        length = len;
        head = new Node;
        head->data = value;
        head->previous = head;
        head->next = head;
        last = head;

        for(int i=1; i<length; i++)
        {
            cout << "\tEnter value of #" << i+1 << " node : ";
            cin >> value;
            current_node = new Node;
            current_node->data = value;
            current_node->previous = last;
            current_node->next = head;
            last->next = current_node;
            last = current_node;
            head->previous = current_node;
        }

        cout << "Constructor with length value called. " << length << " length linked list created\n" << endl;
    }
    else
    {
        cout << "Invalid Length!!! 0 length list created...\n\n";
        head = NULL;
        length = 0;
    }
}


CircularDoublyLinkedList :: CircularDoublyLinkedList(int arr[], int len)
{
    if(len > 0)
    {
        Node * current_node, *last;

        head = new Node;
        head->data = arr[0];
        head->previous = head;
        head->next = head;
        last = head;

        for(int i=1; i<len; i++)
        {
            current_node = new Node;
            current_node->data = arr[i];
            current_node->next = head;
            current_node->previous = last;
            last->next = current_node;
            head->previous = current_node;
            last = current_node;
        }

        length = len;
        cout << "Constructor with array called. " << length << " length linked list created\n\n";
    }
    else
    {
        cout << "Invalid Length value!!! 0 length linked list created\n\n";
        head = NULL;
        length = 0;
    }
}


CircularDoublyLinkedList :: ~CircularDoublyLinkedList()
{
    Node *currentNode = head;
    do
    {
        if(!currentNode)
            break;

        if(head==head->next)
        {
            delete currentNode;
            currentNode = NULL;
        }
        else
        {
            head = head->next;
            head->previous = currentNode->previous;
            currentNode->previous->next = head;
            delete currentNode;
            currentNode = head;
        }
    }while(currentNode!=NULL);
}


void CircularDoublyLinkedList :: displayList()
{
    Node *current_node = head;

    cout << "Displaying " << length << " node circular doubly linked list\n";
    do
    {
        cout << "\t" << current_node->data;
        current_node = current_node->next;
    }while(current_node!=head);
    cout << endl;
}

int CircularDoublyLinkedList :: sum()
{
    Node *current_node = head;
    int total = 0;
    do
    {
        total += current_node->data;
        current_node = current_node->next;
    }while(current_node!=head);
    cout << "\tTotal = " << total << endl;
    return total;
}


double CircularDoublyLinkedList :: average()
{
    int total = sum();
    double avg = double(total) / double(length);
    cout << "\tAverage = " << avg << endl;
    return avg;
}


int CircularDoublyLinkedList :: maximum()
{
    Node * current_node = head;
    int maxValue = head->data;
    do
    {
        if(current_node->data > maxValue)
            maxValue = current_node->data;
        current_node = current_node->next;
    }while(current_node!=head);
    cout << "\tMaximum = " << maxValue << endl;
    return maxValue;
}


int CircularDoublyLinkedList :: minimum()
{
    Node *current_node = head;
    int minValue = head->data;
    do
    {
        if(current_node->data < minValue)
            minValue = current_node->data;
        current_node = current_node->next;
    }while(current_node!=head);
    cout << "\tMinimum = " << minValue << endl;
    return minValue;
}

bool CircularDoublyLinkedList :: searchNode(int key)
{
    Node *current_node = head;
    int counter = 1;
    do
    {
        if(current_node->data == key)
        {
            cout << "\tFound at node #" << counter << endl;
            return true;
        }
        current_node = current_node->next;
        ++counter;
    }while(current_node!=head);
    cout << "\t" << key << " is not a node in the list" << endl;
    return false;
}


void CircularDoublyLinkedList :: insertNode(int index, int value)
{
    if(index<0 || index>length)
    {
        cout << "\tInvalid Index!!! Index must be between [0, " << length << "]\n";
        return;
    }

    Node * current_node = new Node;
    if(head==NULL)
    {
        head = new Node;
        head->data = value;
        head->previous = head;
        head->next = head;
        cout << "\t" << value << " inserted as head node. List is not empty now\n";
    }
    else if(index==0)
    {
        current_node->data = value;
        current_node->previous = head->previous;
        current_node->next = head;
        head->previous->next = current_node;
        head->previous = current_node;
        head = current_node;
        cout << "\t" << value << " inserted as head node\n";
    }
    else
    {
        Node *temp_node = head;
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

int CircularDoublyLinkedList :: removeNode(int index)
{
    if(head==NULL)
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
        current_node = head;
        if(head==head->next)
            head=NULL;
        else
        {
            head = head->next;
            head->previous = current_node->previous;
            current_node->previous->next = head;
        }
        cout << "\t" << current_node->data << " is deleted\n";
        deletedValue = current_node->data;
        delete current_node;
    }
    else
    {
        current_node = head;
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


bool CircularDoublyLinkedList :: isSorted()
{
    Node *current_node = head;
    int value = head->data;
    do
    {
        if(value > current_node->data)
        {
            cout << "\tList is not sorted\n";
            return false;
        }
        value = current_node->data;
        current_node = current_node->next;
    }while(current_node!=head);
    cout << "\tList is sorted\n";
    return true;
}


int main()
{
    cout << "\t***** An Example of Circular Doubly Linked List in C++ *****\n\n";

    int fixed_array[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    CircularDoublyLinkedList l1(fixed_array, 5);
    l1.displayList();
    return 0;
}
