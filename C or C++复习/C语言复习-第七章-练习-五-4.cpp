#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#define MAX 50

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Transpose(int* a,int* at,int row,int col)
{
	for(int i = 0;i < row;i++)
	{
		for(int j = 0;j < col;j++)
		{
			*(at + j*row + i) = *(a + i*row + j);	
		}
	}
	return;
}

void inputMatrix(int row,int col,int* a)
{
	for(int i = 0;i < row;i++)
	{
		for(int j = 0;j < col;j++)
		{
			cin >> *(a + i*row + j);	
		}
	}
}

void printMatrix(int row,int col,int* a)
{
	for(int i = 0;i < row;i++)
	{
		for(int j = 0;j < col;j++)
		{
			cout << *(a + i*row + j);	
			cout << ' ';
		}
		cout << '\n';
	}
}

int main(int argc, char** argv) 
{
	int row,col;
	cin >> row >> col;
	int* a = new int[row*col]();
	int* at = new int[row*col]();
	
	inputMatrix(row,col,a);
	Transpose(a,at,row,col);
	printMatrix(row,col,at);
	
	delete [] at;
	delete [] a;
	return 0;
}
