#include<iostream>
using namespace std;

int partition(int *arr, int start, int end){
    int i = start-1;
    int j = start;
    
    int pivot = arr[end];
    
    while(j <= end-1){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    } 
    swap(arr[i+1],arr[end]);
    
    return i+1;
}

void quickSort(int *arr, int start, int end){
    if(start>=end){
        return;
    }
    int p = partition(arr,start,end);

    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);
}

int main(){
    int arr[] = {6,32,43,1,56,12,6,15,67,12,4};
    int n = sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}