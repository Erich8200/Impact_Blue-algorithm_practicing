// CmdDraft.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>

int main(void)
{
	int a[102][102] = {0};
	int row_step = 1, first_column_step = 2,n = 0,i,j,k;

	scanf_s("%d", &n);

	for (k = 2,a[1][1] = 1; k <= n; k++)
	{
		a[1][k] = a[1][k - 1] + first_column_step;
		first_column_step++;
	}

	for (i = 2; i <= n; i++)
	{
		a[i][1] = a[i - 1][1] + row_step;
		int column_step = i + 1;
		for (j = 2; j <= n - i + 1; j++)
		{
			a[i][j] = a[i][j - 1] + column_step;
			column_step++;
		}
		row_step++;
	}

	for (i = 1, j = 1; i <= n && j <= n;j++)
	{
		if (a[i][j + 1] == 0)
		{
			printf("%d\n", a[i][j]);
			i += 1;
			j = 0;
		}
		else
			printf("%d ",a[i][j]);
	}

	system("pause");

    return 0;
}

