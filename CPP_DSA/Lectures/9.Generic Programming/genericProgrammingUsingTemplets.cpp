#include<iostream>
using namespace std;
// Linear search
int search(int a[],int n, int key){
    for(int i = 0;i<n;i++){
        if(key==a[i])
            return i;
    }
    return -1;
}

// Linear Search using template
template<typename T>
int search_temp(T arr[],int n,T key){
      for(int i = 0;i<n;i++){
        if(key==arr[i])
            return i;
    }
    return -1;
}
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    int key = 5;
    cout<<"Found at : "<<search(a,9,key)<<endl;
    cout<<"Found at : "<<search_temp(a,9,key)<<endl;
    float b[] = {1.1,1.2,1.3};
    cout<<"Found at : "<<search_temp(b,3,1.2f)<<endl;
    return 0;
}