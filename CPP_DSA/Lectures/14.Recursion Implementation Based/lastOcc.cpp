#include<iostream>
#define rep(i,n) for(int x = i ; x < n; x++)
using namespace std;

int lastOcc(int *a,int n, int key){
    if(n==0){
        return -1;
    }

    int i = lastOcc(a+1,n-1,key);
    if(i==-1)
    {
        if(a[0] == key){
                return 0;
        }
        else 
        return -1;
    } 
    return i+1;

}
int main(){

    int n,k;
    cin>>n;
    int a[n];
    rep(0,n){
        cin>>a[x];
    }    
    cin>>k;

    cout<<lastOcc(a,n,k);
}