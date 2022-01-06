#include<iostream>
#include<algorithm>
#include<algorithm>
using namespace std;
const int INF = 0x3FFFFFFF;
int maxn = 50;
int yami[50];
int cnt[50];
int sum[50][20010];//�����ǵ���ı�ţ������ʾ��ǰ��ζ��
int m, n;
int main(void)
{
	cin >> m >> n;
	for (int i = 0; i<n; i++) 
		cin >> yami[i] >> cnt[i];
	int sumn = 0;//��������
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
				//kΪ���Ի�õ���ζ�Ⱥͣ�k >= yami[i]��ʾ�ﵽ����ζ�Ⱥʹ��ڵ�ǰ�������ζ��
				//sum[cur - 1][k - yami[i]] != INF��ʾ��ǰ��ζ�ȿ�����֮ǰ��״̬�ﵽ���ؼ���
				//sum[cur][k]>sum[cur - 1][k - yami[i]] + 1Ϊѡ�����ŵ�״̬ת������
				if (k >= yami[i] && sum[cur - 1][k - yami[i]] != INF && sum[cur][k]>sum[cur - 1][k - yami[i]] + 1)
				{
					sum[cur][k] = sum[cur - 1][k - yami[i]] + 1;
				}
			}
			//ѡ���ѡ��ǰ������Ը���
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
