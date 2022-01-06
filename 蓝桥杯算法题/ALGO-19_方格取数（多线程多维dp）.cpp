#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>
#define N 10

using namespace std;

//����˼·���Ǽ���������ͬʱ��
//����dp����ǰ����ά����һ���ռ䣬����������һ�����ֱ��¼��������
//�����ռ��зֱ����һ�����ߣ�Ҫ�������ߵĲ��ظ�����
int dp[N + 2][N + 2][N + 2][N + 2];
int A[N + 2][N + 2];

int main()
{
	freopen("input0.txt", "r", stdin);
	int n;
	cin >> n;
	int x, y, num;
	while (cin >> x >> y >> num && x && y && num)
		A[x][y] = num;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				for (int l = 1; l <= n; l++)
				{
					//����ת�Ʒ�ʽʵ����������Ͼ���
					int m1 = max(dp[i - 1][j][k - 1][l], dp[i][j - 1][k][l - 1]);//��һ���¡��ڶ����£���һ���ҡ��ڶ�����
					int m2 = max(dp[i][j - 1][k - 1][l], dp[i - 1][j][k][l - 1]);//��һ���ҡ��ڶ����£���һ���¡��ڶ�����
					//��һ�����ߵģ�һ������
					dp[i][j][k][l] = max(m1, m2) + A[i][j];
					//�ж��Ƿ��ظ������ظ������
					if (i != k || j != l)
						dp[i][j][k][l] += A[k][l];
				}
			}
		}
	}
	cout << dp[n][n][n][n] << endl;
	fclose(stdin);
	return 0;
}