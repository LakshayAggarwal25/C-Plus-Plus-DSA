#include<iostream>
using namespace std;
int powerExp(int a, int b){
    int ans = 1;
    while(b>0){
        int last_bit = b&1;
        if(last_bit){
            ans = ans*a;
        }
        a=a*a;
        b >>= 1;
    }

    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<"Ans = "<<powerExp(a,b);
}