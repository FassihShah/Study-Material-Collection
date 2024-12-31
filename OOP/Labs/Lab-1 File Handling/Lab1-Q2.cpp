#include<iostream>
#include<fstream>
using namespace std;
int countNumberOfLines(char  file[])
{
	ifstream ifs;
	ifs.open(file);
	int a, sum = 0;
	char ch;
	while ((ch = ifs.get()) != EOF)
	{
		if (ch == '\n')
		{
			sum = sum + 1;
		}
	}
	return sum;
}
int main(int argc, char* argv[])
{
	cout << countNumberOfLines(argv[1]);
	cout << endl;
	return 0;
}