#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

typedef struct{
	vector<int> satisfy;
	int x;
} Point;

vector< pair<int, int> > lines;
vector<Point> points;

void getSatisfies()
{
	for (int i = 0; i < points.size(); i++)
	{
		for (int j = 0; j < lines.size(); j++)
		{
			if (lines[j].first >= 0 && lines[j].first <= points[i].x && lines[j].second >= points[i].x)
			{
				points[i].satisfy.push_back(j);
			}
		}
	}
}

bool cmp(Point a, Point b)
{
	return a.satisfy.size() > a.satisfy.size();
}

void clearLines(Point& p)
{
	for (int i = 0; i < p.satisfy.size(); i++)
		lines[i].first = lines[i].second = -1;
	p.satisfy.clear();
}

int solve()
{
	int ans = 0;
	while (true)
	{
		getSatisfies();
		sort(points.begin(), points.end(), cmp);
		if (points[0].satisfy.size() == 0)
			break;
		clearLines(points[0]);
		ans += 1;
	}
	
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i].first >= 0)
		{
			ans = -1;
			break;
		}
	}
	return ans;
}

int main()
{
	freopen("0.txt", "r", stdin);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int xx = 0;
		scanf("%d", &xx);
		Point p;
		p.x = xx;
		points.push_back(p);
	}
	
//	for (int i = 0; i < points.size(); i++)
//		cout << points[i].x << " ";
//
//	cout << endl;
	
	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		scanf("%d%d", &a, &b);
		lines.push_back(make_pair(a, b));
	}
	
//	for (int i = 0; i < lines.size(); i++)
//	{
//		cout << lines[i].first << " " << lines[i].second << endl;
//	}
	
	cout << solve() << endl;
	fclose(stdin);
	return 0;
}
