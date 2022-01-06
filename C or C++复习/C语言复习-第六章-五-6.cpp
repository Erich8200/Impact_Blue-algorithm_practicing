#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void int_to_str(int cur,int num,char* s)
{
	static int len = 0;
	len++;
	if(num == 0) 
		return;
	int_to_str(cur + 1,num/10,s);
	s[len-cur-1] = '0' + num%10;
}

int main(int argc, char** argv) 
{
	int num = 0;
	while(num <= 0)
	{
		cout << "请输入一个整数：";
		cin >> num;	
	}
	char* s = new char[(int)log(num)];
	int_to_str(1,num,s);
	cout << "The result is " << s << endl;
	delete s;
	return 0;
}
