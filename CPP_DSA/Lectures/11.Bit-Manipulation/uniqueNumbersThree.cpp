/*
We are given an array containg n numbers. 
All the numbers are present thrice except for one number which is only present once. 
Find the unique number. Only use - bitwise operators, and no extra space.

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
N < 10^5

Output Format
Output a single line containing the unique number

Sample Input
7
1 1 1 2 2 2 3

Sample Output
3

Explanation
3 is present only once
*/
#include<iostream>
using namespace std;
int main(){
    int count[64] = {0};
    int n;
    cin>>n;
    int n0;
    for(int i = 0; i < n; i++){
        cin>>n0;
        //Update the count array by extracting bits
        int j = 0;
        while(n0>0){
            int last_bit = (n0&1);
            count[j] += last_bit;
            j++;
            n0 = n0>>1;
        }
    }
    //iterate over the array and form the ans by converting 0 and 1 into a number
    int p = 1;
    int ans = 0;
    for(int i = 0; i <64;i++){
        count[i] %= 3;
        ans += (count[i]*p);
        p=p*2;
    }
    cout<<ans;
}