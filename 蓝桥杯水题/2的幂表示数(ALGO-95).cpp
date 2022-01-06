#include <stdio.h>
#include <string.h>
#include <malloc.h>

char binStrList[16][60] = { {'0',0},                                                                                     //0  
							{0},                                                                                         //1
							{'2',0},                                                                                     //2
							{'2', '+', '2','(','0',')',0},                                                               //3
							{'2','(','2',')',0},                                                                         //4
							{'2','(','2',')', '+', '2','(','0',')',0},                                                   //5
							{'2','(','2',')', '+', '2',0},                                                               //6
							{'2','(','2',')', '+', '2', '+', '2','(','0',')',0},                                         //7
							{'2','(','2', '+', '2','(','0',')',')',0},                                                   //8
							{'2','(','2', '+', '2','(','0',')',')','+','2','(','0',')',0 },                              //9
							{'2','(','2', '+', '2','(','0',')',')','+', '2',0},                                          //10
							{'2','(','2', '+', '2','(','0',')',')','+', '2','+','2','(','0',')',0},                      //11
							{'2','(','2', '+', '2','(','0',')',')','+', '2','(','2',')',0},                              //12
							{'2','(','2', '+', '2','(','0',')',')','+', '2','(','2',')', '+','2','(','0',')',0},		 //13
							{'2','(','2', '+', '2','(','0',')',')','+', '2','(','2',')', '+', '2',0},					 //14
							{'2','(','2', '+', '2','(','0',')',')','+', '2','(','4',')', '+', '2','+','2','(','0',')',0 }//15
							};

void DecToBin(int decNum, char* binNum, int* binNumLen)
{
	static int length = 0;
	if (decNum == 0) return;
	DecToBin(decNum / 2, binNum + 1, binNumLen);
	*binNum = '0' + decNum % 2;
	length += 1;
	*binNumLen = length;
}

void ParseBinNum(char* binNum, char (*binStrList)[60] , char* outputStr, int binNumLen)
{
	int i = 0,outIndex = 0;
	char* temp = (char*)calloc(60, sizeof(char));
	while (i < binNumLen)
	{
		if (binNum[i] == '1')
		{
			if (binNumLen - i - 1 == 1)
			{
				//printf("2");
				sprintf(temp, "2");
				strcat(outputStr, temp);
				memset(temp, 0, 60 * sizeof(char));
			}
			else
			{
				//printf("2(%s)", binStrList[binNumLen - i - 1]);
				sprintf(temp, "2(%s)", binStrList[binNumLen - i - 1]);
				strcat(outputStr, temp);
				memset(temp, 0, 60 * sizeof(char));
			}
			if (i != binNumLen - 1)
				strcat(outputStr, "+");
		}
		i += 1;
	}

	if ('+' == outputStr[strlen(outputStr) - 1])//Çå³ýÎ²²¿'+'
		outputStr[strlen(outputStr) - 1] = '\0';

	free(temp);

	return;
}

int main(void)
{
	int decNum = 0, binNumLen = 0;
	char* binNum = (char*)calloc(16, sizeof(char));
	char* outputStr = (char*)calloc(60, sizeof(char));
	scanf("%d", &decNum);
	char (*pBinStr)[60] = binStrList;

	DecToBin(decNum, binNum, &binNumLen);
	strrev(binNum);
	ParseBinNum(binNum, pBinStr, outputStr, binNumLen);
	printf("%s", outputStr);
	
	free(outputStr);
	free(binNum);
	return 0;
}