#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t = 0, T = 0;
	cin >> T ;
	while (T--)
	{
		scanf("%d", &t);
		printf("%02d:%02d:%02d\n", t / 3600, t % 3600 / 60, t % 3600 % 60);
	}	
	system("pause");
	return 0;
}