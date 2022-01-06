#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <regex>
#include <vector>
#define N 1000

using namespace std;

int A[N + 2];
int dp[N + 2];

//dp[i] = max{dp[j] + 1, 1}
int getLIS(int n)
{
	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;//不要忘记，假设数组中每一个元素的LIS长度为1
		for (int j = 1; j < i; j++)
		{
			if (A[j] <= A[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		ans = max(ans, dp[i]);//以便求解dp一边查找最大值，就不用最后再遍历一次了
	}
	return ans;
}

int main(int argc, char** argv)
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	cout << getLIS(n) << endl;
	system("pause");
	return 0;
}