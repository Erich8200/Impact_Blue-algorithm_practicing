#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

char A[27] = {'\0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int main()
{
    int n = 0;
    cin >> n;
    if(n == 1)
        cout << 'A' << endl;
    else
    {
        int i = 2;
        string str = "A";
        while (i <= n) {
            str = str + A[i] + str;
            i++;
        }
        cout << str << endl;
    }
    return 0;
}

