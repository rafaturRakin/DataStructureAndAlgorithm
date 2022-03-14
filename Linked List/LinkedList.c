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
} *globalNode;

int iterative_countNodes(struct Node *);


// creating linked list     (04.03.22)
struct Node * create_linkedList()
{
    struct Node *first, *current_node, *last_node;
    int value;

    first = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter the value (-1 to stop) : ");
    scanf("%d", &value);
    if(value==-1)
        return NULL;

    first->data = value;
    first->next = NULL;
    last_node = first;

    while(1)
    {
        printf("Enter the value (-1 to stop) : ");
        scanf("%d", &value);

        if(value==-1)
            break;

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
    printf("Displaying the linked list with %d nodes : \n", iterative_countNodes(p));
    while(p != NULL)
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
    if(p==NULL)
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
        if(p->data < minimum)
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


// Inserting in Linked List         (09.03.2022)
struct Node * insert_linkedList(struct Node *first_node, int index, int value)
{
    struct Node *new_node, *current_node;
    current_node = first_node;
    new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = value;

    if(index<0 || index>iterative_countNodes(first_node))
        printf("\tInvalid Index!!!%d is not inserted at index #%d\n", value, index);
    else if(index==0)
    {
        new_node->next = first_node;
        first_node = new_node;
    }
    else
    {
        for(int i=0; i<index-1; i++)
            current_node = current_node->next;
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
    return first_node;
}


// Insert in a Sorted Linked List       (10.03.2022)
struct Node * insert_sorted(struct Node * first_node, int value)
{
    struct Node *current_node, *new_node, *previous_node=NULL;

    new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    current_node = first_node;

    if(first_node == NULL)
        first_node = new_node;
    else if(value <= first_node->data)
    {
        new_node->next = first_node;
        first_node = new_node;
    }
    else
    {
        while(current_node && current_node->data<value)
        {
            previous_node = current_node;
            current_node = current_node->next;
        }

        new_node->next = previous_node->next;
        previous_node->next = new_node;
    }

    return first_node;
}


// Delete from linked list
struct Node * delete_node(struct Node * first_node, int index)
{
    struct Node *current_node = first_node, *previous_node=NULL;

    if(index<1 || index>iterative_countNodes(first_node))
        printf("\tInvalid Index (%d)!!!\n", index);
    else if(index == 1)
    {
        printf("\tDeleted element is %d\n", current_node->data);
        first_node = first_node->next;
        free(current_node);
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            previous_node = current_node;
            current_node = current_node->next;
        }
        previous_node->next = current_node->next;
        printf("\tDeleted element is %d\n", current_node->data);
        free(current_node);
    }

    return first_node;
}


// Checking sorted or not       (12.03.2022)
void isSorted(struct Node * current_node)
{
    int previous_value = INT_MIN;
    if(current_node==NULL)
    {
        printf("\tList is empty!!!\n");
        return;
    }

    while(current_node != NULL)
    {
        if(current_node->data < previous_value)
        {
            printf("\tList is not sorted\n");
            return;
        }
        previous_value = current_node->data;
        current_node = current_node->next;
    }
    printf("\tList is sorted\n");
}


// Remove duplicate nodes       (13.03.2022)
struct Node * remove_duplicate(struct Node * first_node)
{
    struct Node *current_node, *next_node;

    if(first_node==NULL)
        return NULL;

    current_node = first_node;
    next_node = first_node->next;

    while(next_node != NULL)
    {
        if(current_node->data != next_node->data)
        {
            current_node = next_node;
            next_node = next_node->next;
        }
        else
        {
            current_node->next = next_node->next;
            printf("\tDeleted Element : %d\n", next_node->data);
            free(next_node);
            next_node = current_node->next;
        }
    }
    return first_node;
}


// reverse linked list (data)       (14.03.2022)
void reverse_data(struct Node *first_node)
{
    int i=0, *arr;
    struct Node *current_node = first_node;

    arr = (int *) malloc(sizeof(int) * iterative_countNodes(first_node));

    while(current_node)
    {
        arr[i++] = current_node->data;
        current_node = current_node->next;
    }

    current_node = first_node;
    i--;

    while(current_node)
    {
        current_node->data = arr[i--];
        current_node = current_node->next;
    }
    free(arr);
}


// reverse linked list (links)      (14.03.2022)
struct Node * reverse_slidingPointer(struct Node * first_node)
{
    struct Node *p, *q, *r;
    p = first_node;
    q = r = NULL;

    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first_node = q;
    return first_node;
}


// reverse linked list (recursive)      (14.03.2022)
void reverse_recursive(struct Node *previous, struct Node *current)
{
    if(current)
    {
        reverse_recursive(current, current->next);
        current->next = previous;
    }
    else
        globalNode = previous;
}

int main()
{
    printf("\t***** An Example of Linked List in C *****\n\n");

    struct Node *first, *second;

    printf("Creating Linked List.....\n");
    first = create_linkedList();

    printf("\n");
    display_linkedList(first);

    printf("\nAfter Reversing data...\n");
    reverse_data(first);
    display_linkedList(first);

    printf("\nAfter Reversing links...\n");
    first = reverse_slidingPointer(first);
    display_linkedList(first);

    globalNode = first;
    printf("\nAfter Reversing recursively...\n");
    reverse_recursive(NULL, globalNode);
    display_linkedList(globalNode);

    return 0;
}
