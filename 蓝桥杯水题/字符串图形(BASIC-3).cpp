#include<stdio.h>
#include<math.h>
#include<windows.h>

int main(void)
{
	int times = 0,length = 0;
	int i,j,k,char_pointer;
	char str[27][27] = {0};
	char char_list[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	scanf("%d%d",&times,&length);
	for(j = 1;j <= times;j++)
	{
		str[j-1][j-1] = 'A';
		for(char_pointer = 1,k = j;k <length;k++,char_pointer++)
		{
			str[j-1][k] = char_list[char_pointer];
		}
		for(char_pointer = 1,k = j - 2;k >= 0;k--,char_pointer++)
		{
			str[j-1][k] = char_list[char_pointer];
		}
	}

	for(i = 0;i < times;i++)
	{
		for(j = 0;j < length;j++)
		{
			printf("%c",str[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}