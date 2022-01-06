#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

pair<int, int> partition(int arr[], int l, int r)
{
	int less = l - 1, more = r + 1;
	while (l < more)
	{
		int num = arr[r];
		if (arr[l] < num)
			swap(arr, ++less, l++);
		else if (arr[l] > num)
			swap(arr, --more, l);
		else
			l++;
	}
	return make_pair(less + 1, more - 1);
}

void quickSort(int arr[], int l, int r)
{
	if (l < r)
	{
		//swap(arr, l + (int)(rand()%(r - l + 1)), r);
		pair<int ,int> p = partition(arr, l, r);
		quickSort(arr, l, p.first - 1);
		quickSort(arr, p.second + 1, r);
	}
}

int main(void)
{

	int n = 0;
	cin >> n;

	int* arr = new int[n]();

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	delete arr;

	return 0;
}
