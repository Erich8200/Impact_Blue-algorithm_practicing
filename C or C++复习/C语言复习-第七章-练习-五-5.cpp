#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool compA(string a,string b){return a < b;}
bool compD(string a,string b){return a > b;}

class Control
{
private:
	int option = 0;
public:
	void showMenu();
	void showResult(vector<string> strArray);
	void getOption();
	void Sort(vector<string>& strArray);
};

void Control::showMenu()
{
	cout <<"1.升序排列 2.降序排列 3.退出\n" << "请选择："; 
}

void Control::getOption()
{
	cin >> option;
}

void Control::Sort(vector<string>& strArray)
{
	switch(option)
	{
	case 1:
		sort(strArray.begin(),strArray.end(),compA);
		break;
	case 2:
		sort(strArray.begin(),strArray.end(),compD);
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "Invalid option" << endl;
	}
}

void Control::showResult(vector<string> strArray)
{
	for(int i = 0;i < strArray.size();i++)
		cout << strArray[i] << endl;
	cout << "\n";
}

int main(int argc, char** argv) 
{
	vector<string> strArray;
	string temp;
	int n;
	cout << "请输入字符串格个数：";
	cin >> n;
	cin.clear();
	cin.sync();   //或者用cin.ignore();
	for(int i = 0;i < n;i++)
	{
		cout << "请输入第" << i + 1 << "个字符：";
		getline(cin,temp);
		strArray.push_back(temp);
		
	}
	
	Control* c = new Control();
	while(true)
	{
		c->showMenu();
		c->getOption();
		c->Sort(strArray);
		c->showResult(strArray);		
	}
	return 0;
}
