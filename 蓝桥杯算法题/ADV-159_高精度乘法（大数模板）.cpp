#include <iostream>
#include <string>
#include <memory.h>
#include <stdio.h>

#define N 100000

using namespace std;

class BigInt
{
private:
    int d[N+2];
    int len;
public:
    BigInt() {memset(d,0x00,sizeof(d));}
    BigInt(string str);
    inline void showInt(){
        for(int i = len-1;i >= 0;i--)
            printf("%d",d[i]);
    }
    friend BigInt operator*(const BigInt& a,const BigInt& b);
};

BigInt::BigInt(string str)
{
    memset(d,0x00,sizeof(d));
    this->len = str.length();
    for(int i = 0;i < this->len;i++)
    {
        this->d[i] = str[this->len - i - 1] - '0';
    }
}

BigInt operator*(const BigInt& a,const BigInt& b)
{
    BigInt c;
    c.len = a.len + b.len;
    int i,j;
    for (i = 0;i < a.len;i++)
        for(j = 0;j < b.len;j++)
            c.d[i+j] += a.d[i]*b.d[j];

    for (i = 0;i < c.len - 1;i++)
    {
        c.d[i+1] += c.d[i]/10;
        c.d[i] %= 10;
    }

    while (c.d[i]) {
        c.d[i+1] += c.d[i]/10;
        c.d[i] %= 10;
        i++;
    }

    while (c.d[i] == 0 && i >= 1) i--;
    c.len = i+1;
    return c;
}

int main()
{
    freopen("input3.txt","r",stdin);
    string aStr, bStr;
    cin >> aStr >> bStr;
    BigInt a(aStr);
    BigInt b(bStr);
    BigInt ans = a*b;
    ans.showInt();
    cout << endl;
    fclose(stdin);
    return 0;
}
