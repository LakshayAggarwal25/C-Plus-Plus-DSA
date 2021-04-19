/*
Given two 32-bit numbers, N and M, and two bit poistions, i and j
Write a method to set all bits between i and j in N equal to M
Eg.
Input       
N = 512 i.e 1000000000
M = 21 i.e 10101 in bits
i = 2
j = 6
==> n = 1001010100 = 1108

Sol
1. Clear i to j bits from n
2. Perform m<<i
3. Ans =  n | m  
*/
#include<iostream>
using namespace std;
int clearRangeOfBits(int n, int i, int j){
    int rightSideOnes = -1<<(j+1);
    int leftSideOnes = (1<<i) - 1;
    int mask = rightSideOnes | leftSideOnes;
    return (n & mask);
}
int main(){
    int n,m,i,j;
    cin>>n>>m>>i>>j;
    n = clearRangeOfBits(n,i,j);
    m = (m<<i);
    n = (n|m);
    cout<<n;
}