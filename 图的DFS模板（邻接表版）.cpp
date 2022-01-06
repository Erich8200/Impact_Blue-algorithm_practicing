#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define N 5

using namespace std;

class Node{
private:
	int v,w;
public:
	Node(int vertex,int weigh):v(vertex),w(weigh){	}
	int getV(){return this->v;}
	int getW(){return this->w;}
};

vector<Node> G[N]; 
bool visited[N] = {false};

void DFS(int u,int cur)
{
	//Add operation here
	cout << u << endl;
	visited[u] = true;
	for(int i = 1;i < G[u].size();i++)
	{
		int v = G[u][i].getV();
		if(visited[v] == false)
			DFS(v,cur + 1);
	}
}

void DFSTraverse(vector<Node>* G)
{
	for(int i = 0;i < N;i++)
		if(visited[i] == false)
			DFS(i,1);
}

int main(int argc, char** argv)
{
	G[0].push_back(Node(0,INT_MAX));
	G[0].push_back(Node(1,2));
	G[0].push_back(Node(4,1));
	
	G[1].push_back(Node(1,INT_MAX));
	G[1].push_back(Node(0,2));
	G[1].push_back(Node(2,2));
	G[1].push_back(Node(4,2));
	
	G[2].push_back(Node(2,INT_MAX));
	G[2].push_back(Node(1,2));
	G[2].push_back(Node(3,1));
	
	G[3].push_back(Node(3,INT_MAX));
	G[3].push_back(Node(2,1));
	G[3].push_back(Node(4,1));
	
	G[4].push_back(Node(4,INT_MAX));
	G[4].push_back(Node(0,1));
	G[4].push_back(Node(1,2));
	G[4].push_back(Node(3,1));
	
	DFSTraverse(G);
	
	return 0;
}
