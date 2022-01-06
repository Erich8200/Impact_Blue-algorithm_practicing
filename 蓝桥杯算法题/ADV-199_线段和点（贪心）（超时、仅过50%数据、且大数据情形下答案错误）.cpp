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
	Line(int a, int b) : a(a), b(b) {  }//�ߵĹ��캯��
};

class Point
{
public:
	int x;
	int coverCount;                         //�����������ߵļ���
	vector<int> coverage;                   //�����������ߵ�����
	Point(int x) : x(x) { coverCount = 0; } //��Ĺ��캯��
	Point() { }                             //���Ĭ�Ϲ��캯����������=ʱʹ��
	bool checkCoverage(Line& l, int lineNo);//��������������߼�������
	void removeCoveredLine(int lineNo);     //���Ѹ��ǵ��ߴӵ�������г�ȥ
};

bool covered[N];        //���Ƿ񱻸��ǵļ�¼
vector<Point> pointSet; //�㼯
vector<Line> lineSet;   //�߼�

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

bool cmp(Point a, Point b)//Ϊ������������ߵ������Ӵ�С����
{
	return a.coverCount > b.coverCount;
}

//����Ƿ������߶�������
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
	//ִ��ֱ�������߶�������
	while (!isAllCovered())
	{
		sort(pointSet.begin(), pointSet.end(), cmp);//������������ߵ������Ӵ�С����
		Point curPoint = pointSet[0];               //ÿ��ѡȡ���������������һ����
		ans += 1;
		//����ǰ����������ߴ���������ɾȥ
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