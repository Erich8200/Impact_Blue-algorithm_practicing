#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
#include <stdio.h>

#define N 100000

using namespace std;

string intToString(int n)
{
    string str;
    while (n) {
        str += n%10 + '0';
        n /= 10;
    }
    reverse(str.begin(),str.end());
    return str;
}

int getCount(string str)
{
    int oneCount = count(str.begin(),str.end(),'1');
    int twoCount = count(str.begin(),str.end(),'2');
    return oneCount + twoCount;
}

long long F(int n)
{
    long long ans = 0;
    for (int i = 1;i <= n;i++)
    {
        string str = intToString(i);
        ans += getCount(str);
    }
    return ans % 201203;
}

int main()
{
    int n = 0;
    cin >> n;
    cout << F(n) << endl;
    return 0;
}
