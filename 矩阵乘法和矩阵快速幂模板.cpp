#include <iostream>
#include <stdio.h>
#define N 100

using namespace std;

typedef struct Mat {
	int row = 0, col = 0;
	long long a[N][N];
	void clearA(){
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				a[i][j] = 0LL;
	}
	Mat(){
		clearA(); //必须，不能省略，否则优化后会造成一些奇怪的后果
	}
	Mat(int row, int col){
		clearA(); //必须，不能省略，否则优化后会造成一些奇怪的后果
		this->row = row;
		this->col = col;
	}
	void show(){
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				printf("%ld ", a[i][j]);
		printf("\n");
	}
} Mat;

Mat operator * (const Mat a, const Mat b)
{
	Mat ans(a.row, b.col);
	for (int i = 0; i < a.row; i++)
	{
		for (int j = 0; j < b.col; j++)
		{
			int x = 0;
			for (int k = 0; k < a.col; k++)
				x += a.a[i][k] * b.a[k][j];
			ans.a[i][j] = x;
		}
	}
	return ans;
}

Mat getE(int n)
{
	Mat e(n, n);
	for (int i = 0; i < n; i++)
		e.a[i][i] = 1;
	return e;
}

Mat matFastPow(Mat a, int b)
{
	Mat ans = getE(a.row);
	while (b)
	{
		if (b&1) ans = ans*a;
		a = a*a;
		b >>= 1;
	}
	return ans;
}

int main()
{
	int n = 0;
	Mat ans;
	Mat a(2, 2);
	a.a[0][0] = 0LL;
	a.a[0][1] = 1LL;
	a.a[1][0] = 2LL;
	a.a[1][1] = 3LL;
	
	while (cin >> n)
	{
		ans = matFastPow(a, n);
		ans.show();
	}
	
	return 0;
}

