#include <stdio.h>
#include <cstdlib>

int main(void)
{
	char str[102] = {'\0'};
	int i = 1,j,k;
	j = k = 1;

	while((str[i] = getchar()) != '\n')
		i += 1;
	str[i] = '\0';
	int length = i - 1;
	
	while(j <= length/2)
	{
		str[0] = str[j];
		str[j] = str[length - j + 1];
		str[length - j + 1] = str[0];
		j += 1;
	}
	
	while (k <= length)
	{
		printf("%c",str[k]);
		k += 1;
	}

	system("pause");
	return 0;
}