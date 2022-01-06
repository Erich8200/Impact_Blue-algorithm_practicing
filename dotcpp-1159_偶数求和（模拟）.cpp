#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

vector<int> evenNumArr;
vector<int> avgArr;

void getEvenNum(int n)
{
	for (int i = 1; i <= n; i++)
		evenNumArr.push_back(2 * i);
}

void getAvg(int m)
{
	int len = evenNumArr.size();
	int times = len / m;
	int more = len % m;
	int sum = 0;
	for (int time = 1, i = 0; time <= times; time++, i += m)
	{
		sum = 0;
		for (int j = i; j < i + m; j++)
			sum += evenNumArr[j];
		avgArr.push_back(sum / m);
	}
	sum = 0;
	for (int rest = times*m; rest < len; rest++)
		sum += evenNumArr[rest];
	if (more)
	{
		avgArr.push_back(sum / more);
	}
}

void printAvg()
{
	for (auto it = avgArr.begin(); it < avgArr.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main(int argc, char** argv)
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		evenNumArr.clear();
		avgArr.clear();
		getEvenNum(n);
		getAvg(m);
		printAvg();
	}
	return 0;
}