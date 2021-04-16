/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

Input Format
The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

Constraints
Length of the arrays should be between 1 and 1000.

Output Format
Print all the pairs of numbers which sum to target. Print each pair in increasing order.

Sample Input
5
1
3
4
2
5
5

Sample Output
1 and 4
2 and 3

Explanation
Find any pair of elements in the array which has sum equal to target element and print them.
*/
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

// For a given sorted array, Find Pair of Elements that sum to K(given)
int main(){
    int a[100],n;
    cin>>n;
    for (int i = 0; i< n ; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int k;
    cin >>k;
    int i = 0,j = n-1;
    while(i<j){
        int current_sum = a[i] + a[j];
        if(current_sum>k){
            j--;
        }
        else if(current_sum<k){
            i++;
        }
        else if(current_sum = k){
            cout<<a[i] << " and "<<a[j]<<endl;
            i++;
            j--;
        }
    }
}