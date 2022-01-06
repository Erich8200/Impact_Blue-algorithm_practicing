#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void rev(string str)
{
	int p1 = 0, p2 = 0;
	for (p1 = p2 = str.length() - 1; p1 >= 0; p1--)
	{
		if (str[p1] == ' ' || p1 == 0)
		{
			int i;
			for (i = (str[p1] == ' ' ? p1 + 1 : 0); i <= p2; i++)
			{
				cout << str[i];
			}
			p2 = p1 - 1;
			cout << ' ';
		}
	}
}

void rev_s(const string str, string& rev_str)
{
	int p1 = 0, p2 = 0;
	for (p1 = p2 = str.length() - 1; p1 >= 0; p1--)
	{
		if (str[p1] == ' ' || p1 == 0)
		{
			int i = (str[p1] == ' ' ? p1 + 1 : 0);
			rev_str.append(str.substr(i, p2-i+1));
			rev_str += " ";
			p2 = p1 - 1;
		}
	}
}

int main(int argc, char** argv)
{
	string str;
	string new_str;
	getline(cin, str);
	rev(str);
	rev_s(str, new_str);
	cout << "\n" << new_str << endl;
	getchar();
	return 0;
}