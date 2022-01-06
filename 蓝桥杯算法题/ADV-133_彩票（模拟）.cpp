#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define N 7

using namespace std;

enum Prize
{ NON = 0, SIX = 1, FIVE, FOUR, THREE, TWO, ONE, SPEC };

vector<int> winLott;//中奖彩票
int lott[N];        //当前彩票
int winCount[N];    //中奖彩票数量

Prize checkLott()
{
	int samNum = 0;
	for (int i = 0; i < N; i++)
		samNum += count(winLott.begin(), winLott.end(), lott[i]);
	Prize p = (Prize)samNum;
	return p;
}

int main(int argc, char** argv)
{
	int lotteryCount = 0;
	cin >> lotteryCount;
	
	//输入中奖彩票
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		winLott.push_back(temp);
	}

	//输入并处理彩票
	for (int i = 0; i < lotteryCount; i++)
	{
		//输入一张彩票
		for (int j = 0; j < N; j++)
			cin >> lott[j];
		switch (checkLott())
		{
		case SPEC:
			winCount[0] += 1;
			break;
		case ONE:
			winCount[1] += 1;
			break;
		case TWO:
			winCount[2] += 1;
			break;
		case THREE:
			winCount[3] += 1;
			break;
		case FOUR:
			winCount[4] += 1;
			break;
		case FIVE:
			winCount[5] += 1;
			break;
		case SIX:
			winCount[6] += 1;
			break;
		default:
			break;	
		}
		memset(lott, 0x00, sizeof(lott));
	}

	for (int i = 0; i < N; i++)
		cout << winCount[i] << " ";
	cout << endl;
		
 	return 0;
}