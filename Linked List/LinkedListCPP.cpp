#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  17-03-2022
    Language: C++
    Content:  Linked List
*/

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node *first;
    Node *last;
    int total_nodes;

public:
    LinkedList()
    {
        first = NULL;
        last = NULL;
        total_nodes = 0;
    }
    LinkedList(int arr[], int len);
    ~LinkedList();

    void displayLinkedList();
    void insertNode(int index, int value);
    void deleteNode(int index);
    void countNode();
};


LinkedList :: LinkedList(int arr[], int len)
{
    first = last = NULL;
    total_nodes = 0;

    if(len>0)
    {
        Node *temp;
        first = new Node;
        first->data = arr[0];
        first->next = NULL;
        last = first;
        ++total_nodes;

        for(int i=1; i<len; i++)
        {
            temp = new Node;
            temp->data = arr[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
            ++total_nodes;
        }
    }
}


LinkedList :: ~LinkedList()
{
    Node *current_node = first;
    while(current_node)
    {
        first = first->next;
        delete current_node;
        current_node = first;
    }
}


void LinkedList :: displayLinkedList()
{
    cout << "Displaying (" << total_nodes << " nodes) Linked List\n";
    Node *current_node = first;
    while(current_node)
    {
        cout << "\t" << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << endl << endl;
}


void LinkedList :: insertNode(int index, int value)
{
    if(index<0 || index>total_nodes)
        cout << "\t" << value << " Not Inserted. Invalid Index!!!" << endl;
    else
    {
        Node *tempNode, *currentNode = first;
        tempNode = new Node;
        tempNode->data = value;

        cout << "\tInserting " << value << " at position [" << index << "]...\n";
        if(index == 0)
        {
            tempNode->next = first;
            first = tempNode;
        }
        else if(index == total_nodes)
        {
            tempNode->next = NULL;
            last->next = tempNode;
            last = tempNode;
        }
        else
        {
            for(int i=0; i<index-1; i++)
                currentNode = currentNode->next;
            tempNode->next = currentNode->next;
            currentNode->next= tempNode;
        }
        ++total_nodes;
    }
}


void LinkedList :: deleteNode(int index)
{
    if(index<1 || index>total_nodes)
        cout << "\tNot Deleted. Invalid Index!!!" << endl;
    else
    {
        Node *tempNode, *currentNode = first, *previousNode=NULL;
        tempNode = new Node;

        cout << "\tDeleting " << " from position [" << index << "]...\n";
        if(index == 1)
        {
            tempNode = first;
            first = first->next;
            cout << "\t\t" << tempNode->data << " deleted.\n";
            delete tempNode;
        }
        else
        {
            for(int i=0; i<index-1; i++)
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }

            previousNode->next = currentNode->next;
            tempNode = currentNode;
            if(index==total_nodes)
                last = previousNode;

            cout << "\t\t" << tempNode->data << " deleted.\n";
            delete tempNode;
        }
        --total_nodes;
    }

}


int main()
{
    printf("\t***** An Example of Linked List in C++ *****\n\n");

    int length = 7, demoArray[7] = {2, 4, 8, 16, 32, 64, 128};
    LinkedList myList(demoArray, length);

    myList.displayLinkedList();


    // inserting...
    myList.insertNode(-1, 12);
    myList.insertNode(10, 12);

    myList.insertNode(0, 1);
    myList.displayLinkedList();

    myList.insertNode(8, 256);
    myList.displayLinkedList();

    myList.insertNode(4, 12);
    myList.displayLinkedList();


    // deleting...
    myList.deleteNode(-1);
    myList.deleteNode(15);

    myList.deleteNode(1);
    myList.displayLinkedList();

    myList.deleteNode(9);
    myList.displayLinkedList();

    myList.deleteNode(4);
    myList.displayLinkedList();

    return 0;
}
