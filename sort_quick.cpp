// C++ code to implement quicksort

#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
	
	int pivot = arr[high];
	int count = 0;
	for(int i=0; i<=high; i++){
	    if(arr[i]<pivot){
	        count++;
	    }
	}
	int pivotindex = + count;
	swap(arr[pivotindex], arr[high]);
	int i=low,j=high;
	while(i<pivotindex&&j>pivotindex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotindex&&j>pivotindex){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
	}
	return pivotindex;
}


void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int N = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, N - 1);
	cout << "Sorted array: " << endl;
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	return 0;
}