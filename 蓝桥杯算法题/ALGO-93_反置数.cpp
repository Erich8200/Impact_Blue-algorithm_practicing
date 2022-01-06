#include <iostream>
#include <stdio.h>

using namespace std;

int revNum(int num)
{
	int ans = 0;
	while (num)
	{
		ans *= 10;
		ans += num % 10;
		num /= 10;
	}
	return ans;
}

int main(void)
{
	//freopen("0.txt", "r", stdin);

	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;
	cout << revNum(revNum(num1) + revNum(num2)) << endl;

	//fclose(stdin);
	return 0;
}
