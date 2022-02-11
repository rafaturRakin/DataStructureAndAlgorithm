#include<bits/stdc++.h>

/*
    Author: Rakin
    Date:  11-02-2022
    Language: C++
    Content:  Upper Triangular Matrix
*/

using namespace std;

class UpperTriangularMatrix
{
private:
    int *A;
    int dimension;

public:
    UpperTriangularMatrix()
    {
        dimension = 2;
        A = new int[(dimension*(dimension+1))/2];
    }

    UpperTriangularMatrix(int d)
    {
        dimension = d;
        A = new int[(dimension*(dimension+1))/2];
    }

    ~UpperTriangularMatrix()
    {
        delete [] A;
    }

    void display_matrix(string type);
    void set_value(int i, int j, int value, bool type);
    int get_value(int i, int j, bool type);
    int get_dimension();
};

int UpperTriangularMatrix :: get_dimension()
{
    return dimension;
}

void UpperTriangularMatrix :: set_value(int i, int j, int value, bool type)
{
    int index;
    if(type && i<=j)
    {
        index = (dimension*(i-1)) - ((i-1)*(i-2)/2) + (j-i);
        A[index] = value;
    }
    else if(i<=j)
    {
        index = j*(j-1)/2 + (i-1);
        A[index] = value;
    }
}


int UpperTriangularMatrix :: get_value(int i, int j, bool type)
{
    int index;
    if(type && i<=j)
    {
        index = (dimension*(i-1)) - ((i-1)*(i-2)/2) + (j-i);
        return A[index];
    }
    else if(i<=j)
    {
        index = j*(j-1)/2 + (i-1);
        return A[index];
    }
    else
        return 0;
}


void UpperTriangularMatrix :: display_matrix(string type)
{
    cout << "\nPrinting (" << dimension  << " * " << dimension << ") Upper triangular matrix (" << type << " major mapping) : \n";
    for(int i=1; i<=dimension; i++)
    {
        cout << "\t";
        for(int j=1; j<=dimension; j++)
        {
            if(type=="row")
                cout << get_value(i, j, true) << " ";
            else
                cout << get_value(i, j, false) << " ";
        }
        cout << endl;
    }
    cout << "\n";
}


int main()
{
    cout << "\t***** An Example of Upper Triangular Matrix in C++ *****\n\n";

    int dimension, value;
    string type;
    bool isTrue = false;

    cout << "Enter 'row' for row major mapping or 'col' for column major mapping : ";
    cin >> type;

    cout << "Enter matrix dimension : ";
    cin >> dimension;

    UpperTriangularMatrix m(dimension);

    if(type == "row")
        isTrue = true;

    cout << "Enter all values : \n";
    for(int i=1; i<=dimension; i++)
    {
        cout << "\t";
        for(int j=1; j<=dimension; j++)
        {
            cin >> value;
            m.set_value(i, j, value, isTrue);
        }
    }

    m.display_matrix(type);

    return 0;
}
