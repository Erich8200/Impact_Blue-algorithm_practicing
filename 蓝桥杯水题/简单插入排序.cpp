// CmdDraft.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>

int main(void)
{
	int numArray[201] = {0},numAmount = 0,b,a,i;
	scanf_s("%d",&numAmount);
	for (i = 1; i <= numAmount; i++)
		scanf_s("%d", numArray + i);
	for (a = 2; a <= numAmount; a++)
	{
		if (numArray[a] < numArray[a - 1])
		{
			numArray[0] = numArray[a];
			numArray[a] = numArray[a - 1];
			for (b = a - 2; numArray[b] > numArray[0]; b--)
				numArray[b + 1] = numArray[b];
			numArray[b + 1] = numArray[0];
		}
	}

	for(i = 1;i <= numAmount;i++)
		printf("%d ",numArray[i]);

	system("pause");

    return 0;
}

