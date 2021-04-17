#include<iostream>
using namespace std;
int linearSearch(int arr[],int n, int key){
  for(int i = 0; i < n; i++){
    if(arr[i] == key)
        return i;
  }
  return -1;
}
int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int n;
    n = sizeof(a)/sizeof(int);
    cout<<"Key found at : "<<linearSearch(a,n,15);
    return 0;
}
