#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	double x,n,S;
	cin >> n >> S;
	x = (S - n + 2*pow(2, n) - 2)/(2*pow(2, n) - 1);
	cout << x << endl;
    return 0;
}
