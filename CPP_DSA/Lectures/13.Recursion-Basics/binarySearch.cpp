#include<iostream>
#define rep(i,n) for(int x = i; x < n; x++)

using namespace std;
int binarySearch(int *a,int n, int high, int low,int key){
    int mid = (high+low)/2;
    //base case if element is found
    if(key==a[mid]){
        return mid;
    }
    //base case if element is not found
    if(high <= low){
        return -1;
    }

    //recursive call
    if(key > a[mid]){
        return binarySearch(a,n,high,mid+1,key);
    }
    return binarySearch(a,n,mid-1,low,key);

}

int main(){
    int n,k;
    cin>>n;
    int a[n];
    rep(0,n){
        cin>>a[x];
    }    
    cin>>k;
    int idx = binarySearch(a,n,n,0,k);
    if(idx==-1){
        cout<<"Key not found";
    }
    else{
        cout<<"Key found at "<<idx;
    }
}