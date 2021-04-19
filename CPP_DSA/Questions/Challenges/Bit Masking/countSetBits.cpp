/*
count number of 1s in binary representation of an integer

Input Format
Input N = Number of Test Cases, followed by N numbers

Constraints
Output Format
Number of Set Bits in each number each in a new line

Sample Input
3
5
4
15

Sample Output
2
1
4

Explanation
Convert Binary to Decimal first and then count number of 1's present in all digits.
*/
#include<iostream>
using namespace std;
int countSetBits(int n){
    int ans;
    while(n>0){
        n &= (n-1);
        ans++;    
    }
    return ans;
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        cout<<countSetBits(n)<<endl;
    }
}