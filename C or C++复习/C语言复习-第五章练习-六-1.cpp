#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const double e = 2.718281828;

double ln(int n)
{
	return (log(n)/log(e));
}

double fun(int cur,int m)
{
	static double result = 0;
	if(cur > m)
		return result;
	else
	{
		fun(cur + 1,m);
		return result += ln(cur);
	}
}

int main(int argc, char** argv) 
{
	cout << pow(fun(1,20),0.5) << endl;
	return 0;
}
