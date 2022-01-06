#include <stdio.h>
#include <malloc.h>

int C(int n,int k)
{
	if(k == 0 || k == n)
		return 1;
	return C(n-1,k) + C(n-1,k-1);
}

int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",C(b,a));
	return 0;
}