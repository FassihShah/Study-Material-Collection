#include<iostream>
using namespace std;
class RomanNumeral
{
	char romanNumber[100];
	int decimalNumber;
	int getLenght()
	{
		int i = 0;
		while (romanNumber[i] != '\0')
		{
			i = i + 1;
		}
		return i;
	}
	void concatenateString(const char* src, int& j)
	{
		int x = 0;
		while (src[x] != '\0')
		{
			romanNumber[j] = src[x];
			x = x + 1;
			j = j + 1;
		}
	}
	void copyString(char* const dest, const char* const src)
	{
		int i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i = i + 1;
		}
		dest[i] = '\0';
	}
	int getValue(const char ch)
	{
		switch (ch)
		{
		case 'M':
			return 1000;
		case 'D':
			return 500;
		case 'C':
			return 100;
		case 'L':
			return 50;
		case 'X':
			return 10;
		case 'V':
			return 5;
		case 'I':
			return 1;
		}
	}
	void getAlpha(int& value, int& i)
	{
		if (value == 4)
		{
			value = value - 4;
			concatenateString("IV", i);
		}
		else if (value < 5)
		{
			value = value - 1;
			concatenateString("I", i);
		}
		else if (value == 9)
		{
			value = value - 9;
			concatenateString("IX", i);
		}
		else if (value < 10)
		{
			value = value - 5;
			concatenateString("V", i);
		}
		else if (value >= 40 && value <= 49)
		{
			value = value - 40;
			concatenateString("XL", i);
		}
		else if (value < 50)
		{
			value = value - 10;
			concatenateString("X", i);
		}
		else if (value >= 90 && value <= 99)
		{
			value = value - 90;
			concatenateString("XC", i);
		}
		else if (value < 100)
		{
			value = value - 50;
			concatenateString("L", i);
		}
		else if (value >= 400 && value <= 499)
		{
			value = value - 400;
			concatenateString("CD", i);
		}
		else if (value < 500)
		{
			value = value - 100;
			concatenateString("C", i);
		}
		else if (value >= 900 && value <= 999)
		{
			value = value - 900;
			concatenateString("CM", i);
		}
		else if (value < 1000)
		{
			value = value - 500;
			concatenateString("D", i);
		}
		else
		{
			value = value - 1000;
			concatenateString("M", i);
		}
	}
	void convertRomanNumberToDecimal()
	{
		int i = getLenght() - 1;
		int value, sum = 0, maxNumeral = 0;
		for (; i >= 0; i = i - 1)
		{
			value = getValue(romanNumber[i]);
			if (maxNumeral <= value)
			{
				sum = sum + value;
				maxNumeral = value;
			}
			else
			{
				sum = sum - value;
			}
		}
		decimalNumber = sum;
	}
	void convertDecimalNumberToRoman()
	{
		int temp = decimalNumber, i = 0;
		while (temp != 0)
		{
			getAlpha(temp, i);
		}
		romanNumber[i] = '\0';
	}
public:
	int getDecimalNumber()
	{
		return decimalNumber;
	}
	const char* getRomanNumber()
	{
		return romanNumber;
	}
	void setDecimalNumber(int num)
	{
		decimalNumber = num;
		convertDecimalNumberToRoman();
	}
	void setRomanNumber(const char* rn)
	{
		copyString(romanNumber, rn);
		convertRomanNumberToDecimal();
	}
};
int main()
{
	RomanNumeral rn;
	//rn.setRomanNumber("MCXIV");
	rn.setDecimalNumber(1943);
	cout << rn.getRomanNumber() << '\n';
	cout << rn.getDecimalNumber() << '\n';
	cout << endl;
	return 0;
}