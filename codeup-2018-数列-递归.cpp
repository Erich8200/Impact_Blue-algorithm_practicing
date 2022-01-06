#include <iostream>
#include <string>
#include <queue>
#include <math.h>
#include <algorithm>
#define N 20

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[N];

int F(int n)
{
	if(n == 0) return 0;
	else if(n == 1 || n == 2) return 1;
	else return (F(n-1) + F(n-2));
}

void genSeries(int n)
{
	for(int i = 0;i < n;i++)
		a[i] = F(i);
	return;
}

void draw(int n)
{
	genSeries(2*n-1);
	int i;
	for(i = 0;i < n;i++)
	{
		int j;
		for(j = i;j < n;j++) cout << "  ";
		for(j = 0;j <= 2*i;j++) cout << a[j] << " ";
		cout << endl;
	}
}

int main(int argc, char** argv) 
{
	int m,n,time;
	cin >> m;
	for(time = 1;time <= m;time++)
	{
		cin >> n;
		draw(n);
	}
	return 0;
}
