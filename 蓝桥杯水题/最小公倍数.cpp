#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

bool isPrime(int num)
{
	int factor;
	for (factor = 2; factor <= num/2; factor++)
	{
		if (num % factor == 0)
			return false;
	}
	return true;
}

//生成n以内的素数表
void genPrimeList(int* primeList, int n)
{
	int num,i;
	for (num = 2,i = 0; num <= n; num++)
	{
		if (isPrime(num))
		{
			primeList[i++] = num;
			//printf("%d\n", primeList[i - 1]);
		}
	}
}

int lcm(int a, int b, int* primeList, int* factorList)
{
	//int *p = primeList;
	int factorIndex = 0, result = 1, factor1 = a, factor2 = b, primeIndex;
	bool coprime = false;
	//不互素
	while (!coprime)
	{
		coprime = true;
		for (primeIndex = 0; primeList[primeIndex] <= factor1 && primeList[primeIndex] <= factor2; primeIndex++)
		{
			if (factor1 % primeList[primeIndex] == 0 && factor2 % primeList[primeIndex] == 0)
			{
				factor1 /= primeList[primeIndex];
				factor2 /= primeList[primeIndex];
				factorList[factorIndex] = primeList[primeIndex];
				factorIndex += 1;
				coprime = false;
				break;
			}
			else
				continue;
		}
	}

	for (factorList[factorIndex++] = factor1,factorList[factorIndex] = factor2; factorIndex >= 0; factorIndex--)
		result *= factorList[factorIndex];
	return result;
}

int main(void)
{
	int a, b;
	scanf_s("%d%d", &a, &b);
	int* primeList = (int*)calloc(65535, sizeof(int));
	int* factorList = (int*)calloc(65535, sizeof(int));
	genPrimeList(primeList, a > b ? a : b);
	printf("%d\n",lcm(a, b, primeList, factorList));
	free(factorList);
	free(primeList);
    return 0;
}