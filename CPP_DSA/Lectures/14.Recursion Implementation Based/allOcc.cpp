#include<iostream>
#define rep(i,n) for(int x = i ; x < n; x++)
using namespace std;

int storeOcc(int *a, int i, int n, int key, int *out, int j){
    if(i == n){
        return j; 
    }
    if(a[i]==key){
        out[j] = i;
        return storeOcc(a,i+1,n,key,out,j+1);
    }
    return storeOcc(a,i+1,n,key,out,j);
}

void allOcc(int *a, int i, int n,int key){
    if(i == n){
        return;
    }
    if(a[i] == key){
        cout<<i<<", ";
    }
    allOcc(a,i+1,n,key);

}

int main(){
    int n,k;
    cin>>n;
    int a[n];
    rep(0,n){
        cin>>a[x];
    }    
    cin>>k;
    allOcc(a,0,n,k);
    cout<<"END"<<endl;
    
    int output[100];
    int cnt = storeOcc(a,0,n,k,output,0);

    rep(0,cnt){
        cout<<output[x]<<", ";
    }
    cout<<endl;
}