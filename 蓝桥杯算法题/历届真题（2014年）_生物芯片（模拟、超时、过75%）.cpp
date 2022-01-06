#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <map>
#include <iterator>

using namespace std;

map<long long, bool> light;

long long solve(long long n, long long l, long long r)
{
 for (long long i = l; i <= r; i++)
  light[i] = false;
 
 for (long long i = 2; i <= n; i++)
 {
  for (map<long long, bool>::iterator it = light.begin(); it != light.end(); it++)
  {
   if (it->first % i == 0)
    it->second = !(it->second);
  }
 }
 
 long long count = 0;
 for (map<long long, bool>::iterator it = light.begin(); it != light.end(); it++)
 {
  if (it->second)
   count += 1;
 }
 
 return count;
}

int main(void)
{
 int n,l,r;
 cin >> n >> l >> r;
 cout << solve(n, l, r);
	return 0;
} 

