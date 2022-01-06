#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

class Matrix{
public:
	int dimen;
	map<int, int> mat;
	Matrix product(Matrix& A2);
	bool checkI();
};

Matrix Matrix::product(Matrix& A2)
{
	Matrix ans;
	ans.dimen = this->dimen;
	for (map<int, int>::iterator it = mat.begin(); it != mat.end(); it++)
	{
		int row1 = it->first;
		int col1 = it->second;
		int row2 = col1;
		int col2;
		for (map<int, int>::iterator itt = A2.mat.begin(); itt != A2.mat.end(); itt++)
		{
			if (itt->first == col1)
			{
				col2 = itt->second;
				break;
			}
		}
		ans.mat[row1] = col2;
	}
	return ans;
}

bool Matrix::checkI()
{
	for (map<int, int>::iterator it = mat.begin(); it != mat.end(); it++)
	{
		if (it->first != it->second)
			return false;
	}
	return true;
}

int main(void)
{
	Matrix A, A2;
	cin >> A.dimen;
	for (int i = 0; i < A.dimen; i++)
	{
		int a, b;
		cin >> a >> b;
		A.mat[a] = b;
	}
	
	A2 = A;
	int times = 1;
	
	while(!A2.checkI())
	{
		A2 = A2.product(A);
		times += 1;
	}

	cout << times << "\n";
	return 0;
}
