#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  20-02-2022
    Language: C++
    Content:  Toeplitz Matrix in C++
*/

class ToeplitzMatrix
{
private:
    int *A;
    int dimension;

public:
    ToeplitzMatrix()
    {
        dimension = 2;
        A = new int[2*dimension - 1];
    }

    ToeplitzMatrix(int d)
    {
        dimension = d;
        A = new int[2*dimension - 1];
    }

    ~ToeplitzMatrix()
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

void ToeplitzMatrix :: set_value(int i, int j, int value)
{
    if(i==0 || j==0 || i>dimension || j>dimension)
        cout << "Invalid Index!!\n";
    else if(i<=j)
        A[j-i] = value;
    else if(i>j)
        A[dimension + i-j-1] = value;
}


int ToeplitzMatrix :: get_value(int i, int j)
{
    if(i==0 || j==0 || i>dimension || j>dimension)
    {
        cout << "Invalid Index!!\n";
        return -1;
    }
    else if(i<=j)
        return A[j-i];
    else if(i>j)
        return A[dimension + i-j-1];
    else
        return 0;
}


void ToeplitzMatrix :: display_matrix()
{
    cout << "\nPrinting (" << dimension << " * " << get_dimension() << ") Toeplitz matrix : \n";
    for(int i=1; i<=dimension; i++)
    {
        cout << "\t";
        for(int j=1; j<=dimension; j++)
            cout << get_value(i, j) << "  ";
        cout << "\n";
    }
    cout << "\n";
}


int main()
{
    cout << "\t***** An Example of Toeplitz Matrix in C++ *****\n\n";

    int value, dimension;

    cout << "Enter matrix dimension : ";
    cin >> dimension;

    ToeplitzMatrix m(dimension);

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


