#include<iostream>
using namespace std;
void insertionSort(int arr[], int n, int i){
    if(i>n-1){
        return;
    }
    int temp;
    int key = i + 1;
    for(int j = i; j>=0;j--){
        if(arr[key]<arr[j]){
            temp = arr[j];
            arr[j] = arr[key];
            key = j;
        }else{
            break;
        }
        arr[j + 1] = temp;
    }
    insertionSort(arr, n, i+1);
}
int main(){
    int arr[] = { 10, 7, 8, 9, 1, 5 };
	int N = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, N, 0);
	cout << "Sorted array: " << endl;
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	return 0;
}