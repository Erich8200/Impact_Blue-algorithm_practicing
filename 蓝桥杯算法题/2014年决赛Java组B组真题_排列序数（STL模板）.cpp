#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
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
	vector<char> lettersBak;
	for (int i = 0; i < s.length(); i++)
		letters.push_back(s.at(i));
	lettersBak = letters;
	sort(letters.begin(), letters.end(), cmp);
	int index = 0;
	do
	{
		if (letters == lettersBak)
			break;
		index += 1;
	} while (next_permutation(letters.begin(),letters.end()));
	cout << index << endl;
	system("pause");
	return 0;
}