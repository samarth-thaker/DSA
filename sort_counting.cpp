#include<iostream>
using namespace std;
void countingSort(int a[], int b[], int k){
    int c[k+1];
    for(int i=0; i<=k; i++){
        c[i] = 0;
    }
    for(int j = 1; j<=sizeof(a)/sizeof(a[0]); j++){
        c[a[j]] = c[a[j]] + 1;

}
for(int i = 1; i<=k; i++){
    c[i] = c[i] + c[i-1];
}
for(int j = sizeof(a)/sizeof(a[0]); j>=1; j-- ){
    b[c[a[j]]] = a[j];
    c[a[j]] = c[a[j]] - 1;
}
}

int main(){
    int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int brr[] = {0, 0,0 ,0 ,0 ,0, 0};
    countingSort(arr, brr, 6);
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }



}