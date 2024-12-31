#include"Complex.h"
#include<iostream>
using namespace std;
Complex::Complex()
{
	this->~Complex();
}
Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}
double Complex::getReal() const
{
	return real;
}
double Complex::getImag() const
{
	return imag;
}
void Complex::setReal(double r)
{
	real = r;
}
void Complex::setImag(double i)
{
	imag = i;
}
Complex Complex::add(const Complex& c)
{
	return Complex(real + (c.getReal()), imag + c.getImag());
}
Complex Complex::subtract(const Complex& c)
{
	return Complex(real - (c.getReal()), imag - c.getImag());
}
Complex Complex::multiply(const Complex& c)
{
	Complex m;
	m.setReal((real * c.getReal()) - (imag * c.getImag()));
	m.setImag((c.getReal() * imag) + (real * c.getImag()));
	return m;
}
Complex Complex::divide(const Complex& c)
{
	Complex m;
	m.setReal(((real * c.getReal()) + (imag * c.getImag())) / ((c.getReal() * c.getReal()) - (c.getImag() * c.getImag())));
	m.setImag(((c.getReal() * imag) - (real * c.getImag())) / ((c.getReal() * c.getReal()) - (c.getImag() * c.getImag())));
	return m;
}
Complex Complex::conjugate()
{
	return Complex(real, imag * -1);
}
void Complex::display()
{
	if (imag < 0)
	{
		cout << real << " - " << imag * -1 << "i\n";
	}
	else
	{
		cout << real << " + " << imag << "i\n";
	}
}
Complex::~Complex()
{
	real = 0;
	imag = 0;
}