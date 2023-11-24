#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int key){
int s = 0, e = n-1;
int mid = s + (e-s)/2;
while(s<=e){
if(arr[mid]==key){
    return mid;
}else if(arr[mid]<key){
    s = mid + 1;
}else{
    e = mid - 1;
}
mid = s + (e-s)/2;
}return -1;
}
int main(){
int arr[5] = {1, 2, 3, 4,5};
int n = 5;
int r = binarySearch(arr, n, 4);
if(r!=-1){
    cout<<"Index of 4 is "<<r<<endl;
}else{
    cout<<"4 is not present";
}
}