#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  29-03-2022
    Language: C
    Content:  Circular Doubly Linked List
*/

struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
}*head=NULL;


void createLinkedList(int arr[], int len)
{
    struct Node *last, *current_node;
    head = (struct Node*) malloc(sizeof(struct Node));
    head->data = arr[0];
    head->previous = head;
    head->next = head;
    last = head;
    for(int i=1; i<len; i++)
    {
        current_node = (struct Node *) malloc(sizeof(struct Node));
        current_node->data = arr[i];
        last->next = current_node;
        current_node->previous = last;
        last = current_node;
        last->next = head;
    }
}

int countNodes(struct Node *h)
{
    int counter = 0;
    if(h==NULL)
        return counter;
    do
    {
        ++counter;
        h = h->next;
    } while(h!=head);
    return counter;
}

void displayList(struct Node *h)
{
    if(h==NULL)
    {
        printf("Empty List\n");
        return;
    }
    printf("Printing %d nodes circular linked list\n", countNodes(h));
    do
    {
        printf("\t%d", h->data);
        h = h->next;
    } while(h!=head);
    printf("\n");
}

int main()
{
    printf("\t***** An Example of Circular Doubly Linked List in C *****\n\n");

    int fixed_array[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    struct Node *temp = NULL;
    createLinkedList(fixed_array, 6);
    displayList(head);
    return 0;
}
