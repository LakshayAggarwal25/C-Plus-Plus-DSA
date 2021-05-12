/*
Given an array A, of N elements. Sort the array using quicksort algorithm.
(Note : Use randomized quicksort, otherwise worst case will not pass).

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
1 2 3 4 6 
*/

#include<iostream>
#include<cstring>

using namespace std;

int partation(int *arr, int start, int end){
    int pivot = arr[end];
    int i = start-1;
    int j = start;
    while(j < end){
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
    if( start >= end){
        return;
    }
    int p = partation(arr,start,end);
    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}