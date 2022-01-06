#include <iostream>
#include <vector>

using namespace std;

int ansCount;

//参数1：当前操作的位数
//参数2：总位数
//参数3：进制
//参数4：当前组成的数
void DFS(int cur, const int n, const int k, int* curNum)
{
	if (cur >= n)
	{
		ansCount += 1;
		return;
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			//首位是0或者即将连续2位是0
			if ((cur >= 1 && curNum[cur - 1] == 0 && i == 0) || (cur == 0 && i == 0))
				continue;
			else
			{
				curNum[cur] = i;
				DFS(cur + 1, n, k, curNum);
				//无需恢复，因为之后的结果会覆盖之前的结果，可以节约一点时间
			}
		}
	}
}

int main(int argc, char** argv)
{
	int curNum[1000];
	int n = 0, k = 0;
	cin >> n >> k;
	DFS(0, n, k, curNum);
	cout << ansCount << endl;
	return 0;
}