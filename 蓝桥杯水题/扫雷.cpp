#include <stdio.h>
#include <cstdlib>

int main(void)
{
	int field[102][102] = {0};
	int row = 1,column = 1,mineCount = 0,fieldNo = 0;
		
	while(1)
	{
		scanf("%d%d",&row,&column);
		
		getchar();
	
		if(row == 0 || column == 0)
			return 0;

		for(int i = 1;i <= row;i++)
		{
			for(int j = 1;j <= column;j++)
			{
				field[i][j] = getchar();
			}
			getchar();
		}

		fieldNo += 1;

		for(int a = 1;a <= row;a++)
		{
			for(int b = 1;b <= column;b++)
			{
				mineCount = 0;
				if( field[a][b] == '.')
					{
						if(field[a][b + 1] == '*') mineCount += 1;
						if(field[a][b - 1] == '*') mineCount += 1;
						if(field[a + 1][b + 1] == '*') mineCount += 1;
						if(field[a + 1][b] == '*') mineCount += 1;
						if(field[a + 1][b - 1] == '*') mineCount += 1;
						if(field[a - 1][b + 1] == '*') mineCount += 1;
						if(field[a - 1][b] == '*') mineCount += 1;
						if(field[a - 1][b - 1] == '*') mineCount += 1;
						field[a][b] = mineCount;
					}
			}
		}

		printf("Field #%d:\n",fieldNo);

		for(int c = 1;c <= row;c++)
		{
			for(int d = 1;d <= column;d++)
			{
				if(field[c][d] == '*')
					printf("%c",field[c][d]);
				else
					printf("%d",field[c][d]);
			}
			putchar('\n');
		}

		putchar('\n');
	}

	system("pause");
	return 0;
}