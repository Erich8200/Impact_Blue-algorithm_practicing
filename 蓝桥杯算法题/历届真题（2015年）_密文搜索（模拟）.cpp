#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr;

bool cmp (char a, char b)
{
 return a < b; 
} 

int solve (string& str, vector<string>& passList)
{
 int times = 0;
 for (vector<string>::iterator it = passList.begin(); it < passList.end(); it++)
 {
  string curPass = *it;
  sort(curPass.begin(), curPass.end(), cmp);
  while (next_permutation(curPass.begin(), curPass.end()))
  {
   int curIndex = 0;
   while (str.find(curPass, curIndex) != string::npos)
   {
    times += 1;
    curIndex += 1;
    if (curIndex >= curPass.length())
     break;
   }
  }
 }
 return times;
}

int main(void)
{
 freopen("input0.txt","r",stdin);
 string str;
 cin >> str;
 int n = 0;
 cin >> n;
 vector<string> passList;
 for (int i = 1; i <= n; i++)
 {
  string pass;
  cin >> pass;
  passList.push_back(pass);
 }
 
 cout << solve(str, passList) << endl;
 fclose(stdin);
	return 0;
} 

