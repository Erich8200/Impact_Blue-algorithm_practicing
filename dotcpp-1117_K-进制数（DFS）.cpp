#include <iostream>
#include <vector>

using namespace std;

int ansCount;

//����1����ǰ������λ��
//����2����λ��
//����3������
//����4����ǰ��ɵ���
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
			//��λ��0���߼�������2λ��0
			if ((cur >= 1 && curNum[cur - 1] == 0 && i == 0) || (cur == 0 && i == 0))
				continue;
			else
			{
				curNum[cur] = i;
				DFS(cur + 1, n, k, curNum);
				//����ָ�����Ϊ֮��Ľ���Ḳ��֮ǰ�Ľ�������Խ�Լһ��ʱ��
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