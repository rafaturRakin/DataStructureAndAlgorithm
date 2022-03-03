#include<iostream>

using namespace std;

/*
    Author: Rakin
    Date:  03-03-2022
    Language: C++
    Content:  Polynomial Addition
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

    Polynomial add_polynomial(Polynomial);
    void display_polynomial();
};

Polynomial :: Polynomial()
{
    int i;

    cout << "Enter total terms : ";
    cin >> total_terms;

    terms = new Term[total_terms];

    cout << "Enter terms (coefficient, exponent)\n";
    for(int i=0; i<total_terms; i++)
    {
        cout << "\tTerm# " << i+1 << ":";
        cin >> terms[i].coefficient >> terms[i].exponent;
    }
}

Polynomial Polynomial :: add_polynomial(Polynomial p)
{
    int i, j, k;
    Polynomial *sum = new Polynomial(total_terms + p.total_terms);

    i = j = k = 0;

    while(i<total_terms && j<p.total_terms)
    {
        if(terms[i].exponent > p.terms[j].exponent)
            sum->terms[k++] = terms[i++];
        else if(terms[i].exponent < p.terms[j].exponent)
            sum->terms[k++] = p.terms[j++];
        else
        {
            sum->terms[k] = terms[i];
            sum->terms[k++].coefficient = terms[i++].coefficient + p.terms[j++].coefficient;
        }
    }

    while(i<total_terms)
        sum->terms[k++] = terms[i++];

    while(j<p.total_terms)
        sum->terms[k++] = p.terms[j++];

    sum->total_terms = k;
    return *sum;
}

void Polynomial :: display_polynomial()
{
    int i, j, k=0;
    cout << "\nPrinting " << total_terms << " term(s) polynomial : \n\t";
    for(i=0; i<total_terms; i++)
    {
        cout << terms[i].coefficient << "x";

        if(terms[i].exponent!=1 || terms[i].exponent!=0)
            cout << "^" << terms[i].exponent;

        if(i+1<total_terms && terms[i+1].coefficient>0)
            cout << "+";
    }
    cout << "\n";
}


int main()
{
    cout << "\t***** An Example of Polynomial Addition in C++ *****\n\n";

    cout << ("Creating first polynomial...\n");
    Polynomial p1;

    cout << "\nCreating second polynomial...\n";
    Polynomial p2;

    cout << endl;

    Polynomial sum = p1.add_polynomial(p2);

    cout << "\t\t *** Displaying Polynomials ***\n";
    p1.display_polynomial();
    p2.display_polynomial();

    cout << "\nSum of the 2 polynomials is";
    sum.display_polynomial();

    return 0;
}


