#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <iostream>

using namespace std;

void Disp(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		cout << a[i] << ", ";
	cout << a[n - 1] << endl;
}

void Add(int a[], int m, int b[], int n)
{
	int indexA = m, indexB = 0;
	for (indexB = 0; indexB <= n - 1; )
	{
		a[indexA++] = b[indexB++];
	}
}

int main()
{
	freopen("input0.txt", "r", stdin);
	int* a = NULL;
	int* b = NULL;
	int i = 0;
	int m, n;
	cin >> m >> n;
	a = new int[m + n];
	b = new int[n];
	for (i = 0; i < m; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
		cin >> b[i];

	int m1, n1;
	cin >> m1 >> n1;

	if (m1 >= m || n1 >= n)
		return 1;
	else if (m1 == 0 || n1 == 0)
		Disp(a, m);
	else
	{
		Add(a, m1, b, n1);
		Disp(a, m + n1 - m1);
	}

	delete a;
	delete b;
	fclose(stdin);
	return 0;
}