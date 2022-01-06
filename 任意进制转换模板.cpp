#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int pow(int n,int power)
{
	int ans = 1;
	for(int i = 1;i <= power;i++)
		ans *= n;
	return ans;
}

int toDec(const string& s,int type)
{
	int ans = 0;
	int len = s.length();
	for(int i = 0;i < len;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			ans += (s[i] - '0')*pow(type,len - i - 1);
		else if(s[i] >= 'A' && s[i] <= 'Z')
			ans += (s[i] - 'A' + 10)*pow(type,len - i - 1);
		else if(s[i] >= 'a' && s[i] <= 'z')
			ans += (s[i] - 'a' + 10)*pow(type,len - i - 1);
	}
	
	return ans;
}

void toOther(int n,int type,string& s)
{
	if(n)
	{
		toOther(n/type,type,s);
		s += n%type > 9 ? n%type - 10 + 'A' : n%type + '0';
	}
}



