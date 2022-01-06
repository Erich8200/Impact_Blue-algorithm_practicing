#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	string str;
	cin >> str;
	next_permutation(str.begin(), str.end());
	cout << str;
	return 0;
}
