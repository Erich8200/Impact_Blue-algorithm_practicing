#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int units = 0, tens = 0, hundreds = 0;
	int number;
	for (number = 100; number <= 999; number++)
	{
		units = number % 10;
		tens = number % 100 / 10;
		hundreds = number / 100;
		if (units*units*units + tens * tens*tens + hundreds * hundreds*hundreds == number)
			printf("%d\n", number);
	}
    return 0;
}