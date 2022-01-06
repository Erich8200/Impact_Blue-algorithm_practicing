#include<stdio.h>
#include<math.h>
#include<windows.h>

int main(void)
{
	char a,b,c,d,e;
	int f;
	char str[6] = {0};

	for(a = '0';a <= '1';a++)
	{
		for(b = '0';b <= '1';b++)
		{
			for(c = '0';c <= '1';c++)
			{
				for(d = '0';d <= '1';d++)
				{
					for(e = '0';e <= '1';e++)
					{
						str[0] = a;
						str[1] = b;
						str[2] = c;
						str[3] = d;
						str[4] = e;
						printf("%s\n",str);
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}