#ifndef STRING_H
#define STRING_H
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
	String(const char c);
	String(const char* src);
	String(const String&);
	~String();
	int getLenght() const;
	void display() const;
	void reSize(int);
	void insert(int, const String&);
	void remove(int, int = 1);
	String left(int);
	String right(int);
	String concatenate(const String&) const;
	char& at(int);
	const char& at(const int) const;
	bool isEmpty() const;
	int getSize() const;
	int find(const String& , int = 0) const;
	int replace(const String& ,const String& );
	void trimLeft();
	void trimRight();
	void trim();
	void shrink();
	void makeUpper();
	void makeLower();
	void reverse();
	int compare(const String&) const;
	long long int convertToInteger() const;
	void setNumber(const long long int);
	float convertToFloat() const;
	void concatEqual(const String&);
	void input();
	void reverseWords();
	String tokenize(String);
	void changeToNewCharSet(String cs);
};
#endif