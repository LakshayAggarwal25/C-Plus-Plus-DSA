#include<iostream>
#include<climits>
using namespace std;
int largest(int a[],int n){
    int max = INT_MIN;
    for(int i = 0; i< n ; i++){
        if(a[i]>max)
            max = a[i];
    }
    return max;
}
int smallest(int a[],int n){
    int min = INT_MAX;
    for(int i = 0; i< n ; i++){
        if(a[i]<min)
            min = a[i];
    }
    return min;
}

int main(){
    int a[100],n;
    cin>>n;
    for (int i = 0; i< n ; i++){
        cin>>a[i];
    }

    cout<<"\nLargest : "<<largest(a,n);
    cout<<"\nSmallest : "<<smallest(a,n);
    return 0;
}
