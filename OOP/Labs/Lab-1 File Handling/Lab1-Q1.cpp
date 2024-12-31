#include<iostream>
#include<fstream>
using namespace std;
int readCommaSeparatedNums(char  file[])
{
	ifstream ifs;
	ifs.open(file);
	int a, sum = 0;
	char ch;
	ifs >> sum;
	while (!ifs.eof())
	{
		ch = ifs.get();
		if (ch == ',')
		{
			if (!ifs.eof())
			{
				ifs >> a;
				sum = sum + a;
			}
		}
	}
	return sum;
}
int main(int argc, char* argv[])
{
	cout << readCommaSeparatedNums(argv[1]);
	cout << endl;
	return 0;
}