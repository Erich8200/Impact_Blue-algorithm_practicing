#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void fun(int cur,int n,int& result)
{
	if(n <= 0)
	{
		cout << "Input Error" << endl;
		return;
	}
	else if(cur > n) return;
	else
	{
		result += cur;
		fun(cur + 1,n,result);
	}
}

int main(int argc, char** argv) 
{
	int result = 0;
	int n;
	cin >> n;
	fun(1,n,result);
	if(result > 0)
		cout << result << endl;
	return 0;
}
