#ifndef TERM_H
#define TERM_H
class Term
{
    double coeff;
    int exp;
public:
    Term(double c, int e);
    Term();
    double getCoefficient() const;
    int getExponent() const;
    void addCoeff(double value);
};


#endif