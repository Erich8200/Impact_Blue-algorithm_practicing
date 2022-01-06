#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>

using namespace std;

vector<int> nums;
vector< vector<int> > comps;
vector< pair<int, int> > coordiV;
vector< pair<int, int> > coordiP;
vector< pair<double, int> > minDistance;

//求组合数，计算邮局编号的组合
void C(int cur, const int n, int curLen, const int k, vector<int> comp)
{
	if (cur >= n)
	{
		if (curLen == k)
			comps.push_back(comp);
		return;
	}
	else if (curLen == k)
	{
		comps.push_back(comp);
		return;
	}
	else
	{
		comp.push_back(cur); 
		C(cur + 1, n, curLen + 1, k, comp);
		comp.pop_back();
		C(cur + 1, n, curLen, k, comp);
	}
}

//计算距离
double calcDistance(double x1, double x2, double y1, double y2)
{
	return sqrt(fabs((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}

bool cmp(pair<int, double> a, pair<int, double> b)
{
	return a.second < b.second;
}

//计算最短距离和
int getMinDistIndex()
{
	vector< pair<int, double> > minDistArr;
	for (int i = 0; i < comps.size(); i++)
	{
		vector<double> minDistsArr;
		for (int k = 0; k < coordiV.size(); k++)
		{
			double x1 = coordiV[k].first;
			double y1 = coordiV[k].second;
			vector<double> distArr;
			for (int j = 0; j < comps[i].size(); j++)
			{
				double x2 = coordiP[comps[i][j]].first;
				double y2 = coordiP[comps[i][j]].second;
				double dist = calcDistance(x1, x2, y1, y2);
				distArr.push_back(dist);
			}
			//从当前村民到所有邮局的距离中选一条最短路径并放入最短路径集合
			double minDist = *min_element(distArr.begin(), distArr.end());
			minDistsArr.push_back(minDist);
		}

		//从最短路径集合中求
		double d = 0;
		for (vector<double>::iterator it = minDistsArr.begin(); it < minDistsArr.end(); it++)
		{
			d += *it;
		}

		//保存路径长度和的结果
		minDistance.push_back(pair<int, double>(i, d));
	}

	auto index = min_element(minDistance.begin(), minDistance.end(), cmp);
	return index->first;
}

int main(int argc, char** argv)
{
	freopen("input5.txt", "r", stdin);
	int n = 0, m = 0, k = 0, i = 0, x = 0, y = 0;
	cin >> n >> m >> k;
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		pair<int, int> temp(x, y);
		coordiV.push_back(temp);
	}
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		pair<int, int> temp(x, y);
		coordiP.push_back(temp);
	}

	//求选择邮局的组合
	vector<int> comp;
	C(0, m, 0, k, comp);

	int index =  getMinDistIndex();

	for (auto it = comps[index].begin(); it < comps[index].end(); it++)
	{
		cout << *it + 1 << " ";
	}
	cout << endl;

	system("pause");
	fclose(stdin);
	return 0;
}