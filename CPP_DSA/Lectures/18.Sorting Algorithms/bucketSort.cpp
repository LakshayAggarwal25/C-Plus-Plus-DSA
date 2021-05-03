#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(float *arr, int n){
    vector<float> v[n];
    
    for (int i = 0; i < n; i++){
        int tempIdx = arr[i];
        v[tempIdx].push_back(arr[i]);
    }   

    for (int i = 0; i < n; i++){
        sort(v[i].begin(), v[i].end());
    }
    
    int idx = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < v[i].size(); j++)
        {
            arr[idx] = v[i][j];
            idx++;
        }
    }
}

int main(){
    float arr[] = {6.5,3.52,4.34,1.12,5.45,1.14,6,1.5,6.7,1.2,4};
    int n = sizeof(arr)/sizeof(int);
    bucketSort(arr,n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    } 
}