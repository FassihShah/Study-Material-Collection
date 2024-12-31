#include<iostream>
#include"Polynomial.h"
using namespace std;
void Polynomial::resize()
{
    int newCapacity = capacity * 2;
    Term* newTerms = new Term[newCapacity];
    for (int i = 0; i < noOfTerms; i++)
    {
        newTerms[i] = terms[i];
    }
    delete[] terms;
    terms = newTerms;
    capacity = newCapacity;
}
Polynomial::Polynomial(int capacity) : capacity(capacity), noOfTerms(0)
{
    terms = new Term[capacity];
}
Polynomial::~Polynomial()
{
    delete[] terms;
    terms = nullptr;
    noOfTerms = 0;
}
void Polynomial::addTerm(double coefficient, int exponent)
{
    if (noOfTerms >= capacity)
        resize();
    for (int i = 0; i < noOfTerms; i++)
    {
        if (terms[i].getExponent() == exponent)
        {
            terms[i].addCoeff(coefficient);
            return;
        }
    }
    terms[noOfTerms] = Term(coefficient, exponent);
    noOfTerms++;
}

void Polynomial::display() const
{
    for (int i = 0; i < noOfTerms; i++)
    {
        int coeff = terms[i].getCoefficient();
        if (terms[i].getExponent() == 0 || coeff == 0)
            cout << coeff;
        else
            cout << terms[i].getCoefficient() << "x^" << terms[i].getExponent();
        if (i != noOfTerms - 1)
            cout << " + ";
    }
}
Polynomial Polynomial::add(const Polynomial& other) const
{
    Polynomial result;
    int i = 0, j = 0;
    while (i < noOfTerms || j < other.noOfTerms)
    {
        if (i < noOfTerms && (j >= other.noOfTerms || terms[i].getExponent() > other.terms[j].getExponent()))
        {
            result.addTerm(terms[i].getCoefficient(), terms[i].getExponent());
            i++;
        }
        else if (j < other.noOfTerms && (i >= noOfTerms || other.terms[j].getExponent() > terms[i].getExponent()))
        {
            result.addTerm(other.terms[j].getCoefficient(), other.terms[j].getExponent());
            j++;
        }
        else
        {
            double coefficient = terms[i].getCoefficient() + other.terms[j].getCoefficient();
            result.addTerm(coefficient, terms[i].getExponent());
            i++;
            j++;
        }
    }
    return result;
}
Polynomial Polynomial::multiply(const Polynomial& other) const
{
    Polynomial result;
    for (int i = 0; i < noOfTerms; i++)
    {
        for (int j = 0; j < other.noOfTerms; j++)
        {
            double c = terms[i].getCoefficient() * other.terms[j].getCoefficient();
            int e = terms[i].getExponent() + other.terms[j].getExponent();
            result.addTerm(c, e);
        }
    }
    return result;
}
Polynomial Polynomial::subtract(const Polynomial& other) const
{
    Polynomial c;
    for (int i = 0; i < other.noOfTerms; i++)
    {
        c.addTerm(other.terms[i].getCoefficient() * -1, other.terms[i].getExponent());
    }
    return c.add(*this);
}
double Polynomial::evaluate(double x) const
{
    double result = 0.0;
    for (int i = 0; i < noOfTerms; i++)
    {
        result += terms[i].getCoefficient() * pow(x, terms[i].getExponent());
    }
    return result;
}