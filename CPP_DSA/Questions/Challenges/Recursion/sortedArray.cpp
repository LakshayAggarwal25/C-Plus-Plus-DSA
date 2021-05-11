/*
Take as input N, the size of an integer array. Take one more input, which is a list of N integers separated by a space, and store 
that in an array. Write a recursive function which prints true if the array is sorted in Increasing Order, and false otherwise.

Input Format
N x y z

Constraints
1 < N < 1000
-10^9 < i < 10^9, where i is an element of the array

Output Format
true OR false

Sample Input
5
1 2 3 4 5

Sample Output
true
*/
#include<iostream>
bool checkSortedArray(int *arr, int n, int idx){
    if(idx==n){
        return true;
    }

    if(arr[idx-1] > arr[idx])
        return false;
    
    checkSortedArray(arr,n,idx+1);
}


int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        std::cin>>arr[i];
    }
    if(checkSortedArray(arr,n,1))
        std::cout<<"true";
    else
        std::cout<<"false";
    return 0;
}