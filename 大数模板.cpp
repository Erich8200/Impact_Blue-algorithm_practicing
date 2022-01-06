#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include "public.h"

using namespace std;

class bigInt{
private:
	int d[1000];
	int len;
public:
	bigInt(){
		memset(d,0,sizeof(d));
		len = 0;
	}
	void makeInt(char* str);
	static int compareBigInt(const bigInt& a,const bigInt& b);
	friend bigInt operator+(const bigInt& a,const bigInt& b);
	friend bigInt operator-(const bigInt& a,const bigInt& b);
	friend bigInt operator*(const bigInt& a,const bigInt& b);
	friend bigInt operator/(const bigInt& a,const bigInt& b);
	void showInt(); 
	int getLen();
};

//根据字符串构造大数 
void bigInt::makeInt(char* str)
{
	int len = 0;
	len = this->len = strlen(str);//需要string.h 
	for(int i = 0;i < this->len;i++)
	{
		d[i] = str[len - i - 1] - '0';
	}
}

//输出大数 
void bigInt::showInt()
{
	for(int i = len - 1;i >= 0;i--)
		cout << d[i];
}

int bigInt::getLen()
{
	return this->len;
}

//大数比较 
int bigInt::compareBigInt(const bigInt& a,const bigInt& b)
{
	if(a.len > b.len) return 1;
	else if(a.len < b.len) return -1;
	else
	{
		for(int i = a.len - 1;i >= 0;i--)
		{
			if(a.d[i] > b.d[i]) return 1;
			else if(a.d[i] < b.d[i]) return -1;
		}
		return 0;
	}
}

//高精度加法 
bigInt operator+(const bigInt& a,const bigInt& b)
{
	bigInt c;
	int carry = 0;
	for(int i = 0;i < a.len || i < b.len;i++)
	{
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp/10;
	}
	if(carry != 0)
		c.d[c.len++] = carry;
	return c;
}

//高精度减法
bigInt operator-(const bigInt& a,const bigInt& b) 
{
	bigInt c,temp = a;
	for(int i = 0;i < a.len || i < b.len;i++)
	{
		if(temp.d[i] < b.d[i])
		{
			temp.d[i] += 10;	
			temp.d[i+1] -= 1;
		}
		c.d[c.len++] = temp.d[i] - b.d[i];
	}
	
	//通过缩小数的长度去除最高位的0，同时至少保留一位最低位
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0)
		 c.len--;
		 
	return c;
}

//高精度乘法，SJTU模板 
 bigInt operator*(const bigInt& a,const bigInt& b)
 {
 	bigInt c;
 	c.len = a.len + b.len;
 	int i,j;
 	
 	//朴素乘法，利用数值数组是整数数组的优点 
 	for(i = 0;i < a.len;i++)
	 	for(j = 0;j < b.len;j++)
		 	c.d[i + j] += a.d[i]*b.d[j];
	
	//处理长度范围内的进位 
	for(i = 0;i < c.len - 1;i++)
	{
		c.d[i + 1] += c.d[i]/10;
		c.d[i] %= 10;	
	} 
	
	//处理超出长度范围的进位 
	while(c.d[i])
	{
		c.d[i + 1] = c.d[i]/10;
		c.d[i] %= 10;
		i++;	
	}
	
	//除去前导0并修正len 
	while(i >= 1 && c.d[i] == 0) i--;
	c.len = i + 1;
	
 	return c;
 }
 
//高精度除法，SJTU模板， 模拟手工操作实现复杂，使用减法代替
bigInt operator/(const bigInt& a,const bigInt& b)
{
	int i,j;
	bigInt c,d;
	
	//循环执行减法，看能减去多少个除数 
	for(i = a.len - 1;i >= 0;i--)
	{
		if(!(d.len == 1 && d.d[0] == 0))
		{
			for(j = d.len - 1;j >= 0;j--)
				d.d[j + 1] = d.d[j];
			++d.len;
		}
		
		d.d[0] = a.d[i];
		c.d[i] = 0;
		
		
		while((j = bigInt::compareBigInt(d,b)) >= 0)
		{
			d = d - b;
			c.d[i]++;
			if(j == 0) break;
		}
	}
	
	c.len = a.len;
	while(c.len >= 1 && c.d[c.len] == 0)
		c.len--;
	c.len++;
	
	return c;
}

int main(int argc, char** argv)
{
	
	return 0;
}
