#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define N 2

using namespace std;

int a[N] = {1, 2};

void DFS(int curSum, const int sum, const int n, int& count)
{
 if (curSum == sum)
 {
  count += 1;
  return;
 }
 else if (curSum > sum)
 {
  return; 
 }
 else
 {
  for (int i = 0; i < n; i++)
   DFS(curSum + a[i], sum, n, count);
  return;
 }
}

int main(void)
{
 int n = 0, count = 0;
 cin >> n;
 DFS(0, n, N, count);
 cout << count << endl;
	return 0;
}
