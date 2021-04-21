#include<iostream>
#define rep(i,n) for(int x = i; x < n ; x++)
using namespace std;
int linearSearch(int *a, int idx, int n, int key){
    //base case
    if(idx==n){
        return -1; // key not found
    }
    if(a[idx] == key){
        return idx;
    }

    linearSearch(a,idx+1,n,key);   

}
int main(){
    int n,k;
    cin>>n;
    int a[n];
    rep(0,n){
        cin>>a[x];
    }    
    cin>>k;
    cout<<linearSearch(a,0,n,k);
}