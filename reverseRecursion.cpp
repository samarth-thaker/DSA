#include<iostream>
using namespace std;
int sum = 0, rem;
int revNum(int n){
    
    if(n){
        rem = n%10;
        sum = sum*10 + rem;
        revNum(n/10);
    }
    else{
        return sum;
    }
    return sum;
}
int main(){
    int num = 768;
    int rev = revNum(num);
    cout<<rev<<endl;
}