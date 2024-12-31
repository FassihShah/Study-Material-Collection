#include"Term.h"
Term::Term(double c, int e)
{
    coeff = c;
    exp = e;
}
Term::Term()
{
    coeff = 0;
    exp = 0;
}
double Term::getCoefficient() const
{
    return coeff;
}
int Term::getExponent() const
{
    return exp;
}
void Term::addCoeff(double value)
{
    coeff += value;
}