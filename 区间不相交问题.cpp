#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

const int maxn = 110;

using namespace std;

struct Inteval{
	int x,y;
}I[maxn];

bool cmp(Inteval a,Inteval b)
{
	//先按左端点从小到大排序，左端点相同在按右端点从小到大排序，筛选“包含”  的情况，规避繁琐的判断 
	if(a.x != b.x) return a.x > b.x;
	else return a.y < b.y;
}

int main(int argc, char** argv)
{
	int n,x,y;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> x >> y;
		I[i].x = x;
		I[i].y = y;
	}	
	
	sort(I,I + n,cmp);
	
	int ans = 1,lastX = I[0].x;
	for(int j = 1;j < n;j++)
	{
		if(I[j].y <= lastX)
		{
			lastX = I[j].x;
			ans += 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
