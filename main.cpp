#include <iostream>

using namespace std;

void insertionSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			int tmp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = tmp;
		}
	}
}

void shellSort()
{
 
}


int main()
{
	int size = 10;
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	insertionSort(arr, size);
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}