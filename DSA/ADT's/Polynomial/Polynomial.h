#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include"Term.h"
class Polynomial 
{
    Term* terms;
    int capacity;
    int noOfTerms;
    void resize();
public:
    Polynomial(int capacity = 10);
    ~Polynomial();
    void addTerm(double coefficient, int exponent);
    void display() const;
    Polynomial add(const Polynomial& other) const;
    Polynomial multiply(const Polynomial& other) const;
    Polynomial subtract(const Polynomial& other) const;
    double evaluate(double x) const;
};

#endif