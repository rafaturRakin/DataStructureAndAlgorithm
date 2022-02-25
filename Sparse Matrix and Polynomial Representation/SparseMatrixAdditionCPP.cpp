#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  25-02-2022
    Language: C++
    Content:  Sparse Matrix Addition in C++
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

    SparseMatrix operator + (SparseMatrix &s);
    friend istream & operator >> (istream &input, SparseMatrix &s);
    friend ostream & operator << (ostream &output, SparseMatrix &s);
};

SparseMatrix SparseMatrix :: operator + (SparseMatrix &s)
{
    int i, j, k;
    i = j = k = 0;

    SparseMatrix *sum = new SparseMatrix(row, column, number+s.number);

    if(row!=s.row && column!=s.column)
        return SparseMatrix(0, 0, 0);

    while(i<number && j<s.number)
    {
        if(element[i].r<s.element[j].r)
            sum->element[k++] = element[i++];
        else if(element[i].r > s.element[j].r)
            sum->element[k++] = s.element[j++];
        else
        {
            if(element[i].c<s.element[j].c)
                sum->element[k++] = element[i++];
            else if(element[i].c>s.element[j].c)
                sum->element[k++] = s.element[j++];
            else
            {
                sum->element[k] = element[i];
                sum->element[k++].v = element[i++].v + s.element[j++].v;
            }
        }
    }

    while(i<number)
        sum->element[k++] = element[i++];
    while(j<s.number)
        sum->element[k++] = s.element[j++];

    return *sum;
}

istream & operator >> (istream &input, SparseMatrix &s)
{
    cout << "\tEnter non-zero elements (row, column, value)\n";
    for(int i=0; i<s.number; i++)
    {
        cout << "\t\tElement #" << i+1 << ": ";
        cin >> s.element[i].r >> s.element[i].c >> s.element[i].v;
    }
    return input;
}

ostream & operator << (ostream &output, SparseMatrix &s)
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
    cout << "\t***** An Example of Sparse Matrix Addition in C++ *****\n\n";

    SparseMatrix s1(5, 5, 5), s2(5, 5, 3);

    cout << "Enter First Matrix" << endl;
    cin >> s1;

    cout << "\nEnter Second Matrix" << endl;
    cin >> s2;

    SparseMatrix sum = s1 + s2;

    cout << "\n\nDisplaying First Matrix" << endl;
    cout << s1;

    cout << "Displaying Second Matrix" << endl;
    cout << s2;

    cout << "Displaying Sum" << endl;
    cout << sum;

    return 0;
}
