#include<iostream>
using namespace std;

int merge(int *a, int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[1000];
    int count = 0;
    while(i <= mid and j <= e){
        if(a[i]<=a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
            count += mid - i + 1;
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }

    for(int i = s;i<=e;i++){
        a[i] = temp[i];
    }
    return count;
}

int inversionCount(int *a, int s, int e){
    if(s >= e){
        return 0;
    }

    int mid = (s+e)/2;
    int inversionsInFirstHalf = inversionCount(a,s,mid);
    int inversionsInSecondHalf = inversionCount(a,mid+1,e);
    int crossInversions = merge(a,s,e);

    return inversionsInFirstHalf+inversionsInSecondHalf+crossInversions;
}

int main(){
    int arr[] = {1,5,2,6,3,0};
    int n = sizeof(arr)/sizeof(int);
    //divideArrays(arr,0,n-1);
    cout<<inversionCount(arr,0,n-1);
}