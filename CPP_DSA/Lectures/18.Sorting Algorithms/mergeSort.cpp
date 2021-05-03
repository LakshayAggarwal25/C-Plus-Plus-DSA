#include<iostream>
using namespace std;

void merge(int *arr, int start, int end){
    int mid = (start+end)/2;
    int i = start;
    int j = mid+1;
    int k = start;
    int tempArr[100];
    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            tempArr[k++] = arr[i++];
        }
        else{
            tempArr[k++] = arr[j++];
        }
    }
    while(i<=mid){
        tempArr[k++] = arr[i++];
    }
    while (j<=end){
        tempArr[k++] = arr[j++];
    }
    for(int i = start ; i <= end; i++){
        arr[i] = tempArr[i];
    }
}

void mergeSort(int *arr, int low, int high){
    if(low>=high){
        return;
    }

    int mid = (low+high)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    merge(arr,low,high);
}

int main(){
    int arr[] = {6,32,43,1,56,12,6,15,67,12,4};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}