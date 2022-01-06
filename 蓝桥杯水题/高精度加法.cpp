#include<stdio.h>
#include<math.h>
#include<string.h>
#include<windows.h>

void HighPrecisionAdd(char* a,char* b,char* result)
{
	int length1 = strlen(a),length2 = strlen(b);
	char a_cpy[101] = {0},b_cpy[101] = {0};
	
	//��ԭ�ַ��������ӹ�����Ӱ��ԭ�ַ���
	strcpy(a_cpy,a);
	strcpy(b_cpy,b);

	//��ת�������ַ���
	strrev(a_cpy);
	strrev(b_cpy);

	int i,carry = 0;
	for(i = 0;i <= length1 || i <= length2;i++)//�ĳ� <= �����ǰ��0�����⣬��Ҫ����
	{
		//����һ���ַ����Ѿ��������һ��û�е��������0 + 'x'��Ϊ'0' + 'x'
		if(a_cpy[i] == '\0')
			a_cpy[i] = '0';
		if(b_cpy[i] == '\0')
			b_cpy[i] = '0';

		//��λ���
		result[i] = '0' + ((a_cpy[i] - '0')+ (b_cpy[i] - '0')+ carry )%10;
		carry = ((a_cpy[i] - '0') + (b_cpy[i] - '0') + carry)/10;
	}

	//ȥ��ǰ��0
	if(result[i-1] == '0')
		result[i-1] = 0;

	strrev(result);//��ת��
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