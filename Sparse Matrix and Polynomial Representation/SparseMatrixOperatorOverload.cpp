#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  24-02-2022
    Language: C++
    Content:  Sparse Matrix (Operator Overload)
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
    SparseMatrix(int row, int column, int number)
    {
        this->row = row;
        this->column = column;
        this->number = number;
        this->element = new Element[number];
    }

    ~SparseMatrix()
    {
        delete [] element;
    }

    friend istream & operator >> (istream & input, SparseMatrix s);
    friend ostream & operator << (ostream & output, SparseMatrix s);
};

istream & operator >> (istream & input, SparseMatrix s)
{
    cout << "\tEnter non-zero elements (row, column, value)\n";
    for(int i=0; i<s.number; i++)
    {
        cout << "\t\tElement #" << i+1 << ": ";
        cin >> s.element[i].r >> s.element[i].c >> s.element[i].v;
    }
    return input;
}

ostream & operator << (ostream & output, SparseMatrix s)
{
    cout << "Printing (" << s.row << " * " << s.column << ") Sparse Matrix.\n";

    int k = 0;
    for(int i=0; i<s.row; i++)
    {
        cout << "\t";
        for(int j=0; j<s.column; j++)
        {
            if(s.element[k].r==i && s.element[k].c==j)
                cout << s.element[k++].v << "\t";
            else
                cout << 0 << "\t";
        }
        cout << endl;
    }
    cout << endl;

    return output;
}


int main()
{
    cout << "\t***** An Example of Sparse Matrix Using Operator Overload in C++ *****\n\n";

    SparseMatrix s1(5, 5, 5), s2(3, 6, 3);

    cout << "Enter First Matrix" << endl;
    cin >> s1;

    cout << "\nEnter Second Matrix" << endl;
    cin >> s2;

    cout << "\n\nDisplaying First Matrix" << endl;
    cout << s1;

    cout << "Displaying Second Matrix" << endl;
    cout << s2;

    return 0;
}
