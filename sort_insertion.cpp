#include<iostream>
using namespace std;
void insertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, n);
	cout<<"Sorted array:\n";
	for(int i=0; i<n; i++)
{
    cout<<arr[i]<<" ";
}	return 0;
}