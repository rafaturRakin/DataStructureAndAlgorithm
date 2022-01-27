#include<iostream>

/*
    Author: Rakin
    Date:  27-01-2022
    Language: C++
    Content: Menu Driven Program (C++)
*/

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete []A;
    }

    int getLength()
    {
        return length;
    }

    void insert_array(int, int);
    int delete_array(int);
    int linear_search(int);
    int sum_elements();
    void display_array();

};


void Array::insert_array(int index, int element)
{
    if(length<size && index>=0 && index<=length)
    {
        for(int i=length; i>index; i--)
            A[i] = A[i-1];
        A[index] = element;
        length++;
    }
    else
        printf("Invalid Index!!! Array length is %d...%d is not inserted\n", length, element);
}


int Array::delete_array(int index)
{
    int item = INT_MIN;
    if(length > 0 && index>=0 && index<=length-1)
    {
        item = A[index];
        for(int i=index; i<length-1; i++)
            A[i] = A[i+1];
        length--;
    }
    return item;
}


int Array::linear_search(int key)
{
    int index = -1;
    for(int i=0; i<length; i++)
    {
        if(A[i] == key)
            return index = i;
    }
    return index;
}


int Array::sum_elements()
{
    int total = 0;
    for(int i=0; i<length; i++)
        total += A[i];
    return total;
}


void Array::display_array()
{
    printf("Printing all array elements(%d) : \n", length);
    for(int i=0; i<length; i++)
        printf("\t%d", A[i]);
    printf("\n\n");
}


int main()
{
    printf("\t***** An Example of Menu Driven Program (C++) *****\n\n");

    int index, element, choice, size;
    class Array *arr;

    printf("Enter the array size : ");
    scanf("%d", &size);
    arr = new Array(size);

    do
    {
        printf("\n***** Menu *****\n");
        printf("\t 1. Insert element\n");
        printf("\t 2. Delete element\n");
        printf("\t 3. Search element\n");
        printf("\t 4. Sum elements\n");
        printf("\t 5. Display elements\n");
        printf("\t 6. Exit\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter the index and element : ");
            scanf("%d %d", &index, &element);
            arr->insert_array(index, element);
            break;

        case 2:
            printf("Enter the index : ");
            scanf("%d", &index);
            element = arr->delete_array(index);
            printf("Deleted element from %d index is %d\n", index, element);
            break;

        case 3:
            printf("Enter the element : ");
            scanf("%d", &element);
            index = arr->linear_search(element);
            printf("%d is at location %d\n", element, index);
            break;

        case 4:
            printf("Sum of %d elements in array is %d\n", arr->getLength(), arr->sum_elements());
            break;

        case 5:
            arr->display_array();
            break;

        default:
            printf("Exiting program...\n\n");
            break;
        }
    } while(choice>0 && choice<6);

    return 0;
}

