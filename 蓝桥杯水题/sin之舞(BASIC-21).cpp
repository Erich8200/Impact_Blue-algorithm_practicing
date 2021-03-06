#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void GenAn(char* An, int n)
{
	int i;
	char* temp = (char*)calloc(1100, sizeof(char));
	for (i = 0; i < n; i++)
	{
		sprintf(temp, "sin(%d", i + 1);
		strcat(An, temp);
		memset(temp, 0, 1100);
		if (i % 2 == 0)
			strcat(An, "-");
		else
			strcat(An, "+");
	}
	if (*(An + strlen(An) - 1) == '+' || *(An + strlen(An) - 1) == '-')
		*(An + strlen(An) - 1) = '\0';
	for (i = 0; i < n; i++)
	{
		strcat(An, ")");
	}
	free(temp);
}

void PrintSn(char* An,int n)
{
	int i;

	for (i = 1; i <= n - 1; i++)
		printf("(");
	for (i = 1; i <= n; i++)
	{
		GenAn(An, i);
		if (i == 1)
			printf("%s", An);
		else
			printf("+%d)%s", n - i + 2, An);
		memset(An, 0, 1100);
	}
	printf("+1");
}

int main(void)
{
	char* An = (char*)calloc(1100, sizeof(char));
	int n;
	scanf("%d", &n);
	PrintSn(An, n);
	free(An);
	return 0;
}