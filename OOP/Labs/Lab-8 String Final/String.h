#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
class String
{
	int size;
	char* data; 
	void copyString(char* const, const char* const) const;
	void conctString(char* const, const char* const) const;
	bool isSubString(const char* , const char* , int) const;
	int tellLenght(const char* const) const;
	int getNumLenght(const long long int);
	bool isDelimeter(const String&, const char);
public:
	String();
	String(const char);
	String(const char* );
	String(const String&);
	String(String&&);
	String& operator =(String&&);
	String& operator =(const String&);
	~String();
	void input();
	void shrink();
	char& operator [](const int);
	const char& operator [](const int) const;
	bool operator !() const;
	int getLenght() const;
	int getSize() const;
	void display() const;
	int find(const String&, const int = 0) const;
	void insert(const int, const String&);
	void remove(const int, const int = 1);
	int replace(const String&, const String&);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int);
	bool operator ==(const String&) const;
	bool operator >(const String&) const;
	bool operator <(const String&) const;
	bool operator >=(const String&) const;
	bool operator <=(const String&) const;
	bool operator !=(const String&) const;
	String left(const int);
	String right(const int);
	String operator +(const String&) const;
	void operator +=(const String&);
	String& operator=(const long long int);
	String& operator=(const double);
	explicit operator long long int() const;
	explicit operator double() const;
	explicit operator bool() const;
	String operator ()(const String&);
	friend ostream& operator <<(ostream&, const String&);
	friend istream& operator >>(istream&, String&);

	//--------EXTRA FUNCTIONS----------//
	String operator -(const String&) const;
	void operator -=(const String&);
	friend String operator +(const char*, String);
	String concatenate(const String&) const;
	bool isEmpty() const;
	int compare(const String&) const;
	long long int convertToInteger() const;
	void setNumber(const long long int);
	float convertToFloat() const;
	void concatEqual(const String&);
	void reverseWords();
	String tokenize(String);
	void changeToNewCharSet(String);
};
#endif