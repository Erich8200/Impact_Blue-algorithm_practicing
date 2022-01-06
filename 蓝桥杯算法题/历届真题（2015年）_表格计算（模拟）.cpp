#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#define N 1000

using namespace std;

vector< vector<string> > strTable;
double numTable[N][N];

void recordTable(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		vector<string> rowStrSet;
		for (int j = 0; j < m; j++)
		{
			string str;
			cin >> str;
			rowStrSet.push_back(str);
		}
		strTable.push_back(rowStrSet);
	}
	return;
}

int strToInt(string numStr)
{
	int num = 0;
	for (int i = 0; i < numStr.length(); i++)
		num = num * 10 + (numStr[i] - '0');
	return num;
}

void strTableToNumTable(string numStr, int row, int col)
{
	numTable[row][col] = strToInt(numStr);
}

bool check(int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			if (numTable[i][j] == -1)
				return false;
		}
	}
	return true;
}

int Count(int x1, int y1, int x2, int y2)
{
	return (x2 - x1 + 1)*(y2 - y1 + 1);
}

double Sum(int x1, int y1, int x2, int y2)
{
	double ans = 0;
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			ans += numTable[i][j];
	return ans;
}

double Avg(int x1, int y1, int x2, int y2)
{
	int count = Count(x1, y1, x2, y2);
	return Sum(x1, y1, x2, y2) / count;
}

double Std(int x1, int y1, int x2, int y2)
{
	double avg = Avg(x1, y1, x2, y2);
	double sum = 0;
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			sum += pow(numTable[i][j] - avg, 2);
	return sqrt(sum / Count(x1, y1, x2, y2));
}

void operateTable(int n, int m)
{
	//numTable表格填充非法值-1 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			numTable[i][j] = -1;

	int filled = 0;
	//填充已有的数字 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!isalpha(strTable[i][j][0]))
			{
				strTableToNumTable(strTable[i][j], i, j);
				filled += 1;
			}
		}
	}

	while (filled < n*m)
	{
		//根据已有的数字计算 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (numTable[i][j] == -1)
				{
					string formula = strTable[i][j];
					int firstCommaPos = formula.find(',');
					int colonPos = formula.find(':');
					int secondCommaPos = formula.find(',', colonPos);

					int x1 = strToInt(formula.substr(4, firstCommaPos - 4)) - 1;
					int y1 = strToInt(formula.substr(firstCommaPos + 1, colonPos - firstCommaPos - 1)) - 1;
					int x2 = strToInt(formula.substr(colonPos + 1, secondCommaPos - colonPos - 1)) - 1;
					int y2 = strToInt(formula.substr(secondCommaPos + 1, formula.length() - 1 - secondCommaPos - 1)) - 1;

					//校验失败，计算其他的公式 
					if (!check(x1, y1, x2, y2))
						continue;

					if (formula.find("SUM") != string::npos)
						numTable[i][j] = Sum(x1, y1, x2, y2);
					else if (formula.find("AVG") != string::npos)
						numTable[i][j] = Avg(x1, y1, x2, y2);
					else
						numTable[i][j] = Std(x1, y1, x2, y2);

					filled += 1;
				}
			}
		}
	}
}

void printNumTable(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%.2lf ", numTable[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	recordTable(n, m);
	operateTable(n, m);
	printNumTable(n, m);

	return 0;
}