#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int a[36][36] = { 0 };
	int i, j,n = 0;
	scanf_s("%d", &n);
	printf("1\n");
	for (i = 2, a[1][1] = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			if (a[i][j] == 0)
			{
				printf("\n");
				break;
			}
			else
				printf("%d ", a[i][j]);
		}
	}
	getchar();
	getchar();
    return 0;
}