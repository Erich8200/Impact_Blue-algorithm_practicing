#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

char hex_dec_list[18] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

int HexCharToDec(char c)
{
	for(int i = 0;i <16;i++)
	{
		if (hex_dec_list[i] == c)
			return i;
	}
}

int main(void)
{
	int i = 0; 
	int num_dec = 0;
	char num_hex[9] = { 0 };
	//while ((num_hex[i] = getchar()) != '\n')
	//	i++;
	//num_hex[i] = '\0';
	gets_s(num_hex);

	int num_hex_len = strlen(num_hex);
	for (i = 0; i < num_hex_len; i++)
		num_dec += HexCharToDec(num_hex[i])*pow(16, num_hex_len - i - 1);
	printf("%d", num_dec);

	getchar();
    return 0;
}