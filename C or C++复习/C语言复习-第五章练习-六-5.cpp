#include <iostream>
#define Min(a,b) (a<b?a:b)

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void CommonFactors(int cur,int a,int b)
{
	static int count = 0;
	if(cur > Min(a,b)) return;
	else
	{
		CommonFactors(cur + 1,a,b);
		if(a%cur == 0 && b%cur == 0) 
		{
			count++;
			cout << "Common factor " << count << " is " << cur << endl;
		}
	}
}

int main(int argc, char** argv) 
{
	int a,b;
	cout << "Input two ints:";
	cin >> a >> b;
	CommonFactors(1,a,b);
	return 0;
}
