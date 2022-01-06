#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define N 20

using namespace std;

vector<int> arr;

int main(int argc, char** argv)
{
 int n = 0;
 cin >> n;
 int index = 0;
 cin >> index;
 for (int i = 0;i < n;i++)
 {
  int temp;
  cin >> temp;
  arr.push_back(temp);
 }
 
 int i = 1;
 while(next_permutation(arr.begin(),arr.end()))
 {
  if (i == index)
   break;
  i += 1;
 }
 
 for (vector<int>::iterator it = arr.begin();it < arr.end();it++)
 {
  cout << *it << " ";
 }
 
	return 0;
}
