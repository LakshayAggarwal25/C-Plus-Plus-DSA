// Problem -> Count Binary Strings of Length N, which have no consecutive ones
#include<iostream>
using namespace std;

int count(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    if(n==1) return 2;

    return count(n-1) + count(n-2);

}

int main(){
    int n;
    cin>>n;
    cout<<count(n);
}
