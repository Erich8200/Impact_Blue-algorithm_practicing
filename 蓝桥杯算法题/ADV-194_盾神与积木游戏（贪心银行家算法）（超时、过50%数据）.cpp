#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#define N 10000

using namespace std;

int request[N];//�������Դ��
int allocated[N];//�ѷ������Դ��
int need[N];//����Ҫ����Դ��
int sum;//��Դ����

//�ҵ��������񣬲�����̰�ķ�ѡ�񣬷�����ҵ������
int getReadyJob(int n)
{
	int maxAllocated = 0;
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (sum >= need[i] && request[i] > 0)
		{
			//̰�ģ�ѡ���ѷ������ģ�������ɺ�����ջ����
			if (maxAllocated < allocated[i])
			{
				maxAllocated = allocated[i];
				index = i;
			}
		}
	}
	return index;
}

//ˢ����������ҵ��need����
void refreshNeed(int n)
{
	for (int i = 0; i < n; i++)
		if (request[i])
			need[i] = request[i] > allocated[i] ? (request[i] - allocated[i]) : 0;
}

//��ɵ�ǰ��ҵ��������Դ
void finishJob(int i)
{
	sum += allocated[i];
	request[i] = 0;
	allocated[i] = 0;
	need[i] = 0;
}

bool solve(int n)
{
	bool ans = true;
	refreshNeed(n);
	//���������ҵ��������ɿ��ԣ���ôÿ�ζ������һ����ҵ
	for (int time = 1; time <= n; time++)
	{
		int j;
		//����ֵ��-1˵�������Ҳ������Լ�����ɵ���ҵ���˳�
		if ((j = getReadyJob(n)) >= 0)
		{
			finishJob(j);
			refreshNeed(n);
		}
		else
		{
			ans = false;
			break;
		}
	}
	return ans;
}

int main(int argc, char** argv)
{
	freopen("input5.txt", "r", stdin);
	int m = 0;
	cin >> m;
	while (m--)
	{
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> allocated[i];
			cin >> request[i];
		}
		if (solve(n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		memset(allocated, 0x00, sizeof(allocated));
		memset(request, 0x00, sizeof(request));
		memset(need, 0x00, sizeof(need));
		sum = 0;
	}
	fclose(stdin);
	return 0;
}