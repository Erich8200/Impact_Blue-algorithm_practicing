#include <iostream>
#include <stdio.h>

using namespace std;

int getDivSum(int num)
{
	int ans = 0;
	for (int i = 1; i*i <= num; i++)
		if (num%i == 0)
			ans = ans + i + num/i;
	return ans - num;
}

int main(void)
{
	freopen("0.txt", "r", stdin);

	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;
	
	if (getDivSum(num1) == num2 && getDivSum(num2) == num1)
		cout << "yes\n";
	else
		cout << "no\n";
	fclose(stdin);
	return 0;
}
