#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  23-03-2022
    Language: C
    Content:  Doubly Linked List
*/

struct Node
{
    int data;
    struct Node* previous;
    struct Node* next;
} *first = NULL;


void create_linkedList(int arr[], int len)
{
    struct Node *current_node, *last_node;
    int value;

    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = arr[0];
    first->previous = first->next = NULL;
    last_node = first;

    for(int i=1; i<len; i++)
    {
        current_node = (struct Node *) malloc(sizeof(struct Node));
        current_node->data = arr[i];
        current_node->next = last_node->next;
        current_node->previous = last_node;
        last_node->next = current_node;
        last_node = current_node;
    }
}


int countNodes(struct Node * p)
{
    int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }

    return count;
}


void display_linkedList(struct Node *p)
{
    printf("Displaying the linked list with %d nodes : \n", countNodes(p));
    while(p != NULL)
    {
        printf("\t%d", p->data);
        p = p->next;
    }
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Doubly Linked List in C *****\n\n");

    int arr[7] = {1, 2, 4, 8, 16, 32, 64};

    printf("Creating Linked List...\n");
    create_linkedList(arr, 7);

    display_linkedList(first);

    return 0;
}

