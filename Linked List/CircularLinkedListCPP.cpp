#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  22-03-2022
    Language: C++
    Content:  Circular Linked List
*/

class Node
{
public:
    int data;
    Node* next;
};

class CircularLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    CircularLinkedList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    CircularLinkedList(int arr[], int len);
    ~CircularLinkedList()
    {
        delete head;
    }

    void insert_node(int, int);
    void delete_node(int);
    void display_linkedList();
    int list_length();
};


CircularLinkedList :: CircularLinkedList(int arr[], int len)
{
    Node *current_node;
    int value;

    head = new Node;
    head->data = arr[0];
    head->next = head;
    tail= head;
    ++length;
    for(int i=1; i<len; i++)
    {
        current_node = new Node;

        current_node->data = arr[i];
        current_node->next = tail->next;
        tail->next = current_node;
        tail = current_node;
        ++length;
    }
}

// displaying linked list
void CircularLinkedList :: display_linkedList()
{
    Node *current_node = head;
    cout << "Displaying the (" << length << " node) circular linked list \n\t";
    do
    {
        cout << current_node->data << "\t";
        current_node = current_node->next;
    } while(current_node!=head);
    cout << "\n";
}

void CircularLinkedList :: insert_node(int index, int value)
{
    Node *current_node = head, *temp_node;
    if(index<0 || index>length)
    {
        cout << "\tInvalid Index!!! " << value <<" is not inserted...\n";
        return;
    }
    if(index==0)
    {
        temp_node = new Node;
        temp_node->data = value;
        if(head==NULL)
        {
            cout << "\t" << value << " is now head and 1st node in the list.\n";
            head = temp_node;
            head->next = head;
            ++length;
        }
        else
        {
            while(current_node->next != head)
                current_node = current_node->next;
            current_node->next = temp_node;
            temp_node->next = head;
            head = temp_node;
            cout << "\tNew head is " << head->data << endl;
            ++length;
        }
    }
    else
    {
        for(int i=0; i<index-1; i++)
            current_node = current_node->next;
        temp_node = new Node;
        temp_node->data = value;
        temp_node->next = current_node->next;
        current_node->next = temp_node;
        cout << "\t" << value << " is inserted at # " << index << " index\n";
        ++length;
    }
}

// deleting
void CircularLinkedList :: delete_node(int index)
{
    Node *current_node = head, *temp_node;
    if(index<1 || index>length)
    {
        cout << "\t" << index << " is Invalid Index!!!\n";
        return;
    }

    if(index==1)
    {
        while(current_node->next != head)
            current_node = current_node->next;
        if(current_node==head)
        {
            cout << "\t" << current_node->data << " from " << index << " index is deleted. List is empty now\n";
            delete head;
            head = NULL;
            --length;
        }
        else
        {
            cout << "\t" << head->data << " is deleted from head, current head is " << head->next->data << "\n";
            current_node->next = head->next;
            delete head;
            head = current_node->next;
            --length;
        }
    }
    else
    {
        for(int i=0; i<index-2; i++)
            current_node = current_node->next;
        temp_node = current_node->next;
        current_node->next = temp_node->next;
        cout << "\t" << current_node->data << " from " << index << " index is deleted\n";
        delete temp_node;
        --length;
    }
}

int main()
{
    cout << "\t***** An Example of Circular Linked List in C++ *****\n\n";

    int arr[7] = {1, 2, 4, 8, 16, 32, 64};
    CircularLinkedList cl(arr, 7);

    cout << "Displaying list...\n";
    cl.display_linkedList();

    cout << "\n";
    cl.delete_node(0);
    cl.delete_node(1);
    cl.delete_node(3);
    cl.delete_node(5);

    cout << "\n";
    cl.display_linkedList();

    cout << "\n";
    cl.insert_node(-1, 12);
    cl.insert_node(0, 12);

    cout << "\n";
    cl.display_linkedList();
    return 0;
}
