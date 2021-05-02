#include<iostream>
using namespace std;
void selectionSort(int *arr, int n){
    for (int i = 0; i < n; i++){
        int minIdx = i;
        for (int j = i+1; j < n; j++){
            if(arr[minIdx] > arr[j]){
                minIdx = j;
            }
        }
        swap(arr[minIdx],arr[i]);
    }
    
}
int main(){
    int arr[] = {6,32,43,1,56,12,6,15,67,12,4};
    int n = sizeof(arr)/sizeof(int);
    selectionSort(arr,n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}