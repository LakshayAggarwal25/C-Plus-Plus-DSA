#include<iostream>
#define rep(i,n) for(int x = i ; x < n; x++)
using namespace std;

int firstOcc(int *a,int n, int key){
    if(n==0){
        return -1;
    }

    if(a[0] == key){
        return 0;
    }
    int i = firstOcc(a+1,n-1,key);
    if(i==-1){
        return -1;
    }
    return i + 1;

}
int main(){

    int n,k;
    cin>>n;
    int a[n];
    rep(0,n){
        cin>>a[x];
    }    
    cin>>k;

    cout<<firstOcc(a,n,k);
}