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

//�����ַ���������� 
void bigInt::makeInt(char* str)
{
	int len = 0;
	len = this->len = strlen(str);//��Ҫstring.h 
	for(int i = 0;i < this->len;i++)
	{
		d[i] = str[len - i - 1] - '0';
	}
}

//������� 
void bigInt::showInt()
{
	for(int i = len - 1;i >= 0;i--)
		cout << d[i];
}

int bigInt::getLen()
{
	return this->len;
}

//�����Ƚ� 
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

//�߾��ȼӷ� 
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

//�߾��ȼ���
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
	
	//ͨ����С���ĳ���ȥ�����λ��0��ͬʱ���ٱ���һλ���λ
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0)
		 c.len--;
		 
	return c;
}

//�߾��ȳ˷���SJTUģ�� 
 bigInt operator*(const bigInt& a,const bigInt& b)
 {
 	bigInt c;
 	c.len = a.len + b.len;
 	int i,j;
 	
 	//���س˷���������ֵ����������������ŵ� 
 	for(i = 0;i < a.len;i++)
	 	for(j = 0;j < b.len;j++)
		 	c.d[i + j] += a.d[i]*b.d[j];
	
	//�����ȷ�Χ�ڵĽ�λ 
	for(i = 0;i < c.len - 1;i++)
	{
		c.d[i + 1] += c.d[i]/10;
		c.d[i] %= 10;	
	} 
	
	//���������ȷ�Χ�Ľ�λ 
	while(c.d[i])
	{
		c.d[i + 1] = c.d[i]/10;
		c.d[i] %= 10;
		i++;	
	}
	
	//��ȥǰ��0������len 
	while(i >= 1 && c.d[i] == 0) i--;
	c.len = i + 1;
	
 	return c;
 }
 
//�߾��ȳ�����SJTUģ�壬 ģ���ֹ�����ʵ�ָ��ӣ�ʹ�ü�������
bigInt operator/(const bigInt& a,const bigInt& b)
{
	int i,j;
	bigInt c,d;
	
	//ѭ��ִ�м��������ܼ�ȥ���ٸ����� 
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
