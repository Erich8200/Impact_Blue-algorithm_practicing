#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(int argc, char** argv)
{
	string ip;
	string regVal = "((\\d)|([1-9]\\d)|((1\\d\\d)|(2[0-4]\\d|25[0-5]))).((\\d)|([1-9]\\d)|((1\\d\\d)|(2[0-4]\\d|25[0-5]))).((\\d)|([1-9]\\d)|((1\\d\\d)|(2[0-4]\\d|25[0-5]))).((\\d)|([1-9]\\d)|((1\\d\\d)|(2[0-4]\\d|25[0-5])))";
	regex reg(regVal);
	while (cin >> ip)
	{
		if (regex_match(ip, reg))
			cout << 'Y' << endl;
		else
			cout << 'N' << endl;
	}
	system("pause");
	return 0;
}