#include <iostream>
#include <stdio.h>

using namespace std;

void DFS(int t, const int T, int p, const int P, int tgtP, int& ans)
{
	if (t == T)
	{
		if (p == tgtP)
			ans += 1;
		return;
	}
	else
	{
		DFS(t + 1, T, (p + 1)%P, P, tgtP, ans);
		DFS(t + 1, T, (p - 1 + P)%P, P, tgtP, ans);
	}
}

int main()
{
    int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	DFS(0, m, 0, n, 0, ans);
	printf("%d\n", ans);
	return 0;
}

