#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int year)
{
	int ans = 0, d = 13;
	// Mar ~ Dec
	for (int m = 3; m <= 12; m++)
	{
		int w = (d + 2*m + 3*(m + 1)/5 + year + year/4 - year/100 + year/400 + 1) % 7;
		if (w == 5)
			ans += 1;
	}
	
	year -= 1;
	// Jan
	if (((d + 2*13 + 3*(13 + 1)/5 + year + year/4 - year/100 + year/400 + 1) % 7) == 5)
		ans += 1;

	// Feb
	if (((d + 2*14 + 3*(14 + 1)/5 + year + year/4 - year/100 + year/400 + 1) % 7) == 5)
		ans += 1;
	
	return ans;
}

int main()
{
	int year = 0;
	cin >> year;
	cout << solve(year) << endl;
	return 0;
}

