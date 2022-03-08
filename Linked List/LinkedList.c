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



// Iterative counting nodes     (06.03.2022)
int iterative_countNodes(struct Node * p)
{
    int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }

    return count;
}

// Recursive Counting nodes     (06.03.2022)
int recursive_countNodes(struct Node* p)
{
    if(p==NULL)
        return 0;
    return recursive_countNodes(p->next) + 1;
}

// Iterative sum of nodes       (06.03.2022)
int iterative_sum(struct Node* p)
{
    int sum = 0;
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;   // -1 for last node.
}

// recursive sum of nodes       (06.03.2022)
int recursive_sum(struct Node* p)
{
    if(p==NULL)
        return 0;
    return recursive_sum(p->next) + p->data;
}


// Maximum element      (07.03.2022)
int recursive_maxElement(struct Node *p)
{
    int maximum = INT_MIN;

    if(p == NULL)
        return INT_MIN;
    maximum = recursive_maxElement(p->next);
    if(maximum > p->data)
        return maximum;
    else
        return p->data;

}

// Minimum Element      (07.03.2022)
int iterative_minElement(struct Node *p)
{
    int minimum = INT_MAX;

    while(p)
    {
        if(p->data < minimum && p->data!=-1)
            minimum = p->data;
        p = p->next;
    }
    return minimum;
}


// Linear Search        (08.03.2022)
void linear_search(struct Node *p, int key)
{
    int count = 0;
    while(p)
    {
        ++count;
        if(p->data == key)
        {
            printf("\t%d is found at node #%d\n", p->data, count);
            return;
        }
        p = p->next;
    }

    printf("\t%d is not found in the list\n", key);
}


// Improved Linear Search       (08.03.2022)
struct Node * improved_linear_search(struct Node *first_node, int key)
{
    int count = 0;
    struct Node *current_node = first_node, *previous_node=NULL;

    while(current_node)
    {
        ++count;
        if(current_node->data == key)
        {
            printf("\t%d is found at node #%d\n", current_node->data, count);
            previous_node->next = current_node->next;
            current_node->next = first_node;
            first_node = current_node;
            printf("\tfirst node is now = %d\n\n", first_node->data);
            return first_node;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    printf("\t%d is not found in the list\n", key);
    return first_node;
}

int main()
{
    printf("\t***** An Example of Linked List in C *****\n\n");

    struct Node * first;

    printf("Creating Linked List.....\n");
    first = create_linkedList();

    printf("\nDisplaying Linked List : \n");
    display_linkedList(first);

    printf("\nSearching in linked list\n");
    linear_search(first, 12);
    linear_search(first, 57);

    printf("\nImproved Searching in linked list\n");
    first = improved_linear_search(first, 12);
    first = improved_linear_search(first, 57);

    printf("\nAfter Improvement...\n");
    display_linkedList(first);

    return 0;
}
