#include<iostream>
using namespace std;
void bubbleSort(int *arr, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    return;
}
int main(){
    int arr[] = {6,32,43,1,56,12,6,15,67,12,4};
    int n = sizeof(arr)/sizeof(int);
    bubbleSort(arr,n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}