#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#define N 10000

using namespace std;

class Line
{
public:
	int a;
	int b;
	Line(int a, int b) : a(a), b(b) {  }//线的构造函数
};

class Point
{
public:
	int x;
	int coverCount;                         //点可以满足的线的计数
	vector<int> coverage;                   //点可以满足的线的序列
	Point(int x) : x(x) { coverCount = 0; } //点的构造函数
	Point() { }                             //点的默认构造函数，便于在=时使用
	bool checkCoverage(Line& l, int lineNo);//计算点可以满足的线及其数量
	void removeCoveredLine(int lineNo);     //将已覆盖的线从点的序列中除去
};

bool covered[N];        //线是否被覆盖的记录
vector<Point> pointSet; //点集
vector<Line> lineSet;   //线集

bool Point::checkCoverage(Line& l, int lineNo)
{
	if (this->x >= l.a && this->x <= l.b)
	{
		coverage.push_back(lineNo);
		coverCount += 1;
		return true;
	}
	return false;
}

void Point::removeCoveredLine(int lineNo)
{
	vector<int>::iterator it = find(coverage.begin(), coverage.end(), lineNo);
	if (it != coverage.end())
	{
		coverage.erase(it);
		coverCount -= 1;
	}
}

bool cmp(Point a, Point b)//为按点能满足的线的数量从大到小排序
{
	return a.coverCount > b.coverCount;
}

//检查是否所有线都被满足
bool isAllCovered()
{
	bool ret = true;
	for (int i = 0; i < lineSet.size(); i++)
	{
		if (!covered[i])
		{
			ret = false;
			break;
		}
	}
	return ret;
}

int solve()
{
	int ans = 0;
	//执行直到所有线都被满足
	while (!isAllCovered())
	{
		sort(pointSet.begin(), pointSet.end(), cmp);//按点能满足的线的数量从大到小排序
		Point curPoint = pointSet[0];               //每次选取能满足的线最多的那一个点
		ans += 1;
		//将当前点能满足的线从其他点中删去
		for (int i = 0; i < curPoint.coverCount; i++)
		{
			int coveredLineNo = curPoint.coverage[i];
			covered[coveredLineNo] = true;
			for (int j = 0; j < pointSet.size(); j++)
				pointSet[j].removeCoveredLine(coveredLineNo);
		}
	}
	return ans;
}

int main(int argc, char** argv)
{
	/*freopen("input0.txt", "r", stdin);*/

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pointSet.push_back(Point(x));
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		lineSet.push_back(Line(a, b));
	}

	for (vector<Point>::iterator it = pointSet.begin(); it < pointSet.end(); it++)
		for (int i = 0; i < lineSet.size(); i++)
			it->checkCoverage(lineSet[i], i);

	cout << solve() << endl;

	//fclose(stdin);
	return 0;
}