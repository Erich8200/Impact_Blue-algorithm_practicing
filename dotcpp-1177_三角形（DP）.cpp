#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <regex>
#include <vector>
#define N 100

using namespace std;

int dp[N + 2][N + 2];
int T[N + 2][N + 2];

void triangle(int n)
{
	//dp±ß½ç
	for (int i = 1; i <= n; i++)
		dp[n][i] = T[n][i];
	//Öð²ãÏòÉÏdp
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i + 1][j + 1], dp[i + 1][j]) + T[i][j];
}

int main(int argc, char** argv)
{
	freopen("input0.txt", "r", stdin);
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cin >> T[i][j];
			}
		}

		triangle(n);

		cout << dp[1][1] << endl;
	}
	system("pause");
	fclose(stdin);
	return 0;
}