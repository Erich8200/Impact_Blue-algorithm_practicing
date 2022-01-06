#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool check (int i)
{
 int a = i, b = i + 1, c = i + 2;
 while (a || b || c)
 {
  if ((a%10 + b%10 + c%10)/10)
   return false;
  a /= 10;
  b /= 10;
  c /= 10;
 }
 return true;
}

int main(void)
{
 int n = 0, count = 0;
 cin >> n;
 for (int i = 0; i < n; i++)
  if (check(i))
   count += 1;
 cout << count << endl;
	return 0;
}
