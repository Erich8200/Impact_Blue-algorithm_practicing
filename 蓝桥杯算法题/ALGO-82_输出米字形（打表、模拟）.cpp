#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#define N 50

using namespace std;

char G[2*N-1][2*N-1];

void initG (int n)
{
 for (int i = 0; i < 2*n - 1; i++)
  for (int j = 0; j < 2*n - 1; j++)
   G[i][j] = '.';
}

void printGraph (int n)
{
 initG(n);
 for (int i = 0; i <= n - 1; i++)
 {
  G[n-1][i] = G[n-1][2*n-2-i] = 'A' + i;
  G[i][n-1] = G[2*n-2-i][n-1] = 'A' + i;
  G[i][i] = G[2*n-2-i][2*n-2-i] = G[i][2*n-2-i] = G[2*n-2-i][i] = 'A' + i;
 }
 
 for (int i = 0; i < 2*n - 1; i++)
 {
  for (int j = 0; j < 2*n - 1; j++)
   cout << G[i][j];
  cout << endl;
 }

}

int main(void)
{
 int n = 0;
 cin >> n;
 printGraph(n);
	return 0;
}
