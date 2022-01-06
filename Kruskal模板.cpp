#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <memory.h>

#define N 1002
#define INF 0x3FFFFFFF

using namespace std;

//边的定义 
class Edge{
public:
 int u,v,w;
};

int father[N];//并查集 
Edge E[N];//边数据数组，也可以使用动态数组 

int findFather(int x)
{
 if(x == father[x]) return x;
 else return findFather(father[x]);
}

bool cmp(Edge a,Edge b)
{
 return a.w < b.w;
}

int Kruskal(int n,int m)
{
 int ans = 0,edgeCount = 0;
 
 //初始化并查集为离散的点 
 for(int i = 1;i <= n;i++)
 {
  father[i] = i;
 }
 
 //并查集排序
 sort(E,E + m,cmp); 
 
 for(int i = 0;i < m;i++)
 {
  int faU = findFather(E[i].u);
  int faV = findFather(E[i].v);
  //并 
  if(faU != faV)
  {
   father[faU] = faV;
   ans += E[i].w;
   edgeCount += 1;
   if(edgeCount == n - 1) break;
  }
  
  //判断edgeCount是否为n-1，如果不是就表明不连通，返回-1 
  if(edgeCount != n-1) return -1;
  else return ans;
 }
 
 
}

int main(int argc, char** argv)
{

	return 0;
}

