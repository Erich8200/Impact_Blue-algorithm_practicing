#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

int materialCount[4];
int useCount[5][4] = { {2,1,0,2},{1,1,1,1},{0,0,2,1},{0,3,0,0},{1,0,0,1} };
int productCount[5];

bool satisfy(int useIndex)
{
	if (useCount[useIndex][0] <= materialCount[0] && useCount[useIndex][1] <= materialCount[1] && useCount[useIndex][2] <= materialCount[2] && useCount[useIndex][3] <= materialCount[3])
	{
		materialCount[0] -= useCount[useIndex][0];
		materialCount[1] -= useCount[useIndex][1];
		materialCount[2] -= useCount[useIndex][2];
		materialCount[3] -= useCount[useIndex][3];
		return true;
	}
	else
		return false;
}

void solve()
{
	for (int i = 0;i < 5;i++)
		while (satisfy(i))
			productCount[i] += 1;
	return;
}

int main(int argc, char** argv)
{
	for (int i = 0; i < 4; i++)
		cin >> materialCount[i];
	solve();
	for (int i = 0; i < 5; i++)
		cout << productCount[i] << endl;
	return 0;
}