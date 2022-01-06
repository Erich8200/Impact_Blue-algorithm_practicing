#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#define N 20

using namespace std;

vector<char> letters;

bool cmp(char a, char b)
{
	return a < b;
}

int main(int argc, char** argv)
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		letters.push_back(s.at(i));
	sort(letters.begin(), letters.end(), cmp);
	do
	{
		for (int i = 0; i < letters.size(); i++)
			cout << letters.at(i);
		cout << endl;
	} while (next_permutation(letters.begin(),letters.end()));
	system("pause");
	return 0;
}