#include<iostream>
using namespace std;
int power(int a, int n){
    //Base Case 
    if(n==1){
        return a;
    }
    return a * power(a,n-1);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<power(a,b);
}