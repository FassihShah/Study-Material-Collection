#include"Calculator.h"
#include"Stack.h"
Calculator::Calculator(String inf)
{
    infix = inf;
    delimeter = ',';
}
int Calculator::getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}
String Calculator::infixToPostfix()
{
    String postfix;
    Stack<char> operators(infix.getLenght());
    for (int i = 0; i < infix.getLenght();)
    {
        if (infix[i] == ')')
        {
            while (!operators.isEmpty() && operators.top() != '(')
            {
                postfix += operators.pop();
            }
            operators.pop();
            i++;
        }
        else if (getPrecedence(infix[i]) || infix[i] == '(')
        {
            if ((getPrecedence(infix[i]) > getPrecedence(operators.top())) || operators.isEmpty() || infix[i] == '(')
            {
                operators.push(infix[i]);
            }
            else
            {
                while (getPrecedence(infix[i]) <= getPrecedence(operators.top()))
                {
                    postfix += operators.pop();
                }
                operators.push(infix[i]);
            }
            i++;
        }
        else
        {
            while (infix[i] >= '0' && infix[i] <= '9' && i < infix.getLenght())
            {
                postfix += infix[i];
                i++;
            }
            postfix += delimeter;
        }
    }
    while (!operators.isEmpty())
    {
        postfix += operators.pop();
    }
    return postfix;
}
String Calculator::infixToPrefix()
{
    infix.reverse();
    String prefix;
    Stack<char> operators(infix.getLenght());
    for (int i = 0; i < infix.getLenght();)
    {
        if (infix[i] == '(')
        {
            while (!operators.isEmpty() && operators.top() != ')')
            {
                prefix += operators.pop();
            }
            operators.pop();
            i++;
        }
        else if (getPrecedence(infix[i]) || infix[i] == ')')
        {
            if ((getPrecedence(infix[i]) > getPrecedence(operators.top())) || operators.isEmpty() || infix[i] == ')')
            {
                operators.push(infix[i]);
            }
            else
            {
                while (getPrecedence(infix[i]) < getPrecedence(operators.top()))
                {
                    prefix += operators.pop();
                }
                operators.push(infix[i]);
            }
            i++;
        }
        else
        {
            while (infix[i] >= '0' && infix[i] <= '9' && i < infix.getLenght())
            {
                prefix += infix[i];
                i++;
            }
            prefix += delimeter;
        }
    }
    while (!operators.isEmpty())
    {
        prefix += operators.pop();
    }
    prefix.reverse();
    return prefix;
}
int Calculator::evaluatePostfix()
{
    Stack<int> operands(infix.getLenght());
    infix = infixToPostfix();
    for (int i = 0; i < infix.getLenght();)
    {
        if (getPrecedence(infix[i]))
        {
            int op1 = operands.pop();
            int op2 = operands.pop();
            switch (infix[i])
            {
            case '+':
                operands.push(op2 + op1);
                break;
            case '-':
                operands.push(op2 - op1);
                break;
            case '*':
                operands.push(op2 * op1);
                break;
            case '/':
                operands.push(op2 / op1);
                break;
            case '^':
                operands.push(pow(op2, op1));
                break;
            }
            i++;
        }
        else
        {
            int x = 0;
            while (infix[i] != delimeter)
            {
                x = x * 10 + (infix[i] - '0');
                i++;
            }
            operands.push(x);
            i++;
        }
    }
    return operands.pop();
}
int Calculator::evaluatePrefix()
{
    Stack<int> operands(infix.getLenght());
    infix = infixToPrefix();
    for (int i = infix.getLenght() - 1; i >= 0;)
    {
        if (getPrecedence(infix[i]))
        {
            int op2 = operands.pop();
            int op1 = operands.pop();
            switch (infix[i])
            {
            case '+':
                operands.push(op2 + op1);
                break;
            case '-':
                operands.push(op2 - op1);
                break;
            case '*':
                operands.push(op2 * op1);
                break;
            case '/':
                operands.push(op2 / op1);
                break;
            case '^':
                operands.push(pow(op2, op1));
                break;
            }
            i--;
        }
        else if (infix[i] >= '0' && infix[i] <= '9')
        {
            int x = 0;
            int k = i;
            while (infix[i] != delimeter)
            {
                i--;
            }
            int j = i;
            i++;
            while (i <= k)
            {
                x = x * 10 + (infix[i] - '0');
                i++;
            }
            i = j;
            operands.push(x);
            i--;
        }
    }
    return operands.pop();
}