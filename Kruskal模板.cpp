#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <memory.h>

#define N 1002
#define INF 0x3FFFFFFF

using namespace std;

//�ߵĶ��� 
class Edge{
public:
 int u,v,w;
};

int father[N];//���鼯 
Edge E[N];//���������飬Ҳ����ʹ�ö�̬���� 

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
 
 //��ʼ�����鼯Ϊ��ɢ�ĵ� 
 for(int i = 1;i <= n;i++)
 {
  father[i] = i;
 }
 
 //���鼯����
 sort(E,E + m,cmp); 
 
 for(int i = 0;i < m;i++)
 {
  int faU = findFather(E[i].u);
  int faV = findFather(E[i].v);
  //�� 
  if(faU != faV)
  {
   father[faU] = faV;
   ans += E[i].w;
   edgeCount += 1;
   if(edgeCount == n - 1) break;
  }
  
  //�ж�edgeCount�Ƿ�Ϊn-1��������Ǿͱ�������ͨ������-1 
  if(edgeCount != n-1) return -1;
  else return ans;
 }
 
 
}

int main(int argc, char** argv)
{

	return 0;
}

