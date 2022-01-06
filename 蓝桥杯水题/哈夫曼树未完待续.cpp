#include<stdio.h>
#include<math.h>
#include<windows.h>

int CountLeaves(int leaves[],int *pcost_index)
{
	int count = 0,index_bak = 0,i;
	for(i = 0;i < 100;i++)
	{
		if(leaves[i] != 0)
		{
			count += 1;
			index_bak = i;
		}
	}
	if(count == 1)
		*pcost_index = index_bak;
	return count;
}

void HuffmanAlgo(int leaves[])
{
	int min1 = 0,min2 = 0,i,index_bak_1 = 0,index_bak_2 = 0;
	
	//Ñ°ÕÒmin1
	for(min1 = leaves[0],i = 0;i < 100;i++)
	{
		if(leaves[i] < min1 && leaves[i] != 0)
		{
			min1 = leaves[i];
			index_bak_1 = i;
		}
	}

	//Ñ°ÕÒmin2
	for(i = 0,min2 = leaves[0];i < 100;i++)
	{
		if(i != index_bak_1 && leaves[i] != 0 && leaves[i] < min2)//
		{
			min2 = leaves[i];
			index_bak_2 = i;
		}
	}
	leaves[index_bak_1] = min1 + min2;
	leaves[index_bak_2] = INT_MAX;
}

int main(void)
{
	int min1 = 0,min2 = 0,i,total_cost = 0,cost_index = 0,n = 0;
	int leaves[100] = {0};
	int* pcost_index = &cost_index;
	scanf("%d",&n);
	
	for(i = 0;i < n;i++)
		scanf("%d%*c",leaves + i);
	
	while(CountLeaves(leaves,pcost_index))
	{
		HuffmanAlgo(leaves);
	}
	
	total_cost = leaves[*pcost_index];
	printf("%d",total_cost);

	system("pause");
	return 0;
}