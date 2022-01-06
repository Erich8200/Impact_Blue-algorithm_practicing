#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define N 10000

using namespace std;

double a[N],b[N],c[N],d[N],e[N],f[N],t[N];

int main(void)
{
 int n = 0;
 cin >> n;
 for (int i = 0; i < n; i++)
  cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> f[i] >> t[i];
 double x1, y1, z1, x2, y2, z2;
 cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
 for (int i = 0; i < n; i++)
 {
  x1 = x1 + a[i]*t[i];
  y1 = y1 + b[i]*t[i];
  z1 = z1 + c[i]*t[i];
  x2 = x2 + d[i]*t[i];
  y2 = y2 + e[i]*t[i];
  z2 = z2 + f[i]*t[i];
 }
 
 printf("%.4lf",sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2)));
	return 0;
} 

