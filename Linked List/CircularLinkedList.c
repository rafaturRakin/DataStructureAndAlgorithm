#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  18-03-2022
    Language: C
    Content:  Circular Linked List
*/

struct Node
{
    int data;
    struct Node* next;
} *head;

// creating circular linked list
void create_linkedList(int arr[], int len)
{
    struct Node *current_node, *last_node;
    int value;

    head = (struct Node *) malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = head;
    last_node = head;
    for(int i=1; i<len; i++)
    {
        current_node = (struct Node *) malloc(sizeof(struct Node));

        current_node->data = arr[i];
        current_node->next = last_node->next;
        last_node->next = current_node;
        last_node = current_node;
    }
}

// displaying linked list
void display_linkedList(struct Node *p)
{
    printf("Displaying the circular linked list \n\t");
    do
    {
        printf("%4d  ", p->data);
        p = p->next;
    } while(p!=head);
    printf("\n");
}


int main()
{
    printf("\t***** An Example of Circular Linked List in C *****\n\n");

    int arr[7] = {1, 2, 4, 8, 16, 32, 64};
    create_linkedList(arr, 7);
    display_linkedList(head);
    return 0;
}

