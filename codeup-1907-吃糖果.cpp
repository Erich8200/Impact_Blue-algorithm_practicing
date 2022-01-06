#include <iostream>
#include <string>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void DFS(int cur,int curCount,int n,int& totalCount)
{
	if(n == 0)
		return;
	if(curCount > n)
	{
		return;
	}
	else if(curCount == n)
	{
		totalCount += 1;
		return;
	}
	else
	{
		DFS(cur + 1,curCount + 1,n,totalCount);
		DFS(cur + 1,curCount + 2,n,totalCount);
	}
}

int main(int argc, char** argv) 
{
	int total = 0;
	int n = 0;
    while(scanf("%d",&n) == 1) 
	{
    	if (n <= 0 || n >= 20)
    	{
    		cout << "" << endl;
    		continue;
		}
	    else 
		{
			total = 0;
	        DFS(1,0,n,total);
			cout << total << endl;
	    }
	}
	return 0;
}
