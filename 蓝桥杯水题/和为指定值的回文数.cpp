#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

//char hex_dec_list[18] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

int main(void)
{
	int result_num[10000] = { 0 };
	int i,n;
	int current_num;

	scanf_s("%d", &n);

	//五位数第一次筛选
	for (i = 0,current_num = 10000; current_num <= 99999; current_num++)
	{
		if ((current_num / 10000 == current_num % 10) && (current_num / 1000 % 10 == current_num % 100 / 10))
		{
			result_num[i] = current_num;
			i++;
		}
			
	}

	//五位数第二次筛选
	for (i = 0; result_num[i] != 0; i++)
	{
		if (n == result_num[i] / 10000 + result_num[i] % 10 + result_num[i] / 1000 % 10 + result_num[i] % 100 / 10 + result_num[i] / 100 % 10)
		{
			printf("%d\n", result_num[i]);
			result_num[i] = 0;
		}
	}

	//六位数第一次筛选
	for (i = 0,current_num = 100000; current_num <= 999999; current_num++)
	{
		if ((current_num / 100000 == current_num % 10) && (current_num / 10000 % 10 == current_num % 100 / 10) && (current_num / 1000 % 10 == current_num % 1000 / 100))
		{
			result_num[i] = current_num;
			i++;
		}		
	}

	//六位数第二次筛选
	for (i = 0; result_num[i] != 0; i++)
	{
		if (n == result_num[i] / 100000 + result_num[i] % 10 + result_num[i] / 10000 % 10 + result_num[i] % 100 / 10 + result_num[i] / 1000 % 10 + result_num[i] % 1000 / 100)
		{
			printf("%d\n", result_num[i]);
			result_num[i] = 0;
		}
	}


    return 0;
}