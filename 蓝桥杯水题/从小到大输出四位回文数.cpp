#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int current_num;
	for (current_num = 1000; current_num <= 9999; current_num++)
	{
		if (current_num / 1000 == current_num % 10 && current_num / 100 % 10 == current_num % 100 / 10)
		{
			printf("%d\n", current_num);
		}
	}
    return 0;
}