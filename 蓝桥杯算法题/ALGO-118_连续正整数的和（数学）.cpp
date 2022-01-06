#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define EPS 0.000001

using namespace std;

map<int, int> result;

void solve (int n) 
{
 double a = 1;
 while (a <= n/2)
 {
  double b = (sqrt(1+4*(a*a-a+2*n))-1)/2;
  if (b - (int)b < EPS)
   result[(int)a] = (int)b;
  a += 1;
 }
}

int main(void)
{
 freopen("input10.txt", "r", stdin);
 int n = 0;
 cin >> n;
 solve(n);
 for (map<int, int>::iterator it = result.begin(); it != result.end(); it++)
  cout << it->first << " " << it->second << endl;
	return 0;
}
