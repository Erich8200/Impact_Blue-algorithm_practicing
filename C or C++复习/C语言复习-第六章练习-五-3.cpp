#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void change(int* a,int* row,int* column,int m,int n)
{
	//整列置1 
	for(int x = 0;x < n;x++)
	{
		if(column[x] == 1)
		{
			for(int i = 0;i < m;i++)
				*(a + i*m + x) = 1;
		}
	}
	
	//整行置1 
	for(int y = 0;y < m;y++)
	{
		if(row[y] == 1)
		{
			for(int j = 0;j < n;j++)
				*(a + y*m + j) = 1;
		}
	}	
	return;
}

int main(int argc, char** argv) 
{
	int m,n,temp;
	cout << "请输入二维数组的行m，列n的值：\n";
	cin >> m >> n;
	int* a = new int[m*n]();
	int* row = new int[m]();
	int* column = new int[n]();
	cout << "请输入二维数组中0，1信息\n";
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cin >> temp;
			*(a + m*i + j) = temp;
			if(temp == 1)
			{
				row[i] = 1;
				column[j] = 1;
			}
		}
	}
	
	change(a,row,column,m,n);
	
	cout << '\n';
	
	for(int k = 0;k < m;k++)
	{
		for(int l = 0;l < n;l++)
		{
			cout << *(a + m*k + l);
			cout << ' ';
		}
		cout << '\n';
	}
	
	delete [] column;
	delete [] row;
	delete [] a;
	return 0;
}
