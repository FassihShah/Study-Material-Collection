#include<iostream>
#include "String.h"
using namespace std;
bool String::isDelimeter(const String& s, const char ch)
{
	if (s.isEmpty())
		return false;
	int lenght = s.getLenght(), i = 0;
	bool status = false;
	while (i < lenght && status == false)
	{
		if (ch == s.data[i])
		{
			status = true;
		}
		i = i + 1;
	}
	return status;
}
void String::copyString(char* const dest, const char* const src) const
{
	int i = 0;
	if (src == nullptr)
	{
		return;
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
}
int String::getNumLenght(const long long int num)
{
	int count = 0;
	long long int n = (num < 0 ? num * -1 : num);
	while (n > 0)
	{
		n = n / 10;
		count = count + 1;
	}
	return count;
}
void String::conctString(char* const dest, const char* const src) const
{
	if (src == nullptr)
		return;
	int i = 0, j = tellLenght(dest);
	cout << j;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i = i + 1;
		j = j + 1;
	}
	dest[j] = '\0';
}
bool String::isSubString(const char* destination, const char* key, int start = 0) const
{
	int  j = 0, lenght = tellLenght(key), end = start + lenght;
	while (start < end)
	{
		if (destination[start] == key[j])
		{
			j = j + 1;
		}
		else
		{
			j = 0;
		}
		start = start + 1;
	}
	return j == lenght ? true : false;
}
int String::tellLenght(const char* const src) const
{
	int i = 0;
	if (src == nullptr)
	{
		return 0;
	}
	while (src[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const char c)
{
	data = new char[2];
	size = 2;
	data[0] = c;
	data[1] = '\0';
}
String::String(const char* src) :String()
{
	size = tellLenght(src);
	if (size == 0)
	{
		return;
	}
	size = size + 1;
	data = new char[size];
	copyString(data, src);
}
String::String(const String& ref) :String()
{
	if (ref.size == 0)
		return;
	size = ref.size;
	data = new char[size];
	copyString(data, ref.data);
}
int String::getLenght() const
{
	return tellLenght(data);
}
void String::display() const
{
	if (data)
		cout << data;
}
void String::reSize(int cap)
{
	if (cap <= 0)
	{
		this->~String();
		return;
	}
	char* temp = new char[cap + 1];
	temp[0] = '\0';
	if (!isEmpty())
	{
		int i;
		for (i = 0; i < cap && i < getLenght(); i = i + 1)
		{
			temp[i] = data[i];
		}
		temp[i] = '\0';
	}
	this->~String();
	size = cap + 1;
	data = temp;
}
void String::insert(const int index, const String& subStr)
{
	int lenght = getLenght(), subLenght = subStr.getLenght(), count = 0, k = index;
	if (size <= lenght + subLenght)
	{
		reSize(lenght + subLenght);
	}
	char* temp = new char[lenght - index + 1];
	for (int i = index; i < lenght; i = i + 1)
	{
		temp[count] = data[i];
		count = count + 1;
	}
	temp[count] = '\0';
	count = 0;
	while (count < subLenght)
	{
		data[k] = subStr.data[count];
		k = k + 1;
		count = count + 1;
	}
	count = 0;
	while (temp[count] != '\0')
	{
		data[k] = temp[count];
		k = k + 1;
		count = count + 1;
	}
	data[k] = '\0';
}
void String::remove(const int index, const int count )
{
	int lenght = getLenght(), i = index;
	while (i < lenght - count)
	{
		data[i] = data[i + count];
		i = i + 1;
	}
	data[i] = '\0';
}
char& String::at(const int index)
{
	if (index >= 0 && index < size)
	{
		return data[index];
	}
	cout << "\nIndex is out of bound";
	exit(0);
}
const char& String::at(const int index) const
{
	if (index >= 0 && index < size)
	{
		return data[index];
	}
	cout << "\nIndex is out of bound";
	exit(0);
}
bool String::isEmpty() const
{
	if (data == nullptr || getLenght() == 0)
	{
		return true;
	}
	return false;
}
int String::getSize() const
{
	return size;
}
int String::find(const String& subStr, const int start ) const
{
	int j = 0, lenght = subStr.getLenght(), count = 0, i = start;
	if (data == nullptr || subStr.data == nullptr)
		return 0;
	while (data[i] != '\0')
	{
		if ((isSubString(data, subStr.data, i)) == 1)
		{
			return i;
		}
		i = i + 1;
	}
	return -1;
}
int String::replace(const String& old, const String& newSubStr)
{
	int count = 0, subLenght = newSubStr.getLenght();
	int oldLenght = old.getLenght(), index = find(old);
	if (data == nullptr || old.data == nullptr)
		return 0;
	while (index != -1)
	{
		remove(index, oldLenght);
		insert(index, newSubStr);
		index = find(old, index + subLenght);
		count = count + 1;
	}
	return count;
}
void String::trimLeft()
{
	int index = 0, i = 0;
	while (data[index] == '\t' || data[index] == ' ' || data[index] == '\n')
	{
		index = index + 1;
	}
	if (index == 0)
		return;
	for (; index < getLenght(); i = i + 1, index = index + 1)
	{
		data[i] = data[index];
	}
	data[i] = '\0';
}
void String::trimRight()
{
	int index = getLenght() - 1;
	while (data[index] == '\t' || data[index] == ' ' || data[index] == '\n')
	{
		index = index - 1;
	}
	if (index == getLenght() - 1)
		return;
	data[index + 1] = '\0';
}
void String::trim()
{
	trimLeft();
	trimRight();
}
void String::shrink()
{
	reSize(getLenght());
}
void String::makeUpper()
{
	for (int i = 0; i < getLenght(); i = i + 1)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - 32;
		}
	}
}
void String::makeLower()
{
	for (int i = 0; i < getLenght(); i = i + 1)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
	}
}
void String::reverse()
{
	if (isEmpty())
		return;
	char* temp = new char[size];
	int i = 0, j = getLenght() - 1;;
	while (j >= 0)
	{
		temp[i] = data[j];
		i = i + 1;
		j = j - 1;
	}
	temp[i] = '\0';
	data = temp;
}
int String::compare(const String& s2) const
{
	int lenght1 = getLenght(), lenght2 = s2.getLenght(), count = 0, sum;
	bool status = true;
	while ((count < lenght1 && count < lenght2) && status)
	{
		sum = data[count] - s2.data[count];
		status = (sum == 0 ? true : false);
		count = count + 1;
	}
	if (status == true)
	{
		if (lenght2 == lenght1)
		{
			return 0;
		}
		else if (count == lenght2)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	if (sum > 0)
	{
		return 1;
	}
	return -1;
}
String String::left(const int count)
{
	String temp;
	if (count >= getLenght())
	{
		temp.reSize(getLenght());
		copyString(temp.data, data);
		return temp;
	}
	temp.reSize(count);
	if (count == 0)
		return temp;
	for (int i = 0; i < count && data[i] != '\0'; i = i + 1)
	{
		temp.data[i] = data[i];
	}
	temp.data[count] = '\0';
	return temp;
}
String String::right(const int count)
{
	String temp;
	if (count >= getLenght())
	{
		temp.reSize(getLenght());
		copyString(temp.data, data);
		return temp;
	}
	temp.reSize(count);
	if (count == 0)
		return temp;
	int j = count;
	j = getLenght() - j;
	for (int i = 0; data[j] != '\0'; i = i + 1, j = j + 1)
	{
		temp.data[i] = data[j];
	}
	temp.data[temp.size] = '\0';
	return temp;
}
String String::concatenate(const String& s2) const
{
	String temp;
	temp.reSize(getLenght() + s2.getLenght());
	copyString(temp.data, data);
	conctString(temp.data, s2.data);
	return temp;
}
void String::input()
{
	char ch;
	int index = getLenght();
	//cout << "\nEnter the string : ";
	cin.get(ch);
	while (ch != '\n')
	{
		if (index == size)
		{
			reSize((size == 0 ? 1 : size) * 2);
		}
		data[index] = (char)ch;
		index = index + 1;
		cin.get(ch);
	}
	if (index == size)
		reSize(size + 1);
	data[index] = '\0';
}
long long int String::convertToInteger() const
{
	long long int result = 0;
	int sign = 1;
	int i = 0;
	if (data[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	for (; i < size; i = i + 1)
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			result = result * 10 + (data[i] - '0');
		}
	}
	return result * sign;
}
float String::convertToFloat() const
{
	int index = 0, sign = 1;
	float result = 0;
	if (data[index] == '-')
	{
		sign = -1;
		index = 1;
	}
	while (data[index] != '.' && (index < getLenght()))
	{
		result = result * 10 + (data[index] - '0');
		index = index + 1;
	}
	float d = 10;
	index = index + 1;
	while (index < getLenght())
	{
		result = result + (data[index] - '0') / d;
		d = d * 10;
		index = index + 1;
	}
	return result * sign;
}
void String::setNumber(const long long int num)
{
	int index = 0, lenght, i = 1, div = 1;
	lenght = getNumLenght(num);
	this->~String();
	reSize(lenght + 2);
	if (num == 0)
	{
		data[0] = '0';
		data[1] = '\0';
		return;
	}
	long long int n = (num < 0 ? num * -1 : num);
	if (num < 0)
	{
		data[0] = '-';
		index = 1;
	}
	while (i < lenght)
	{
		div = div * 10;
		i = i + 1;
	}
	while (lenght)
	{
		data[index] = (n / div) + '0';
		n = n % div;
		div = div / 10;
		index = index + 1;
		lenght = lenght - 1;
	}
	data[index] = '\0';
}
void String::concatEqual(const String& s2)
{
	if (getSize() <= getLenght() + s2.getLenght())
		reSize(getLenght() + s2.getLenght());
	conctString(data, s2.data);
}
void String::reverseWords()
{
	if (isEmpty())
		return;
	String s;
	s.reSize(getSize());
	copyString(s.data, data);
	int index = 0;
	while (!isEmpty())
	{
		String temp = tokenize("\"':; ,!?.-_()");
		temp.reverse();
		s.remove(index, temp.getLenght());
		s.insert(index, temp);
		index = index + temp.getLenght() + 1;
	}
	s.data[index] = '\0';
	copyString(data, s.data);
}
String String::tokenize(String s)
{
	int tokenIndex = 0;
	String temp;
	if (isEmpty())
		return temp;
	int i = 0;
	while (!isDelimeter(s, data[tokenIndex]))
	{
		temp.reSize(temp.getSize() + 1);
		temp.data[i] = data[tokenIndex];
		i = i + 1;
		tokenIndex = tokenIndex + 1;
	}
	remove(0, i + 1);
	temp.reSize(temp.getSize() + 3);
	temp.data[i] = '\0';
	return temp;
}
void String::changeToNewCharSet(String cs)
{
	int lenght = getLenght(), i = 0;
	char ch;
	while (i < lenght)
	{
		ch = data[i];
		if (ch >= 97 && ch <= 123)
		{
			data[i] = cs.data[ch - 'a'];
		}
		i = i + 1;
	}
}
String :: ~String()
{
	if (size == 0)
	{
		return;
	}
	delete[]data;
	data = nullptr;
	size = 0;

}