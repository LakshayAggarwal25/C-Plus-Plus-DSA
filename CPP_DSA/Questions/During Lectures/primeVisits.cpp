/*
PMO gives two random numbers a & b to the Prime Minister.
PM Modi wants to visit all countries between a and b (inclusive) , However due to shortage of time he can't visit each and every country , 
So PM Modi decides to visit only those countries,for which country number has two divisors. So your task is to find number of countries 
Mr. Modi will visit.

Input Format
The first line contains N , no of test cases. The next N lines contain two integers a and b denoting the range of country numbers.

Constraints
a<=1000000 & b<=1000000.
N<=1000

Output Format
Output contains N lines each containing an answer for the test case.

Sample Input
2
1 10
11 20

Sample Output
4
4

Explanation
PM Modi chooses countries with numbers 2,3,5 and 7 for the first testcase.
For the second testcase , he chooses countries with numbers 11,13,17 and 19.
*/
#include<iostream>
using namespace std;
#define ll long long int
#define MAX_RANGE 1000000
void primeSeive(int *p){
    
    for(ll i = 3; i < MAX_RANGE; i+=2){
        p[i] = 1;
    }

    for(ll i = 3; i < MAX_RANGE; i+=2){
        if(p[i]==1){
            for(ll j = i*i; j < MAX_RANGE ; j += i ){
                p[j] = 0;
            }
        }
    }

    p[2] = 1;
    p[0] = p[1] = 0;
}

int main(){
    int p[MAX_RANGE] = {0};
    primeSeive(p);
    int cSum[MAX_RANGE] = {0};
    for(ll i = 1; i < MAX_RANGE ;i++){
        cSum[i] = cSum[i-1] + p[i];
    }
    int tc;
    cin>>tc;
    while(tc--){
        int a,b;
        cin>>a>>b;
        cout<<(cSum[b]-cSum[a-1])<<endl;
    }
}