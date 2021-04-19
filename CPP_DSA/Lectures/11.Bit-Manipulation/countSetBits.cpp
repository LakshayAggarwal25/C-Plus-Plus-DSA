/*
Given a number N, find number of set(1) bits in binary rep. of it
N = 13, Binary = 1101, Output = 3
*/
#include<iostream>
using namespace std;
int countSetBits(int n){
    int ans = 0;
    while(n>0){
        n = n & (n-1);
        ans++;  
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<countSetBits(n)<<endl;
    //Inbuilt function
    cout<<__builtin_popcount(n);
}
