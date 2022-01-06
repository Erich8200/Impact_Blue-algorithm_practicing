#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool cmp(int a,int b)
{
	return a > b;
}

double avg(vector<int> a)
{
	int sum = 0;
	for(int i = 0;i < a.size();i++)
		sum += a[i];
	return sum/a.size();
}

int countLarge(int average,vector<int> a)
{
	int count;
	for(int i = 0;i < a.size();i++)
	{
		if(a[i] > average)
			count += 1; 
	}
	return count;
}

int main(int argc, char** argv) 
{
	vector<int> a;
	int temp;
	for(int i = 0;i < 10;i++)
	{
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(),a.end(),cmp);
	
	double average = avg(a);
	int count = countLarge(average,a);
	
	for(int j = 0;j < a.size();j++)
		cout << a[j] << " ";
	cout << "\nCOUNT = " << count << endl;
	
	return 0;
}
