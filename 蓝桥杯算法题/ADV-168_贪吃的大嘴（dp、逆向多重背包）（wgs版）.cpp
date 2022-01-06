#include<iostream>
#include<algorithm>
#include<algorithm>
using namespace std;
const int INF = 0x3FFFFFFF;
int maxn = 50;
int yami[50];
int cnt[50];
int sum[50][20010];//纵轴是蛋糕的编号，横轴表示当前美味度
int m, n;
int main(void)
{
	cin >> m >> n;
	for (int i = 0; i<n; i++) 
		cin >> yami[i] >> cnt[i];
	int sumn = 0;//蛋糕总数
	for (int i = 0; i<n; i++) 
		sumn += cnt[i];

	for (int i = 0; i <= sumn; i++)
	{
		for (int j = 0; j <= m; j++) 
			sum[i][j] = INF;
	}
	sum[0][0] = 0;

	int cur = 1;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<cnt[i]; j++)
		{
			for (int k = 0; k <= m; k++)
			{
				//k为可以获得的美味度和，k >= yami[i]表示达到的美味度和大于当前蛋糕的美味度
				//sum[cur - 1][k - yami[i]] != INF表示当前美味度可以由之前的状态达到，关键！
				//sum[cur][k]>sum[cur - 1][k - yami[i]] + 1为选择最优的状态转移条件
				if (k >= yami[i] && sum[cur - 1][k - yami[i]] != INF && sum[cur][k]>sum[cur - 1][k - yami[i]] + 1)
				{
					sum[cur][k] = sum[cur - 1][k - yami[i]] + 1;
				}
			}
			//选择或不选择当前蛋糕可以更优
			for (int k = 0; k <= m; k++)
			{
				sum[cur][k] = min(sum[cur - 1][k], sum[cur][k]);
			}
			cur++;
		}
	}
	if (sum[cur - 1][m] != INF) cout << sum[cur - 1][m];
	else cout << "><";
	return 0;
}
