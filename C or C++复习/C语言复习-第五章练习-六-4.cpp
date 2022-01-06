#include <iostream>
#include <string>
#include <math.h>
#define Max(a,b) a>b?a:b
#define Min(a,b) a<b?a:b

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int MaxCommonFactor(int a,int b)
{
	int diff = (a>b?a-b:b-a);
	if((Min(a,b)) == diff) return diff;
	else MaxCommonFactor(Min(a,b),diff);
}

int main(int argc, char** argv) 
{
	int a,b;
	cout << "Input two ints:";
	cin >> a >> b;
	int result = MaxCommonFactor(a,b);
	if(result == 1)
		cout << -1 << endl;
	else
		cout << "Max common factor of " << a << " and " << b << " is " << result;
	return 0;
}
