#include<iostream>
using namespace std;

int power(int a, int n){ // O(n)
    if(n==1){
        return a;
    }
    return a * power(a,n-1);
}

int fastPower(int a, int n){ // O(log(n))
    if(n==0){
        return 1;
    }
    int smallerAns = fastPower(a,n/2);
    smallerAns *= smallerAns;
    if(n&1){
        return smallerAns * a;
    }
    return smallerAns;
}
int main(){
    int a,n ;
    cin>>a>>n;
    cout<<power(a,n)<<endl;
    cout<<fastPower(a,n)<<endl;
}