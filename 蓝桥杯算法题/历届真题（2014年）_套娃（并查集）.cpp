#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

map<int, int> dollSet;

int Q(int x)
{
	int ans = 0;
	while (dollSet[x] != x && dollSet[x] != 0)
	{
		x = dollSet[x];
		ans += 1;
	}
	return ans;
}

int P(int x, int n)
{
	int count = 0;
	int preX = x;
	while (dollSet[x] != x && dollSet[x] != 0)
	{	
		//找前驱是x的结点的值，前驱->前驱的前驱 
		for (map<int, int>::iterator it = dollSet.begin(); it != dollSet.end(); it++)
			if (it->second == x)
				it->second = dollSet[x];
		preX = x;
		x = dollSet[x];
		count += 1;
	}
	
	//解开根结点，构造一个虚拟的“根结点” 
	for (map<int, int>::iterator it = dollSet.begin(); it != dollSet.end(); it++)
		if (it->second == n)
			it->second = 0;
			
	return count;
}

int main(void)
{
	freopen("input0.txt","r",stdin);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++)
	{
		int a,b;
		cin >> a >> b;
		dollSet[b] = a;
	}
	dollSet[n] = n;
	
//	cout << Q(1) << endl;
//	cout << Q(4) << endl;
//	cout << P(2, n) << endl;	
//	cout << Q(1) << endl;
//	cout << Q(4) << endl;

	for (int i = 0; i < m; i++)
	{
		char ch;
		int x;
		cin >> ch >> x;
		switch (ch)
		{
		case 'Q':
			cout << Q(x) << "\n";
			break;
		case 'P':
			cout << P(x, n) << "\n";
			break;
		}
	}
	
	fclose(stdin);
	return 0;
}
