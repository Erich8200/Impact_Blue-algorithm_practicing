#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int Maxn = 50;
int n,total,pos[Maxn];
int vis[3][2*Maxn];

void nQueen(int cur,int n)
{
	if(cur == n)
	{
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				if(pos[i] == j) cout << 'X';
				else cout << 'O';
				if(j == n - 1) cout << endl;
			}		
		}
		cout << endl;
		total++;
	}
	else
	{
		for(int i = 0;i < n;i++)
		{
		    //冲突检测：其中主对角线+n是防止出现负数
			if(!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n])
			{ 
				pos[cur] = i;//第cur行的pos（位置）是i 
				vis[0][i] = 1;
				vis[1][cur + i] = 1;
				vis[2][cur - i + n] = 1;
				//进入下一层搜索 
				nQueen(cur + 1,n);
				//恢复 
				vis[0][i] = 0;
				vis[1][cur + i] = 0;
				vis[2][cur - i + n] = 0;
			}
		}
	}
}

int main(int argc, char** argv) 
{
    int n;
    cin >> n;
	nQueen(0,n);
	cout << total << endl;
	return 0;
}
