#include<iostream>
#include<fstream>
#include"GenericMatrix_Implementation.cpp"
using namespace std;
int main()
{
	ofstream ofs("rotate oops.pgm");
	ifstream ifs("OOPS.pgm");
	char ch = 'a';
	int cnt = 1;
	int count = 0;
	int y = 0;
	String s;
	s.reSize(100);
	for (int i = 0; i < 3;)
	{

		ifs.get(ch);
		ofs << ch;
		s[count] = ch;
		count++;
		if (ch == '#')
		{
			cnt = 2;
			i--;
		}
		if (ch == '\n')
		{
			i++;
		}
	}
	s[count] = '\0';
	int num = 0;
	ifs.seekg(0, ios::beg);
	for (int i = 0; i < cnt;)
	{
		num++;
		ifs.get(ch);
		if (ch == '\n')
			i++;
	}
	//cout << count;
	int x;
	ifs >> x;
	int cols = x;
	ifs >> x;
	int rows = x;
	String co, ro;
	co = (long long int)cols;
	ro = (long long int)rows;
	s.replace(co, '&');
	s.replace(ro, '?');
	s.replace('&', ro);
	s.replace('?', co);
	ifs.seekg(count + 2);
	Matrix<int> m(rows, cols);
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			ifs >> m[i][j];
		}
	}
	Matrix<int> rotated = m.transpose();
	int r = rotated.getColums() - 1;
	Matrix<int> temp = rotated;
	for (int i = 0; i < rotated.getColums() - 1; i++)
	{
		for (int j = 0; j < rotated.getRows(); j++)
		{
			temp[j][r] = rotated[j][i];
		}
		r--;
	}
	for (int i = 0; i < temp.getRows(); i = i + 1)
	{
		for (int j = 0; j < temp.getColums(); j = j + 1)
		{
			ofs << temp[i][j];
			if (temp[i][j] < 10)
				ofs << ' ';
			ofs << " ";
		}
		ofs << "\n";
	}
	ofs.seekp(0);
	ofs << s;
	ofs.close();
	ifs.close();
	cout << s;
	return 0;
}