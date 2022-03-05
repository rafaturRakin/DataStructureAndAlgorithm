
#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  04-03-2022
    Language: C
    Content:  Linked List
*/

struct Node
{
    int data;
    struct Node* next;
};


// creating linked list     (04.03.22)
struct Node * create_linkedList()
{
    struct Node *first, *current_node, *last_node;
    int value;

    first = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter the value (-1 to stop) : ");
    scanf("%d", &value);
    first->data = value;
    first->next = NULL;

    last_node = first;

    while(value != -1)
    {
        printf("Enter the value (-1 to stop) : ");
        scanf("%d", &value);

        current_node = (struct Node *) malloc(sizeof(struct Node));
        current_node->data = value;
        current_node->next = NULL;
        last_node->next = current_node;
        last_node = current_node;
    }

    return first;
}

// displaying linked list       (04.03.22)
void display_linkedList(struct Node *p)
{
    printf("\nDisplaying the linked list : \n");
    while(p != NULL && p->data!=-1)
    {
        printf("\t%d", p->data);
        p = p->next;
    }
    printf("\n");
}


// Display Linked List using recursion      (05.03.2022)
void display_linkedList_recursive(struct Node *p)
{
    if(p==NULL)
    {
        printf("\n");
        return;
    }
    printf("\t%d", p->data);
    display_linkedList_recursive(p->next);
}


// Display Linked List in reverse order using recursion         (05.03.2022)
void display_linkedList_reverse_recursive(struct Node *p)
{
    if(p==NULL || p->data==-1)
        return;

    display_linkedList_reverse_recursive(p->next);
    printf("\t%d", p->data);
}


int main()
{
    printf("\t***** An Example of Linked List in C *****\n\n");

    struct Node * first;

    printf("Creating Linked List.....\n");
    first = create_linkedList();

    printf("\nDisplaying Linked List : \n");
    display_linkedList_recursive(first);

    printf("\nPrinting in reverse order :\n");
    display_linkedList_reverse_recursive(first);
    printf("\n");

    return 0;
}
