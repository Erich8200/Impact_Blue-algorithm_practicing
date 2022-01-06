#include <iostream>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class MyString
{
public:
	char* getStr();
	int getLength();
	void setStr(char* p);
	MyString(char* s){ if(s != NULL) {str = s;length = strlen(s);}}
	MyString(){}
private:
	int length;
	char* str;
};

int MyString::getLength()
{
	return strlen(str);
}

char* MyString::getStr()
{
	return str;
}

void MyString::setStr(char* p)
{
	if(p != NULL)
	{
		this->str = p;
		this->length = strlen(p);
	}	
}

class Edit
{
public:
	static void deleteSpace(MyString &str);
};

class MyInput
{
public:
	int maxLen;
	void strInputWithSpace(char* inputStr);
	MyInput(int maxLen){
		this->maxLen = maxLen;
	};	
};

void MyInput::strInputWithSpace(char* inputStr)
{
	char c = 0;
	int i = 0;
	while((c = getchar()) != '\n' && i < maxLen)
	{
		inputStr[i] = c;
		i += 1;
	}
	inputStr[i] = 0;
}

void Edit::deleteSpace(MyString &str)
{
	 char* temp = new char[256]();
	 int lenthBak = str.getLength();
	 for(int i = 0,j = 0;i < lenthBak;i++)
	 {
	 	if((str.getStr())[i] != ' ')
	 	{
	 		temp[j++] = (str.getStr())[i];
		}
		(str.getStr())[i] = 0;
	 }
	 strcpy(str.getStr(),temp);
	 (str.getStr())[str.getLength()] = 0;
	 delete [] temp;
}

int main(int argc, char** argv) 
{
	char* str = new char[20];
	//cin >> str;
	MyInput myInput(20);
	myInput.strInputWithSpace(str);
	//MyString* myString = new MyString(str);
	MyString myString(str);
	Edit::deleteSpace(myString);
	cout << myString.getStr() << endl;
	//delete myString;
	delete [] str;
	return 0;
}
