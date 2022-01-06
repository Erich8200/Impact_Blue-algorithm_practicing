#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int dayCount[][12] = {{31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31}};

typedef struct {
	int year;
	int month;
	int day;
} Date;

bool isRun(int year)
{
	return (year % 4 == 0 && year % 100 != 0 && year % 400 == 0);
}

Date* F1Check(int num1, int num2, int num3)
{
	int year = 0, month = 0, day = 0;
	Date* date = NULL;
	if (num1 + 1900 >= 1960 && num1 + 1900 <= 2059)
		year = num1 + 1900;
	else if (num1 + 2000 >= 2000 && num1 + 2000 <= 2059)
		year = num1 + 2000;
		
	if (year == 0)
		return date;
		
	if (num2 >= 1 && num2 <= 12)
	{
		if (num3 <= dayCount[isRun(year)][num2] && num3 >= 1)
		{
			month = num2;
			day = num3;
		}
	}
	if (year && month && day)
	{
		date = new Date;
		date->year = year;
		date->month = month;
		date->day = day;
	}
	return date;
}

Date* F2Check(int num1, int num2, int num3)
{
	int year = 0, month = 0, day = 0;
	Date* date = NULL;
	if (num3 + 1900 >= 1960 && num3 + 1900 <= 2059)
		year = num3 + 1900;
	else if (num3 + 2000 >= 2000 && num3 + 2000 <= 2059)
		year = num3 + 2000;

	if (year == 0)
		return date;
		
	if (num1 >= 1 && num1 <= 12)
	{
		if (num2 <= dayCount[isRun(year)][num1] && num2 >= 1)
		{
			month = num1;
			day = num2;
		}
	}
	if (year && month && day)
	{
		date = new Date;
		date->year = year;
		date->month = month;
		date->day = day;
	}
	return date;
}

Date* F3Check(int num1, int num2, int num3)
{
	int year = 0, month = 0, day = 0;
	Date* date = NULL;
	if (num3 + 1900 >= 1960 && num3 + 1900 <= 2059)
		year = num3 + 1900;
	else if (num3 + 2000 >= 2000 && num3 + 2000 <= 2059)
		year = num3 + 2000;
		
	if (year == 0)
		return date;
		
	if (num2 >= 1 && num2 <= 12)
	{
		if (num1 <= dayCount[isRun(year)][num2] && num1 >= 1)
		{
			month = num2;
			day = num1;
		}
	}
	if (year && month && day)
	{
		date = new Date;
		date->year = year;
		date->month = month;
		date->day = day;
	}
	return date;
}

void printDate(Date* date)
{
	if (date)
		//cout << date->year << "-" << date->month << "-" << date->day << endl;
		printf("%d-%02d-%02d\n", date->year, date->month, date->day);
}

bool cmp(Date a, Date b)
{
	if (a.year < b.year)
		return true;
	else if (a.year == b.year)
	{
		if (a.month < b.month)
			return true;
		else if (a.month == b.month)
			return a.day < b.day;
		else
			return false;
	}
	else
		return false;
}

int main(void)
{
	freopen("0.txt", "r", stdin);
	string str;
	cin >> str;
	int num1 = (str[0] - '0')*10 + (str[1] - '0');
	int num2 = (str[3] - '0')*10 + (str[4] - '0');
	int num3 = (str[6] - '0')*10 + (str[7] - '0');
	Date* date = NULL;
	
	vector<Date> arr;
	
	date = F1Check(num1, num2, num3);
	if (date)
		arr.push_back(*date);
	delete date;
	date = F2Check(num1, num2, num3);
	if (date)
		arr.push_back(*date);
	delete date;
	date = F3Check(num1, num2, num3);
	if (date)
		arr.push_back(*date);
	delete date;
	
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < arr.size(); i++)
		printDate(&(arr[i]));
	
	fclose(stdin);
	return 0;
}
