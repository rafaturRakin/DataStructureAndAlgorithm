#include<bits/stdc++.h>

/*
    Author: Rakin
    Date:  10-02-2022
    Language: C++
    Content:  Lower Triangular Matrix
*/

using namespace std;

class LowerTriangularMatrix
{
private:
    int *A;
    int dimension;

public:
    LowerTriangularMatrix()
    {
        dimension = 2;
        A = new int[(dimension*(dimension+1))/2];
    }

    LowerTriangularMatrix(int d)
    {
        dimension = d;
        A = new int[(dimension*(dimension+1))/2];
    }

    ~LowerTriangularMatrix()
    {
        delete [] A;
    }

    void display_matrix(string type);
    void set_value(int i, int j, int value, bool type);
    int get_value(int i, int j, bool type);
    int get_dimension();
};

int LowerTriangularMatrix :: get_dimension()
{
    return dimension;
}

void LowerTriangularMatrix :: set_value(int i, int j, int value, bool type)
{
    int index;
    if(type && i>=j)
    {
        index = i*(i-1)/2 + (j-1);
        A[index] = value;
    }
    else if(i>=j)
    {
        index = (dimension*(j-1)) - ((j-1)*(j-2)/2) + (i-j);
        A[index] = value;
    }
}


int LowerTriangularMatrix :: get_value(int i, int j, bool type)
{
    int index;
    if(type && i>=j)
    {
        index = i*(i-1)/2 + (j-1);
        return A[index];
    }
    else if(i>=j)
    {
        index = (dimension*(j-1)) - ((j-1)*(j-2)/2) + (i-j);
        return A[index];
    }
    else
        return 0;
}


void LowerTriangularMatrix :: display_matrix(string type)
{
    cout << "\nPrinting (" << dimension  << " * " << dimension << ") Lower triangular matrix (" << type << " major mapping) : \n";
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
    cout << "\t***** An Example of Lower Triangular Matrix in C++ *****\n\n";

    int dimension, value;
    string type;
    bool isTrue = false;

    cout << "Enter 'row' for row major mapping or 'col' for column major mapping : ";
    cin >> type;

    cout << "Enter matrix dimension : ";
    cin >> dimension;

    LowerTriangularMatrix m(dimension);

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
