
#include<iostream>
#include<string>
#include<algorithm>
 
using namespace std; 
 
int main()
{
	string digits[10] = {"", "shi", "bai", "qian", "wan", "shi", "bai", "qian", "yi", "shi"};
	string number[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	
	string str;
	cin >> str;
	
	int len = str.length();
	for(int i = 0; i < len; i++)
	{
		int num = str[i] - '0';//得到相应的数字
		int nowdig = len - i - 1;	//倒序，得到正确的位数下标 
		  
		//0要做特殊处理，
		if(num == 0)
		{	
			//处理方式：连续几个0时只读最后一个0的读音。
			 //处理0的数问题。如果有下一个数， 且下一个数不是0 
			if(i + 1 < len && str[i + 1] != '0')
				cout << number[num] << " ";
				
			//处理0的位问题： 
			if((nowdig) % 4 == 0)	 //当为个，万, 亿位时，为标志位 
			{
				//如果标志位前面够4位，就取4位，否则取到最高位,由于是左闭右开，所以如果位数不够4时，应为i+1，才能取到i
				int count = min(i+1, 4);
				
				bool allzero = true;	//标志着是否全为0 
				for(int j = 0; j < count ; j++)
				{
					if(str[i - j] != '0')
					{
						allzero = false;
						break;	
					}  
					
				}
				
				if(allzero)
					continue;	
				else
					cout << digits[nowdig] << " ";
				
				
			}
		}
		//在每到需要读1的时候，遇到shi就不读 
		else if(num == 1 && (nowdig == 1 || nowdig == 5 || nowdig == 9))
		{
			cout << digits[nowdig] << " ";
		}
		else
		{	
			cout << number[num] << " " << digits[nowdig] << " ";				
		}
		
	}	
	
	cout << endl;
	
	return 0;
}













