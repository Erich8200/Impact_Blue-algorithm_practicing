// CmdDraft.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int calc_times = 0;
	char num_bin[400000] = { 0 };
	char num_oct_rev[300000] = { 0 };
	char num_hex[2][100000] = { 0 };

	scanf_s("%d", &calc_times);
	getchar();
	
	int i,j;
	for (i = 0,j = 0; i < calc_times; i++)
	{
		j = 0;
		while ((num_hex[i][j] = getchar()) != '\n')
			j++;
		num_hex[i][j] = '\0';
	}
		

	for (i = 0; i < calc_times; i++)
	{
		int num_hex_length = strlen(num_hex[i]);
		int pb = 0;

		for (int ph = 0; ph <= num_hex_length - 1; ph++)
		{
			switch (num_hex[i][ph])
			{
			case '0':
			{
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				break;
			}
			case '1':
			{
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				break;
			}
			case '2':
			{
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				break;
			}
			case '3':
			{
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				break;
			}
			case '4':
			{
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				break;
			}
			case '5':
			{
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				break;
			}
			case '6':
			{
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				break;
			}
			case '7':
			{
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				break;
			}
			case '8':
			{
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				break;
			}
			case '9':
			{
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				break;
			}
			case 'A':
			{
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				break;
			}
			case 'B':
			{
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				break;
			}
			case 'C':
			{
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				num_bin[pb++] = '0';
				break;
			}
			case 'D':
			{
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				num_bin[pb++] = '1';
				break;
			}
			case 'E':
			{
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				num_bin[pb++] = '0';
				break;
			}
			case 'F':
			{
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				num_bin[pb++] = '1';
				break;
			}
			}
		}

		int num_bin_length = strlen(num_bin);
		int po = 0;

		for (pb = num_bin_length - 1; pb >= 0; pb -= 3, po++)
		{
			num_oct_rev[po] = num_oct_rev[po] + 1 * (num_bin[pb] - '0') + 2 * (num_bin[pb - 1] - '0') + 4 * (num_bin[pb - 2] - '0') + '0';
		}

		int num_oct_length = strlen(num_oct_rev);

		for (po = num_oct_length - 1; po >= 0; po--)
		{
			if (num_oct_rev[po] >= '0' && num_oct_rev[po] <= '7')
				if(!(po == num_oct_length - 1 && num_oct_rev[po] == '0'))
					printf("%c", num_oct_rev[po]);
		}
		printf("\n");
		
		
		for(j = 0;j < 300000;j++)
			num_oct_rev[j] = 0;
		for(j = 0; j < 400000; j++)
			num_bin[j] = 0;
	}
	getchar();
    return 0;
}