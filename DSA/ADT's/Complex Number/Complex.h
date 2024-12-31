#ifndef COMPLEX_H
#define COMPLEX_H
class Complex
{
	double real;
	double imag;
public:
	Complex();
	Complex(double r, double i);
	double getReal() const;
	double getImag() const;
	void setReal(double);
	void setImag(double);
	Complex add(const Complex&);
	Complex subtract(const Complex&);
	Complex multiply(const Complex&);
	Complex divide(const Complex&);
	Complex conjugate();
	void display();
	~Complex();
};
#endif