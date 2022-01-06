#include<stdio.h>
#include<math.h>
#include<string.h>
#include<windows.h>

void HighPrecisionAdd(char* a,char* b,char* result)
{
	int length1 = strlen(a),length2 = strlen(b);
	char a_cpy[101] = {0},b_cpy[101] = {0};
	
	//将原字符串拷出加工而不影响原字符串
	strcpy(a_cpy,a);
	strcpy(b_cpy,b);

	//反转拷出的字符串
	strrev(a_cpy);
	strrev(b_cpy);

	int i,carry = 0;
	for(i = 0;i <= length1 || i <= length2;i++)//改成 <= 会出现前导0的问题，需要处理
	{
		//处理一个字符串已经加完而另一个没有的情况，将0 + 'x'改为'0' + 'x'
		if(a_cpy[i] == '\0')
			a_cpy[i] = '0';
		if(b_cpy[i] == '\0')
			b_cpy[i] = '0';

		//逐位求和
		result[i] = '0' + ((a_cpy[i] - '0')+ (b_cpy[i] - '0')+ carry )%10;
		carry = ((a_cpy[i] - '0') + (b_cpy[i] - '0') + carry)/10;
	}

	//去除前导0
	if(result[i-1] == '0')
		result[i-1] = 0;

	strrev(result);//反转答案
}

int main(void)
{
	char a[101] = {0},b[101] = {0},result[202] = {0};
	int i = 0;
	scanf("%s",a);
	getchar();
	scanf("%s",b);
	HighPrecisionAdd(a,b,result);
	printf("%s",result);

	system("pause");
	return 0;
}