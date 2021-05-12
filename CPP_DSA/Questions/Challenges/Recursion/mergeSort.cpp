/*
Given an array A, of N elements. Sort the array using mergesort algorithm.

Input Format
A single integer, N, denoting the number of elements in array. Next line contains N integers, denoting the elements of array.

Constraints
1<=N<=2*10^5
|Ai|<=10^9

Output Format
Print in a single line, N spaced integers, denoting the elements of array A in sorted order.

Sample Input
5
3 6 4 1 2

Sample Output
1 2 3 4 6 */

#include<iostream>
#include<cstring>

using namespace std;

void merge(int *arr, int start, int end){
    int i = start;
    int k = start;
    int mid = (start+end)/2;
    int j = mid+1;
    int temp[1000000];

    while(i<=mid && j <=end){
        if(arr[i]<arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    } 

    while(i<=mid)
        temp[k++] = arr[i++]; 

    while(j<=end)
        temp[k++] = arr[j++];

    for(int z = start; z <=end ; z++){
        arr[z] = temp[z];
    }
}

void mergeSort(int *arr, int start, int end){
    if(start>=end){
        return;
    }

    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);

    merge(arr,start,end);
}

int main(){
    int n;
    cin>>n;
    int arr[100000];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}