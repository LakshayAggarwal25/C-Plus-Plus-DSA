#include<iostream>
#include<climits>
using namespace std;

void countSort(int *arr,int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++){ 
        if(max < arr[i]){
            max = arr[i];
        }
    }

    int tempArrOfFrequencies[max+1] = {0};
    for (int i = 0; i < n; i++){
        tempArrOfFrequencies[arr[i]]++; 
    }
    
    int j = 0;
    for (int i = 0; i < max+1; i++){
        while(tempArrOfFrequencies[i] > 0){
            arr[j] = i;
            j++;
            tempArrOfFrequencies[i]--; 
        }
    }
}

int main(){
    int arr[] = {6,32,43,1,56,12,6,15,67,12,4};
    int n = sizeof(arr)/sizeof(int);
    countSort(arr,n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }    
}