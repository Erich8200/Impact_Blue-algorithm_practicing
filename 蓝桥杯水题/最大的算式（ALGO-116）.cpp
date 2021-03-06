#include <stdio.h>
#include <stdlib.h>
#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b

long long dp[16][16] = { 0 };   //dp[i][j]表示前i个数中有j个乘号时，所得最大值
int sum[16] = { 0 };    //sum[i]表示前i个数之和

int main()
{
	int N, K, i = 1, j, k, t;
	scanf("%d %d", &N, &K);
	int num[16];
	for (; i <= N; i++)
	{
		scanf("%d", &num[i]);
		sum[i] = sum[i - 1] + num[i];
	}
	//如果没有乘号的情况/连加情况
	for (i = 1; i <= N; i++)
	{
		dp[i][0] = sum[i];
	}
	//dp
	for (i = 2; i <= N; i++)
	{
		t = min(i - 1, K);
		for (j = 1; j <= t; j++)
		{
			for (k = 2; k <= i; k++)    //k为这个乘号的位置
			{
				dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] * (sum[i] - sum[k - 1])); //求前i个数有j个乘号的情况中最大的情况
			}
		}
	}
	printf("%lld\n", dp[N][K]);
	return 0;
}