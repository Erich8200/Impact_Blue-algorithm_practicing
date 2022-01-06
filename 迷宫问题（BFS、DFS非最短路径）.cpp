#include <iostream>
#include <string>
#include <queue>
#include <math.h>
#include <algorithm>
#define N 50

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int maze[N][N] = {{1,1,0,1},{1,0,1,1},{1,0,1,0},{1,0,1,1},{1,1,1,0},{1,1,1,1}};
bool visited[N][N] = {false};

class Pos
{
private:
	int x,y,step = 0;
public:
	int getX(){return x;}
	int getY(){return y;}
	int getStep(){return step;}
	int setX(int value){x = value;}
	int setY(int value){y = value;}
	void setStep(int value){step = value;}
	Pos(int x,int y){this->x = x;this->y = y;}
	Pos(){}
};

void fillMaze(int m,int n)
{
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
			cin >> maze[i][j];
	}
}

void printMaze(int m,int n)
{
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
			cout <<  maze[i][j];
		cout << '\n';
	}	
}

bool putAdj(int x,int y,int curStep,queue<Pos>& q)
{
	if(maze[x][y]== 1 && visited[x][y] == false)
	{
		Pos temp(x,y);
		temp.setStep(curStep+1);
		q.push(temp);
		visited[x][y] = true;
		return true;
	}
	else
		return false;
}

int mazeQ(int startX,int startY,int endX,int endY,queue<Pos>& q)
{
	if(maze[startX] == 0 || maze[startY] == 0 || maze[endX] == 0 || maze[endY] == 0) return INT_MAX;//起点终点合法性检查 
	int stepCount = 0;
	
	Pos temp(startX,startY),node;
	q.push(temp);
	visited[startX][startY] = true;
	
	while(!q.empty())
	{
		node = q.front();
		if(node.getX() == endX && node.getY() == endY) break;
		int nodeX = node.getX(),nodeY = node.getY();
		stepCount = node.getStep();
		putAdj(nodeX-1,nodeY,stepCount,q);
		putAdj(nodeX+1,nodeY,stepCount,q);
		putAdj(nodeX,nodeY-1,stepCount,q);
		putAdj(nodeX,nodeY+1,stepCount,q);
		q.pop();
	}
	
	if(node.getX() == endX && node.getY() == endY)
		return node.getStep();
	else
		return INT_MAX;
}

void mazeQ_DFS(int cur, int curX, int curY, int endX, int endY)
{
	static int time = 1;
	if (curX == endX && curY == endY)
	{
		if (time == 1)
		{
			cout << "(" << curX << "," << curY << ")" << endl;
			cout << "\n";
		}
		time += 1;
		return;
	}
	else
	{
		if (time == 1)
			cout << "(" << curX << "," << curY << ")" << endl;
		if (maze[curX - 1][curY] == 1 && !visited[curX - 1][curY])
		{
			visited[curX - 1][curY] = true;
			mazeQ_DFS(cur + 1, curX - 1, curY, endX, endY);			
			visited[curX - 1][curY] = false;
		}
		if (maze[curX + 1][curY] == 1 && !visited[curX + 1][curY])
		{
			visited[curX + 1][curY] = true;
			mazeQ_DFS(cur + 1, curX + 1, curY, endX, endY);
			visited[curX + 1][curY] = false;
		}
		if (maze[curX][curY - 1] == 1 && !visited[curX][curY - 1])
		{
			visited[curX][curY - 1] = true;
			mazeQ_DFS(cur + 1, curX, curY - 1, endX, endY);
			visited[curX][curY - 1] = false;
		}
		if (maze[curX][curY + 1] == 1 && !visited[curX][curY + 1])
		{
			visited[curX][curY + 1] = true;
			mazeQ_DFS(cur + 1, curX, curY + 1, endX, endY);
			visited[curX][curY + 1] = false;
		}
	}
}

int main(int argc, char** argv) 
{
	int m,n,a,b,x,y;
	cout << "输入迷宫的行数和列数：";
	cin >> m >> n;
	cin.clear();
	cin.sync();
	cout << "输入迷宫：" <<endl;
	fillMaze(m,n);
	cout << "输入起点坐标：";
	cin >> a >> b;
	cout << "输入终点坐标：";
	cin >> x >> y;	
	queue<Pos> Q;
	cout << mazeQ(a,b,x,y,Q) << endl;
	return 0;
}
