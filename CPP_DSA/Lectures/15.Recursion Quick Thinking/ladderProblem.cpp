/*
Problem -> Given N steps in ladder
in How many ways can a preson having the ability to take 1-k(i.e. 1,2,3,....,k) steps at a time, reach the end
*/
#include<iostream>
using namespace std;
int f(int n,int k){
    if(n == 0) return 1;
    if(n<0) return 0;
    int ans = 0;
    for (int i = 1; i <=k ; i++)
    {
        ans += f(n-i,k);
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<f(n,k);
}