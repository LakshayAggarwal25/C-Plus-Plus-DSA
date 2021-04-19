/*
Problem - Unique number 2N+1
Given a list of numbers where every number occurs twice except one, find that unique number
*/
#include<iostream>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int no;
    int ans = 0;
    //Bitwise XOR Operator to solve
    // XOR of 2 same numbers is zero i.e 5^5 = 0
    for(int i = 0; i <n;i++){
        cin>>no;
        ans = ans^no;
    }
    cout<<ans<<endl;
}