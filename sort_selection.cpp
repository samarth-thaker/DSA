#include<iostream>
#include<stdlib.h>
using namespace std;

void selectionSort(int arr[], int n){
for(int i=0; i<n-1; i++){
    int minindex = i;
    for(int j=i+1; j<n; j++){
        if(arr[j]<arr[minindex]){
            minindex = j;
        }
    }
    if(minindex!=i){
    swap(arr[minindex], arr[i]);
    }
}
}
int main(){
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	cout<<"Sorted array:\n";
	for(int i=0; i<n; i++)
{
    cout<<arr[i]<<" ";
}	return 0;
}