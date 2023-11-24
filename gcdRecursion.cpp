#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(b!=0){
        return gcd(b, a%b);
    }else{
        return a;
    }
}
int main(){
    int a = 45, b = 10;
    cout<<gcd(a, b);

}