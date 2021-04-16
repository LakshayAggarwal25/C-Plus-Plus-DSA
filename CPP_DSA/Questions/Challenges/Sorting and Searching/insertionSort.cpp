/*
Given an array A of size N , write a function that implements insertion sort on the array. Print the elements of sorted array.

Input Format
First line contains a single integer N denoting the size of the array. 
Next line contains N space seperated integers where ith integer is the ith element of the array.

Constraints
1 <= N <= 1000
|Ai| <= 1000000

Output Format
Output N space seperated integers of the sorted array in a single line.

Sample Input
4
3 4 2 1

Sample Output
1 2 3 4

Explanation
For each test case, write insertion sort to sort the array.
*/
#include<iostream>
using namespace std;
void insertionSort(int a[], int n){
    for (int i = 1; i <= n-1 ; i++){
      int e = a[i];
      int j = i-1;
      while(j>=0 && a[j]>e){
        a[j+1] = a[j];
        j=j-1;
      }
      a[j+1] = e;
    }
}
int main(){
        int a[1000];
        int n;
        cin>>n;
        for (int i = 0; i< n ; i++){
            cin>>a[i];
        }
        insertionSort(a,n);
        for (int i = 0; i< n ; i++){
            cout<<a[i]<<" ";
        }
}