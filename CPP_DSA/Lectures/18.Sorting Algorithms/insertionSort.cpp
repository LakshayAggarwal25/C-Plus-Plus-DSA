#include<iostream>
using namespace std;
void insertionSort(int *arr, int n){
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
}
int main(){
    int arr[] = {6,32,43,1,56,12,6,15,67,12,4};
    int n = sizeof(arr)/sizeof(int);
    insertionSort(arr,n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}