#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

char Map[] = {'1', '0', 'x', '9', '8', '7', '6', '5', '4', '3', '2'};

int main(void)
{
	freopen("input0.txt", "r", stdin);
	string id;
	cin >> id;
	id.insert(6, "19");
	
	int num = 0;
	num += (id[0] - '0')*7;
	num += (id[1] - '0')*9;
	num += (id[2] - '0')*10;
	num += (id[3] - '0')*5;
	num += (id[4] - '0')*8;
	num += (id[5] - '0')*4;
	num += (id[6] - '0')*2;
	num += (id[7] - '0')*1;
	num += (id[8] - '0')*6;
	num += (id[9] - '0')*3;
	num += (id[10] - '0')*7;
	num += (id[11] - '0')*9;
	num += (id[12] - '0')*10;
	num += (id[13] - '0')*5;
	num += (id[14] - '0')*8;
	num += (id[15] - '0')*4;
	num += (id[16] - '0')*2;
	num %= 11;
	
	id += Map[num];
	cout << id << endl;

	fclose(stdin);
	return 0;
}
