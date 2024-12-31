#include<iostream>
#include<fstream>
using namespace std;
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

void replaceLines(char  file[], char ch[], char  key[])
{
	fstream fs;
	fs.open(file);
	int sum = (int)ch[0] - 48;
	char lines[10][200];
	for (int i = 0; i < 10; i = i + 1)
	{
		fs.getline(lines[i], 200);
	}
	copyString(lines[sum - 1], key);
	for (int i = 0; i < 10; i = i + 1)
	{
		cout << lines[i] << "\n";
	}
	fs.seekg(0, ios::beg);
	for (int i = 0; i < 10; i = i + 1)
	{
		fs << lines[i] << "\n";
	}
	fs.close();
}

int main(int argc, char* argv[])
{
	replaceLines(argv[1], argv[2], argv[3]);
	cout << endl;
	return 0;
}