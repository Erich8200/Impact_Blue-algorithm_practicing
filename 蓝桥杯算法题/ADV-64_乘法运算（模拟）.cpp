#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

char A[7][4];

void solve(int a, int b)
{
	int res = a * b;
	A[0][3] = a % 10 + '0';
	A[0][2] = (a / 10 == 0 && (int)log(a) + 1 < 2 ? ' ' : a / 10 + '0');
	A[1][0] = '*';
	A[1][1] = (b / 10 == 0 && (int)log(b) + 1 < 2 ? ' ' : b / 10 + '0');
	A[1][2] = b % 10 + '0';
	A[2][0] = A[2][1] = A[2][2] = '-';
	int temp1 = (b % 10)*a, temp2 = (b / 10)*a;
	A[3][3] = temp1 % 10 + '0';
	A[3][2] = (temp1 / 10 % 10 == 0 && (int)log(temp1) + 1 < 2 ? ' ' : temp1 / 10 % 10 + '0');
	A[3][1] = (temp1 / 100 == 0 && (int)log(temp1) + 1 < 3 ? ' ' : temp1 / 100 + '0');
	if (temp2 == 0) return;
	A[4][2] = temp2 % 10 + '0';
	A[4][1] = (temp2 / 10 % 10 == 0 && (int)log(temp2) + 1 < 2 ? ' ' : temp2 / 10 % 10 + '0');
	A[4][0] = (temp2 / 100 == 0 && (int)log(temp2) + 1 < 3 ? ' ' : temp2 / 100 + '0');
	A[5][0] = A[5][1] = A[5][2] = '-';
	A[6][3] = res % 10 + '0';
	A[6][2] = (res / 10 % 10 == 0 && (int)log(res) + 1 < 2 ? ' ' : res / 10 % 10 + '0');
	A[6][1] = (res / 100 == 0 && (int)log(res) + 1 < 3 ? ' ' : res / 100 % 10 + '0');
	A[6][0] = (res / 1000 == 0 && (int)log(res) + 1 < 4 ? ' ' : res / 1000 + '0');
}

void clearA()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (A[i][j] == '\0' || A[i][j] == ' ')
				continue;
			else if (A[i][j] == '0')
			{
				A[i][j] = '\0';
				break;
			}
			else if (A[i][j] >= '1' && A[i][j] <= '9')
				break;
		}
	}
	if (A[3][0] == '\0' && A[3][1] == ' ' && A[3][2] == ' ' && A[3][3] == '\0')
		A[3][2] = A[3][3] = '0';
	if (A[4][0] == '\0' && A[4][1] == ' ' && A[4][2] == ' ' && A[4][3] == '\0')
		A[4][2] = A[4][3] = '0';
}

int main(int argc, char** argv)
{
	int a, b;
	cin >> a >> b;
	solve(a, b);
	clearA();
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (A[i][j] == '*')
				cout << "¡Á";
			else if (A[i][j] == '-')
			{
				cout << "©¥©¥©¥";
				break;
			}
			else
				cout << A[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}