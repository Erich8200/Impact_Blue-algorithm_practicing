#include<stdio.h>
#include<math.h>
#include<windows.h>

int main(void)
{
	int time = 0;
	scanf("%d",&time);
	printf("%d:%d:%d",time/3600,time%3600/60,time%3600%60);
	system("pause");
	return 0;
}