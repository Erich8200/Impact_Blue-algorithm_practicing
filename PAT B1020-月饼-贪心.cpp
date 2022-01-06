#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#define N 20

using namespace std;

class MoonCake
{
private:
	double stock;
	double totalPrice;
	double unitPrice;
public:
	MoonCake(double s,double p):stock(s),totalPrice(p){unitPrice = totalPrice/stock;}
	double getStock(){return stock;}
	double getUnitPrice(){return unitPrice;}
};

bool comp(MoonCake a,MoonCake b)
{
	return a.getUnitPrice() > b.getUnitPrice();
}

double greedy(vector<MoonCake> moonCakeList,double requirement)
{
	int i = 0;
	//按照单价从高到低排序月饼对象列表  
	double maxUnitPrice = 0;
	sort(moonCakeList.begin(),moonCakeList.end(),comp);
	
	double soldAmount = 0,profit = 0;
	while(soldAmount < requirement)
	{
		double residue = requirement - soldAmount;
		double unitPrice = moonCakeList[i].getUnitPrice();
		double stock = moonCakeList[i].getStock();
		
		if(stock > residue)
		{
			soldAmount += residue;
			profit += residue*unitPrice;
		}
		else
		{
			soldAmount += stock;
			profit += stock*unitPrice;
		}
		i++;
	}
	return profit;
}

int main(int argc, char** argv) 
{
	vector<MoonCake> moonCakeList;
	int num,i;
	double requirement,temp;
	
	double* mStock = new double[num]();
	double* mPrice = new double[num]();
	
	cin >> num >> requirement;
	
	for(i = 0;i < num;i++)
		cin >> mStock[i];
	
	for(i = 0;i < num;i++)
		cin >> mPrice[i];
		
	for(i = 0;i < num;i++)
	{
		MoonCake m(mStock[i],mPrice[i]);
		moonCakeList.push_back(m);
	}
	
	cout << greedy(moonCakeList,requirement) << endl;
	
	delete [] mPrice;
	delete [] mStock;
	
	return 0;
}
