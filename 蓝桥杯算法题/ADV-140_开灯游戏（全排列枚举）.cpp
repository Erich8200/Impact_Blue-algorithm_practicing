#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool light[9];

vector<string> ans;

int a[][9] = {
	{0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,1,1,1},
	{0,0,0,0,0,1,1,1,1},
	{0,0,0,0,1,1,1,1,1},
	{0,0,0,1,1,1,1,1,1},
	{0,0,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1},
};

bool check()
{
	int count = 0;
	for (int j = 0; j < 9; j++)
		if (light[j])
			count += 1;
	if (count == 4)
		return true;
	else
		return false;
}

void solve()
{
	for (int i = 0; i < 9; i++)
	{
		do
		{
			for (int j = 0; j < 9; j++)
			{
				if (a[i][j] == 1)
				{
					if (j == 0)
					{
						light[1] = !light[1];
						light[3] = !light[3];
					}
					if (j == 1)
					{
						light[0] = !light[0];
						light[2] = !light[2];
						light[4] = !light[4];
					}
					if (j == 2)
					{
						light[1] = !light[1];
						light[5] = !light[5];
					}
					if (j == 3)
					{
						light[0] = !light[0];
						light[4] = !light[4];
						light[6] = !light[6];
					}
					if (j == 4)
					{
						light[1] = !light[1];
						light[3] = !light[3];
						light[5] = !light[5];
	  					light[7] = !light[7];
					}
					if (j == 5)
					{
						light[2] = !light[2];
						light[4] = !light[4];
						light[8] = !light[8];
					}
					if (j == 6)
					{
	  					light[3] = !light[3];
	  					light[7] = !light[7];
					}
					if (j == 7)
					{
						light[4] = !light[4];
						light[6] = !light[6];
						light[8] = !light[8];
					}
					if (j == 8)
					{
						light[5] = !light[5];
	  					light[7] = !light[7];
					}
				}
			}
			
			if (check())
			{
//				for (int j = 0; j < 9; j++)
//					cout << a[i][j];
//				cout << endl;
				string s;
				for (int j = 0; j < 9; j++)
					s += '0' + a[i][j];
				ans.push_back(s);
			}
			
			for (int k = 0; k < 9; k++)
				light[k] = false;
			
		} while (next_permutation(a[i], a[i] + 9));
	}
	
	sort(ans.begin(), ans.end());
	
	for (vector<string>::iterator it = ans.begin(); it < ans.end(); it++)
		cout << *it << endl;
	
}

int main()
{
	solve();
	return 0;
}
