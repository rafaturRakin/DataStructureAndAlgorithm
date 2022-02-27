#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  27-02-2022
    Language: C++
    Content:  Polynomial Representation in c++
*/

class Term
{
public:
    int coefficient;
    int exponent;
};

class Polynomial
{
private:
    int total_terms;
    Term *terms;

public:
    Polynomial()
    {
        total_terms = 3;
        terms = new Term[total_terms];
    }

    Polynomial(int number)
    {
        total_terms = number;
        terms = new Term[total_terms];
    }

    ~Polynomial()
    {
        delete [] terms;
    }

    void read_values();
    void display_polynomial();
};

void Polynomial :: read_values()
{
    cout << "Enter terms (coefficient, exponent)\n";
    for(int i=0; i<total_terms; i++)
    {
        cout << "\tTerm #" << i+1 << ": ";
        cin >> terms[i].coefficient >> terms[i].exponent;
    }
}

void Polynomial :: display_polynomial()
{
    int i, j, k=0;
    cout << "\nPrinting " << total_terms << " term(s) polynomial : \n\t";
    for(i=0; i<total_terms; i++)
    {
        cout << " " << terms[i].coefficient;

        if(terms[i].exponent==1)
            cout << "x ";
        else if(terms[i].exponent==0)
            cout << " ";
        else
            cout << "x^" << terms[i].exponent << " ";

        if(i+1<total_terms && terms[i+1].coefficient>0)
            cout << "+";
    }
    cout << endl;
}


int main()
{
    cout << "\t***** An Example of Polynomial Representation in C++ *****\n\n";

    Polynomial p(4);

    p.read_values();

    cout << "\n";

    p.display_polynomial();

    return 0;
}


