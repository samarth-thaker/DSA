#include<iostream>
using namespace std;
void merge(int arr[], int s, int e){
    int mid = s + (e-s)/2;
    int l1= mid - s + 1;
    int l2 = e- mid;
    int *first = new int(l1);
    int *second = new int(l2);
    int mai = s;
    for(int i=0; i<l1; i++){
        first[i] = arr[mai++];
    }int m = mid + 1;
    for(int i=0; i<l2; i++){
        second[i] = arr[mai++];
    }int index1 = 0, index2 = 0; mai = s;
    while(index1<l1 && index2<l2){
        if(first[index1]<second[index2]){
            arr[mai++] = first[index1++];
        }else{
            arr[mai++] = second[index2++];
        }
    }while(index1<l1){
        arr[mai++] = first[index1++];

    }while(index2<l2){
        arr[mai++] = second[index2++];
    }

}void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = s + (e-s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);

}
int main(){
    int arr[5] = {22, 5, 6, 1, 9};
    int n = 5;
    mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}