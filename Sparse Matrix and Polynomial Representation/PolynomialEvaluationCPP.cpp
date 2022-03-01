#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  01-03-2022
    Language: C++
    Content:  Polynomial Evaluation (C++)
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
    int power(int, int);

public:
    Polynomial();

    Polynomial(int t)
    {
        total_terms = t;
        terms = new Term[total_terms];
    }

    ~Polynomial()
    {
        delete [] terms;
    }

    int evaluate_polynomial(int);
    void display_polynomial();
};


int Polynomial :: power(int base, int exponent)
{
    if(exponent == 0)
        return 1;

    if(exponent%2==1)
        return base * power(base*base, (exponent-1)/2);
    else
        return power(base*base, exponent/2);
}


Polynomial :: Polynomial()
{
    int i;

    cout << "Enter total terms : ";
    cin >> total_terms;

    terms = new Term[total_terms];


    cout << "Enter terms (coefficient, exponent)\n";
    for(int i=0; i<total_terms; i++)
    {
        cout << "\tTerm#" << i+1 << ": ";
        cin >> terms[i].coefficient >> terms[i].exponent;
    }
}


int Polynomial :: evaluate_polynomial(int value)
{
    int sum = 0;
    for(int i=0; i<total_terms; i++)
        sum += terms[i].coefficient * power(value, terms[i].exponent);
    return sum;
}


void Polynomial :: display_polynomial()
{
    int i, j, k=0;
    cout << "\nPrinting " << total_terms <<" term(s) polynomial : \n\t";
    for(i=0; i<total_terms; i++)
    {
        cout << " " << terms[i].coefficient;

        if(terms[i].exponent==1)
            cout << "x";
        else if(terms[i].exponent==0)
            cout << "";
        else
            cout << "x^" << terms[i].exponent;

        if(i+1<total_terms && terms[i+1].coefficient>0)
            cout << " +";
    }
    cout << endl;
}


int main()
{
    cout << "\t***** An Example of Polynomial Evaluation in C++ *****\n\n";

    Polynomial p;
    int value_x;

    cout << endl;

    p.display_polynomial();

    cout << "\nEnter the value of x : ";
    cin >> value_x;

    cout << "The value of the polynomial is : " << p.evaluate_polynomial(value_x) << "\n\n";

    return 0;
}
