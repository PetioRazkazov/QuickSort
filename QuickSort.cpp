#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

//Избираме си пивот(последния елемент) и го слага където му е мястото като въртим цикъл ако елемент е по-малък от пивотния го слагаме отляво ако е по-голям ще стои вдясно. 
int pivotIndex(int arr[], int start, int end)
{
	int pivot = arr[end];
	int i = (start - 1); //индекс на по-малките елементи.
	for (int j = start; j <= end - 1; j++)
	{
		if (arr[j] <= pivot) 
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[end]);
	return (i + 1);
}

void quickSort(int arr[], int start, int end) 
{

	if (start < end)
	{
		int pivot = pivotIndex(arr, start, end);//след изпъляването нa това pivot е на правилното място в масива.
		quickSort(arr, start, pivot - 1);
		quickSort(arr, pivot + 1, end);
	}
}

void printArr(int arr[], int size) //Принтира Array
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	//Примерно
	int arr[] = {10,30,8,9,2,8};
	quickSort(arr, 0, 5);
	printArr(arr, 6);
    return 0;
}

