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


void insert_node(int index, int value)
{
    struct Node *current_node, *temp_node;

    if(index<0 || index>countNodes(first))
    {
        printf("\tInvalid Index!!!%d is not inserted.\n", value);
        return;
    }

    if(index==0)
    {
        temp_node = (struct Node *) malloc(sizeof(struct Node));
        temp_node->data = value;
        temp_node->previous = NULL;
        temp_node->next = first;
        first->previous = temp_node;
        first = temp_node;
        printf("\t%d is inserted before %d and it's the current first node\n", value, first->next->data);
    }
    else
    {
        current_node = first;
        for(int i=0; i<index-1; i++)
            current_node = current_node->next;
        temp_node = (struct Node *) malloc(sizeof(struct Node));
        temp_node->data = value;

        temp_node->previous = current_node;
        temp_node->next = current_node->next;
        if(current_node->next)
            current_node->next->previous = temp_node;
        current_node->next = temp_node;
        printf("\t%d is inserted after %d\n", value, current_node->data);
    }
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

    printf("\n");
    insert_node(-1, 10);
    insert_node(0, 10);
    insert_node(1, 20);
    insert_node(5, 50);
    insert_node(10, 100);

    printf("\n");
    display_linkedList(first);

    return 0;
}

