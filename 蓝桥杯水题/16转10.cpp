#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

char hex_dec_list[18] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

int main(void)
{
	int num_dec = 0;                            //十进制数
	char dec_hex_list[17] = { '0',' 1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	scanf_s("%d", &num_dec);                    
	char num_hex[9] = { 0 };                    //十六进制数组
	int ph = 7;
	
	if (!num_dec)                               //后面的循环排除了前导0，单独是0的情况补上
	{
		printf("0");
		return 0;
	}

	for (; num_dec > 0; num_dec /= 16, ph--)     //num_hex数组从后往前放，如果控制条件是>=0，会有前导0
	{
		num_hex[ph] = dec_hex_list[num_dec % 16];
	}
	printf("%s", num_hex + ph + 1);              //因为是--，出来之前会多减一次，要加上

    return 0;
}