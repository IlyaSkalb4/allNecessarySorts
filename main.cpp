#include <iostream>
#include <windows.h>

using namespace std;

void output(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\n";
}

void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void combinedBubbleSort(int* arr, int size)
{
	bool bit;
	do
	{
		bit = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				bit = true;
			}
		}
	} while (bit);
}

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

void selectionSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			int tmp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = tmp;
		}
	}
}

void heapify(int* arr, int size, int index)
{
	int largest = index;
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (left < size && arr[left] > arr[largest])
	{
		largest = left;
	}
	if (right < size && arr[right] > arr[largest])
	{
		largest = right;
	}
	if (largest != index)
	{
		int tmp = arr[largest];
		arr[largest] = arr[index];
		arr[index] = tmp;
		heapify(arr, size, largest);
	}
}

void heapSort(int* arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(arr, size, i);
		Sleep(500);
		system("cls");
		output(arr, size);
	}
	for (int i = size - 1; i >= 0; i--)
	{
		int tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;
		heapify(arr, i, 0);
		Sleep(500);
		system("cls");
		output(arr, size);
	}
}

int main()
{
	int size = 30;
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
	output(arr, size);
	heapSort(arr, size);
	output(arr, size);
	return 0;
}