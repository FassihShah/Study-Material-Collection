#ifndef CALCULATOR_H
#define CALCULATOR_H
#include"String.h"
class Calculator
{
	String infix;
	char delimeter;
	int getPrecedence(char);
public:
	Calculator(String);
	String infixToPostfix();
	String infixToPrefix();
	int evaluatePostfix();
	int evaluatePrefix();
};
#endif