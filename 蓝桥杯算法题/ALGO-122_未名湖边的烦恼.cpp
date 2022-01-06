#include <iostream>
#include <stdio.h>

using namespace std;

int shoeCount;

void solve (int pushCount, int popCount, int& ans)
{
	if (shoeCount < 0) return;
	else if (pushCount == 0 && popCount == 0)
		ans += 1;
	else
	{
		if (pushCount > 0)
		{
			shoeCount += 1;
			solve(pushCount-1, popCount, ans);
			shoeCount -= 1;
		}
		if (popCount > 0)
		{
			shoeCount -= 1;
			solve(pushCount, popCount - 1, ans);
			shoeCount += 1;
		}
	}
	return;
}

int main(void)
{
	freopen("input9.txt", "r", stdin);

	int m = 0, n = 0, ans = 0;
	cin >> m >> n;
	solve(m, n, ans);
	cout << ans << endl;

	fclose(stdin);
	return 0;
}
