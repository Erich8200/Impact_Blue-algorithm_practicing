#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool comp(char a,char b)
{
	return a > b;
}

int main(int argc, char** argv) 
{
	string str;
	cout << "Enter a string:";
	cin >> str;
	sort(str.begin(),str.end(),comp);
	cout << str;
	return 0;
}
