#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

/*参数：
curNum：当前选择第n个数
curSum：当前和
a：选择下界
b：选择上界
x：要求的和
n：选择n个数
count：符合要求的解的数量
*/

void DFS(int curNum, int curSum, const int a, const int b, const int x, const int n, int& count)
{
	if (curNum == n)
	{
		if (curSum == x)
			count += 1;
		return;
	}
	else if (curSum > x)
		return;
	else
	{
		for (int i = a; i <= b; i++)
			DFS(curNum + 1, curSum + i, a, b, x, n, count);
	}
}

int main(void)
{
	freopen("input9.txt", "r", stdin);
	int n = 0, a = 0, b = 0, x = 0;
	cin >> n >> a >> b >> x;
	int count = 0;
	DFS(0, 0, a, b, x, n, count);
	double ans = 0;
	ans = count*1.0/pow((b - a + 1), n);
	printf("%.4lf", ans);
	fclose(stdin);
	return 0;
}
