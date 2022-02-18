#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  18-02-2022
    Language: C++
    Content:  Symmetric Matrix (Upper Triangular)
*/

class SymmetricMatrix
{
private:
    int *A;
    int dimension;

public:
    SymmetricMatrix()
    {
        dimension = 2;
        A = new int[dimension*(dimension+1)/2];
    }

    SymmetricMatrix(int d)
    {
        dimension = d;
        A = new int[dimension*(dimension+1)/2];
    }

    ~SymmetricMatrix()
    {
        delete [] A;
    }

    void set_value(int, int, int);
    int get_value(int, int);
    void display_matrix();
    int get_dimension()
    {
        return dimension;
    }
};

void SymmetricMatrix :: set_value(int i, int j, int value)
{
    int index;
    if(i==0 || j==0 || i>dimension || j>dimension)
        cout << "Value not set!! Invalid Index (" << i << " , " << j << ")!!" << endl;
    else if(i<=j)
    {
        index = dimension*(i-1) - (i-2)*(i-1)/2 + j-i;
        A[index] = value;
    }
}


int SymmetricMatrix :: get_value(int i, int j)
{
    int index;
    if(i==0 || j==0 || i>dimension || j>dimension)
    {
        cout << "No value in this Invalid Index ( " << i << " , " << j << ")!!" << endl;
        return -1;
    }
    else if(i<=j)
    {
        index = dimension*(i-1) - (i-2)*(i-1)/2 + j-i;
        return A[index];
    }
    else if(i>j)
    {
        index = dimension*(j-1) - (j-2)*(j-1)/2 + i-j;
        return A[index];
    }
    else
        return 0;
}


void SymmetricMatrix :: display_matrix()
{
    cout << "\nPrinting (" << get_dimension() << " * " << get_dimension() << ")symmetric matrix using (upper triangular matrix) : \n";

    for(int i=1; i<=get_dimension(); i++)
    {
        cout << "\t";
        for(int j=1; j<=get_dimension(); j++)
            cout << get_value(i, j) << " ";
        cout << "\n";
    }
    cout << "\n";
}


int main()
{
    cout << "\t***** An Example of Symmetric Matrix (Upper Triangular) in C++ *****\n\n";

    int value, d;

    printf("Enter matrix dimension : ");
    scanf("%d", &d);

    SymmetricMatrix m(d);

    cout << "Enter values : \n";
    for(int i=1; i<=m.get_dimension(); i++)
    {
        cout << "\t";
        for(int j=1; j<=m.get_dimension(); j++)
        {
            cin >> value;
            m.set_value(i, j, value);
        }
    }

    m.display_matrix();

    return 0;
}

