
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
		int num = str[i] - '0';//�õ���Ӧ������
		int nowdig = len - i - 1;	//���򣬵õ���ȷ��λ���±� 
		  
		//0Ҫ�����⴦��
		if(num == 0)
		{	
			//����ʽ����������0ʱֻ�����һ��0�Ķ�����
			 //����0�������⡣�������һ������ ����һ��������0 
			if(i + 1 < len && str[i + 1] != '0')
				cout << number[num] << " ";
				
			//����0��λ���⣺ 
			if((nowdig) % 4 == 0)	 //��Ϊ������, ��λʱ��Ϊ��־λ 
			{
				//�����־λǰ�湻4λ����ȡ4λ������ȡ�����λ,����������ҿ����������λ������4ʱ��ӦΪi+1������ȡ��i
				int count = min(i+1, 4);
				
				bool allzero = true;	//��־���Ƿ�ȫΪ0 
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
		//��ÿ����Ҫ��1��ʱ������shi�Ͳ��� 
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













