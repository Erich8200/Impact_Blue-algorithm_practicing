#include <iostream>
#include <stdio.h>
#include <list>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input0.txt", "r", stdin);
	list<int> numList;
	int num = 0;
	while (cin >> num)
	{
		if (num == 0)
			break;
		numList.push_back(num);
	}
	
	numList.reverse();
	
	for (list<int>::iterator it = numList.begin(); it != numList.end(); it++)
	{
		if (it == --numList.end())
			cout << *it ;
		else
			cout << *it << " ";
	}
	fclose(stdin);
	return 0;
}
