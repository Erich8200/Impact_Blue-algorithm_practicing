#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fun(int cur,int num,int& result)
{
	if(num == 0 && cur != 1) return 1;
	else if(num == 0 && cur == 1) return 0;
	fun(cur + 1,num/10,result);
	return result *= num%10;
}

int main(int argc, char** argv) 
{
	int result = 1;
	int num;
	cin >> num;
	cout << fun(1,num,result) << endl;
	return 0;
}
