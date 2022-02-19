#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  19-02-2022
    Language: C++
    Content:  Tridiagonal Matrix in C++
*/

class TridiagonalMatrix
{
private:
    int *A;
    int dimension;

public:
    TridiagonalMatrix()
    {
        dimension = 2;
        A = new int[3*dimension - 2];
    }

    TridiagonalMatrix(int d)
    {
        dimension = d;
        A = new int[3*dimension - 2];
    }

    ~TridiagonalMatrix()
    {
        delete [] A;
    }

    int get_dimension();
    void set_value(int, int, int);
    int get_value(int, int);
    void display_matrix();
};

void TridiagonalMatrix :: set_value(int i, int j, int value)
{
    if(i==0 || j==0 || i>dimension || j>dimension)
        cout << "Invalid Index!!\n";
    else if(i-j==1)
        A[i-2] = value;
    else if(i-j==0)
        A[dimension-1 + i-1] = value;
    else if(i-j==-1)
        A[dimension-1 + dimension + i-1] = value;
}


int TridiagonalMatrix :: get_value(int i, int j)
{
    if(i==0 || j==0 || i>dimension || j>dimension)
    {
        cout << "Invalid Index!!\n";
        return -1;
    }
    else if(i-j==1)
        return A[i-2];
    else if(i-j==0)
        return A[dimension-1 + i-1];
    else if(i-j==-1)
        return A[dimension-1 + dimension + i-1];
    else
        return 0;
}


void TridiagonalMatrix :: display_matrix()
{
    cout << "\nPrinting (" << dimension << " * " << dimension << ") Tridiagonal matrix : \n";
    cout << "Total maximum non-zero elements : " << 3*dimension-2 << "\n\n";
    for(int i=1; i<=dimension; i++)
    {
        cout << "\t";
        for(int j=1; j<=dimension; j++)
            cout <<  get_value(i, j) << "  ";
        cout << "\n";
    }
    cout << "\n";
}


int main()
{
    cout << "\t***** An Example of Tridiagonal Matrix in C++ *****\n\n";

    int value, dimension;

    cout << "Enter matrix dimension : ";
    cin >> dimension;

    TridiagonalMatrix m(dimension);

    cout << "Enter all values : \n";
    for(int i=1; i<=dimension; i++)
    {
        cout << "\t";
        for(int j=1; j<=dimension; j++)
        {
            cin >> value;
            m.set_value(i, j, value);
        }
    }

    m.display_matrix();
    return 0;
}

