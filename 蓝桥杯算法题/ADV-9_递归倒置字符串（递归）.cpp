#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <stdio.h>
#define N 40

using namespace std;

void rev(int cur, const int n, string & str)
{
	if (cur >= n / 2) return;
	char temp = str[cur];
	str[cur] = str[n - cur - 1];
	str[n - cur - 1] = temp;
	cout << str << endl;
	rev(cur + 1, n, str);
}

int main(int argc, char** argv)
{
	int n = 0;
	string s;
	cin >> n >>  s;
	rev(0, n, s);
	cout << endl << s << endl;
	system("pause");
	return 0;
}