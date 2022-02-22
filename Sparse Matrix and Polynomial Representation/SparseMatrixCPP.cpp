#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  22-02-2022
    Language: C++
    Content:  Sparse Matrix (C++)
*/

class Element
{
public:
    int r;
    int c;
    int v;
};

class SparseMatrix
{
private:
    int row;
    int column;
    int number;
    Element *element;

public:
    SparseMatrix();
    ~SparseMatrix()
    {
        delete [] element;
    }

    void display_matrix();
};

SparseMatrix :: SparseMatrix()
{
    int i;

    cout << "Enter dimension (row, column) : ";
    cin >> row >> column;

    cout << "Enter number of non-zero elements : ";
    cin >> number;

    element = new Element[number];

    cout << "Enter non-zero elements (row, column, value)\n";
    for(int i=0; i<number; i++)
    {
        cout << "\tElement#" << i+1 << ": ";
        cin >> element[i].r >> element[i].c >> element[i].v;
    }
}

void SparseMatrix :: display_matrix()
{
    int i, j, k=0;
    cout << "\nPrinting (" << row << " * " << column << ")sparse matrix : \n";
    for(i=0; i<row; i++)
    {
        cout << "\t";
        for(j=0; j<column; j++)
        {
            if(i==element[k].r && j==element[k].c)
                printf("%5d ", element[k++].v);
            else
                printf("%5d ", 0);
        }
        cout << "\n";
    }
    cout << endl;
}


int main()
{
    cout << "\t***** An Example of Sparse Matrix in C++ *****\n\n";

    SparseMatrix s1;
    cout << "\n";
    SparseMatrix s2;

    cout << "\nMatrix: #01";
    s1.display_matrix();

    cout << "Matrix: #02";
    s2.display_matrix();

    return 0;
}

