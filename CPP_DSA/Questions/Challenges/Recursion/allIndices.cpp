/*
Take as input N, the size of array. Take N more inputs and store that in an array. 
Take as input M, a number. Write a recursive function which returns an array containing indices of all items in the array 
which have value equal to M. Print all the values in the returned array.

Input Format
Enter a number N(size of the array) and add N more numbers to the array Enter number M to be searched in the array

Constraints
1 <= Size of array <= 10^5

Output Format
Display all the indices at which number M is found in a space separated manner

Sample Input
5
3
2
1
2
3
2

Sample Output
1 3

Explanation
2 is found at indices 1 and 3.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> findAllIdx(int *arr, int n, int idx, int key, vector<int> ans){
    if(idx == n){
        return ans;
    }

    if(arr[idx]== key){
        ans.push_back(idx);
        return findAllIdx(arr,n,idx +1,key,ans);
    }
    return findAllIdx(arr,n,idx +1,key,ans);
}

int main(){
    int n,key;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i <n ; i++){
        cin>>arr[i];
    }
    cin>>key;
    vector<int> ans;
    ans = findAllIdx(arr,n,0,key,ans);
    for (auto i : ans)
    {
        cout<<i<<" ";
    }
}