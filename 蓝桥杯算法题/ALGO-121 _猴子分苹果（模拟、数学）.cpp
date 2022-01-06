#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(void)
{
	int m,n;
	cin >> n >> m;
	for(int i=0;;i++)
	{
		bool flag = true;
		long long x = i;
		for(int j=1;j<=n;j++)
		{
			x = x * n + m;
			if(x%(n-1)!=0)
			{
				flag = false;
				break;
			}
			x = x/(n-1);
		}
		if(flag == false) continue;
		if(flag == true)
		{
			x = x * n+ m;
			printf("%lld",x);
			return 0;
		}
	}
	return 0;
} 

