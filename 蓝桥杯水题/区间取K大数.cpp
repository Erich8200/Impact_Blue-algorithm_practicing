#include <stdio.h>
#include <malloc.h>

void sort(int* a,int length)
{
	int i,j;
	for(i = 2;i <= length;i++)
	{
		j = i - 1;
		if(a[j] < a[j + 1])
		{
			for(a[0] = a[j + 1];a[0] > a[j];j--)
				a[j + 1] = a[j];
			a[j + 1] = a[j];
		}
	}
}

int main(void)
{
	int n = 0;
	scanf("%d",&n);
	getchar();
	int* a = (int*)malloc(n*sizeof(int));
	int i;
	for(i = 0;i < n;i++)
		scanf("%d",a + i);
	getchar();
	int m = 0;
	scanf("%d",&m);
	int* sortArray = NULL;
	
	for(i = 0;i < m;i++)
	{
		int l,r,k,p,q;
		scanf("%d%d%d",&l,&r,&k);
		getchar();
		sortArray = (int*) malloc((r - l + 2)*sizeof(int));
		for(p = 1,q = l - 1;q < r - 1;p++,q++)
			sortArray[p] = a[q];
		sort(sortArray,r - l + 1);
		printf("%d\n",sortArray[k-1]);
		free(sortArray);
		sortArray = NULL;
	}
	return 0;
}