#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int solve(int n)
{
 vector<int> str;
 for (int i = 1; i <= n; i++)
  str.push_back(i);
 int index = 0;
 vector<int>::iterator it = str.begin();
 while (str.size() > 1)
 {
  index = (index + 2)%str.size();
  it = str.begin() + index;
  it = str.erase(it);
  index = it - str.begin();
 }
 return str.at(0);
}

int main(void)
{
 int n = 0;
 cin >> n;
 cout << solve(n) << endl;
	return 0;
}
