#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stdio.h>
#include <cctype>

#define N 6

using namespace std;

set<int> A, B, U, I, C;

int main(int argc, char** argv)
{
	int n = 0, m = 0, i = 0, temp = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> temp;
		A.insert(temp);
	}
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> temp;
		B.insert(temp);
	}
		
	set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(U, U.begin()));
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(I, I.begin()));
	set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));

	set<int>::iterator it;

	for (it = I.begin(), i = 0; it != I.end(); it++, i++)
	{
		if (i == I.size() - 1)
			cout << *it << endl;
		else
			cout << *it << " ";
	}

	for (it = U.begin(), i = 0; it != U.end(); it++, i++)
	{
		if (i == U.size()-1)
			cout << *it << endl;
		else
			cout << *it << " ";
	}

	for (it = C.begin(), i = 0; it != C.end(); it++, i++)
	{
		if (i == C.size()-1)
			cout << *it << endl;
		else
			cout << *it << " ";
	}
	
	system("pause");
	return 0;
}