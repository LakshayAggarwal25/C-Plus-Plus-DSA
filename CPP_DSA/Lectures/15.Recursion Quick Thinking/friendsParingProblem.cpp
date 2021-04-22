/*
Problem -> Given N, friends who want to go to a party on bikes. Each guy can go a single, or as a couple.
Find the Number of ways in which N friends can go to a party
*/

#include<iostream>
using namespace std;

int ways(int n){
    if(n == 1 or n == 0){
        return 1;
    }

    return ((1*ways(n-1)) + (n-1)*ways(n-2));
}

int main(){
    int n;
    cin>>n;
    cout<<ways(n);
}