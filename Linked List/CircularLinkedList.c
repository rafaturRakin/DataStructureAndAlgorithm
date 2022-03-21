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

int list_length(struct Node *);
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
    printf("Displaying the (%d node) circular linked list \n\t", list_length(p));
    do
    {
        printf("%4d  ", p->data);
        p = p->next;
    } while(p!=head);
    printf("\n");
}


// recursive display
void recursive_display(struct Node *h,int flag)
{
    if(h!=head || flag==0)
    {
        flag = 1;
        printf("\t %d", h->data);
        recursive_display(h->next, flag);
    }
}

int list_length(struct Node * h)
{
    int len = 0;
    if(h==NULL)
        return len;
    do
    {
        ++len;
        h = h->next;
    }while(h!=head);
    return len;
}


void insert_node(struct Node *h, int index, int value)
{
    struct Node *current_node, *temp_node;
    if(index<0 || index>list_length(h))
    {
        printf("\tInvalid Index!!!%d is not inserted...\n", value);
        return;
    }
    if(index==0)
    {
        temp_node = (struct Node *) malloc(sizeof(struct Node));
        temp_node->data = value;
        if(head==NULL)
        {
            printf("\t%d is now head and 1st node in the list.\n", value);
            head = temp_node;
            head->next = head;
        }
        else
        {
            while(h->next != head)
                h = h->next;
            h->next = temp_node;
            temp_node->next = head;
            head = temp_node;
            printf("\tNew head is %d\n", head->data);
        }
    }
    else
    {
        for(int i=0; i<index-1; i++)
            h = h->next;
        temp_node = (struct Node *) malloc(sizeof(struct Node));
        temp_node->data = value;
        temp_node->next = h->next;
        h->next = temp_node;
        printf("\t%d is inserted at #%d index\n", value, index);
    }
}

// deleting
void delete_node(struct Node * h, int index)
{
    struct Node *current_node, *previous_node;
    if(index<1 || index>list_length(h))
    {
        printf("\t%d is Invalid Index!!!\n", index);
        return;
    }

    if(index==1)
    {
        while(h->next != head)
            h = h->next;
        if(h==head)
        {
            printf("\t%d from %d index is deleted. List is empty now\n", h->data, index);
            free(head);
            head = NULL;
        }
        else
        {
            printf("\t%d is deleted from head, current head is %d\n", head->data, head->next->data);
            h->next = head->next;
            free(head);
            head = h->next;
        }
    }
    else
    {
        for(int i=0; i<index-2; i++)
            h = h->next;
        current_node = h->next;
        h->next = current_node->next;
        printf("\t%d from %d index is deleted\n", current_node->data, index);
        free(current_node);
    }
}

int main()
{
    printf("\t***** An Example of Circular Linked List in C *****\n\n");

    int arr[7] = {1, 2, 4, 8, 16, 32, 64};
    create_linkedList(arr, 7);
    printf("Displaying list...\n");
    display_linkedList(head);

    printf("\n");
    delete_node(head, 0);
    delete_node(head, 1);
    delete_node(head, 3);
    delete_node(head, 5);

    printf("\n");
    display_linkedList(head);
    return 0;
}

