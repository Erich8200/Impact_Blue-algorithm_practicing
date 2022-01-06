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
		dp[i] = 1;//��Ҫ���ǣ�����������ÿһ��Ԫ�ص�LIS����Ϊ1
		for (int j = 1; j < i; j++)
		{
			if (A[j] <= A[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		ans = max(ans, dp[i]);//�Ա����dpһ�߲������ֵ���Ͳ�������ٱ���һ����
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