/*
Take as input N, the size of array. Take N more inputs and store that in an array. 
Take as input a number M. Write a function which returns the index on which M is found in the array, in case M is not found -1 is returned. 
Print the value returned.You can assume that the array is sorted, but you’ve to optimize the finding process. 
For an array of size 1024, you can make 10 comparisons at maximum.

1.It reads a number N.
2.Take Another N numbers as input in Ascending Order and store them in an Array.
3.Take Another number M as input and find that number in Array.
4.If the number M is found, index of M is returned else -1 is returned.Print the number returned.

Input Format
Constraints
N cannot be Negative. Range of Numbers N and M can be between -1000000000 to 1000000000

Output Format
Sample Input
5
3
5
6
9
78
6

Sample Output
2

Explanation
Array = {3, 5, 6, 9, 78}, target number = 6 . Index of number 6 in the given array = 2. 
Write Binary search to find the number in given array as discuss in the class.
*/
#include <iostream>
using namespace std;
int binarySearch(int a[], int n, int key){
    int s = 0;
    int e = n-1;
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==key){
            ans = mid;
            return ans;
        }
        else if(a[mid]>key){
            e = mid - 1 ;
        }
        else{
            s = mid + 1 ;
        }
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    int a[100];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int key ;
    cin>>key;
    cout<<binarySearch(a,n,key);
}