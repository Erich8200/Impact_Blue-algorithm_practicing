#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <stdio.h>

#define MAX_N 51
#define MAX_M 51

using namespace std;

int Map[MAX_N][MAX_M];
//int cache[MAX_N][MAX_M][MAX_N][MAX_M];
int n, m;
int rowDir[] = { 1,0 };
int colDir[] = { 0,1 };
int dp[MAX_N][MAX_M][MAX_N][MAX_M];

// 70%
//int solve_dfs(int row1, int col1, int row2, int col2)
//{
//	if (cache[row1][col1][row2][col2])
//		return cache[row1][col1][row2][col2];
//
//	if (row1 == m && col1 == n && row2 == m && col2 == n)
//		return 0;
//	else
//	{
//		int newRow1, newRow2, newCol1, newCol2;
//		int ans = 0;
//		for (int i = 0; i < 2; i++)
//		{
//			newRow1 = row1 + rowDir[i];
//			newCol1 = col1 + colDir[i];
//			for (int j = 0; j < 2; j++)
//			{
//				newRow2 = row2 + rowDir[j];
//				newCol2 = col2 + colDir[j];
//				if (newRow1 >= 1 && newRow1 <= m && newCol1 >= 1 && newCol1 <= n && newRow2 >= 1  && newRow2 <= m && newCol2 >= 1 && newCol2 <= n
//					&& newRow1 != newRow2 && newCol1 != newCol2)
//				{
//					ans = max(solve_dfs(newRow1, newCol1, newRow2, newCol2) + Map[newRow1][newCol1] + Map[newRow2][newCol2], ans);
//				}
//			}
//		}
//
//		cache[row1][col1][row2][col2] = ans;
//		return ans;
//	}
//}

int solve_dp()
{
	for (int i = m; i >= 1; i--)
	{
		for (int j = n; j >= 1; j--)
		{
			for (int k = m; k >= 1; k--)
			{
				for (int l = n; l >= 1; l--)
				{
					int newRow1, newRow2, newCol1, newCol2;
					int ans = 0;
					for (int a = 0; a < 2; a++)
					{
						newRow1 = i + rowDir[a];
						newCol1 = j + colDir[a];
						for (int b = 0; b < 2; b++)
						{
							newRow2 = k + rowDir[b];
							newCol2 = l + colDir[b];
							if (newRow1 >= 1 && newRow1 <= m && newCol1 >= 1 && newCol1 <= n && newRow2 >= 1 && newRow2 <= m && newCol2 >= 1 && newCol2 <= n
								&& newRow1 != newRow2 && newCol1 != newCol2)
							{
								ans = max(dp[newRow1][newCol1][newRow2][newCol2] + Map[newRow1][newCol1] + Map[newRow2][newCol2], ans);
							}
						}
					}

					dp[i][j][k][l] = ans;

				}
			}

		}
	}

	return dp[1][1][1][1];

}

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> Map[i][j];
	//cout << solve_dfs(1, 1, 1, 1) << endl;
	cout << solve_dp() << endl;
	return 0;
}