/*
Problem ->
Given a wall of size 4xN, and tiles of size (1,4) and (4,1)
in how many ways can you build the wall
*/
#include<iostream>
using namespace std;
int countNoOfWays(int n){
    if(n<=3)    return 1;

    return countNoOfWays(n-1) + countNoOfWays(n-4);
}

int main(){
    int n;
    cin>>n;
    cout<<countNoOfWays(n);
}