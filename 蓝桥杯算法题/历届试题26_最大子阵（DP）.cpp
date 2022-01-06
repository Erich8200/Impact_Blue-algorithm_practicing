#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define N 500

using namespace std;

int dp[N + 2][N + 2];
int A[N + 2][N + 2];

int solve(int n, int m)
{
	int ans = A[1][1];
	//��ʼ��dp����
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = dp[i][j - 1] + A[i][j];

	//�����������
	for (int first = 1; first <= m; first++)
	{
		for (int last = first; last <= m; last++)
		{
			int subMatrixSum = 0;
			for (int i = 1; i <= n; i++)
			{
				subMatrixSum += dp[i][last] - dp[i][first - 1];
				ans = ans > subMatrixSum ? ans : subMatrixSum;
				subMatrixSum = subMatrixSum > 0 ? subMatrixSum : 0;//��Ҫ���ܾ������󡣷����п��ܻ�������������ֵ�����´�����
			}
		}
	}

	return ans;
}

int main()
{
	freopen("input0.txt", "r", stdin);
	int m, n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> A[i][j];
	cout << solve(n, m) << endl;
	fclose(stdin);
	system("pause");
	return 0;
}