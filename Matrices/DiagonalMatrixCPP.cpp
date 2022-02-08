#include<iostream>

/*
    Author: Rakin
    Date:  08-02-2022
    Language: C++
    Content:  Diagonal Matrix
*/

using namespace std;

class DiagonalMatrix
{
private:
    int *A;
    int dimension;

public:
    DiagonalMatrix()
    {
        A = new int[2];
        dimension = 2;
    }

    DiagonalMatrix(int d)
    {
        A = new int[d];
        dimension = d;
    }

    ~DiagonalMatrix()
    {
        delete [] A;
    }

    void set_value(int i, int j, int value);
    int get_value(int i, int j);
    void display_matrix();
};


void DiagonalMatrix :: set_value(int i, int j, int value)
{
    if(i==j)
        A[i-1] = value;
}


int DiagonalMatrix :: get_value(int i, int j)
{
    if(i==j)
        return A[i-1];
    return 0;
}


void DiagonalMatrix :: display_matrix()
{
    cout << "\nPrinting (" << dimension  << " * " << dimension << ") diagonal matrix : \n";
    for(int i=0; i<dimension; i++)
    {
        cout << "\t";
        for(int j=0; j<dimension; j++)
        {
            if(i==j)
                cout << A[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    cout << "\n";
}


int main()
{
    cout << "\t***** An Example of Diagonal Matrix in C++ *****\n\n";

    int dimension, value;
    cout << "Enter matrix dimension : ";
    cin >> dimension;

    DiagonalMatrix m(dimension);

    cout << "Enter diagonal values : \n\n";
    for(int i=1; i<=dimension; i++)
    {
        cout << "\tMatrix [" << i << " , " << i << "] : ";
        cin >> value;
        m.set_value(i, i, value);
    }

    m.display_matrix();

    cout << "Use of get method\n";
    cout << "Value at [2, 2] : " << m.get_value(2, 2) << endl;
    cout << "Value at [1, 2] : " << m.get_value(1, 2) << endl;

    return 0;
}
