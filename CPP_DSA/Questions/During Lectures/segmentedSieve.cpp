/*
PRIME1 - Prime Generator
#number-theory
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). 
In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, 
test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
*/

#include<iostream>
#include<vector>

using namespace std;

const int N = 100000;

vector<int> primes;

int p[N] = {0}; // 0 is prime and 1 is not prime

void sieve(){
    for(int i = 2; i < N; i++){
        if(p[i]==0){
            primes.push_back(i);
            for(int j = i; j<N; j+=i){
                p[i]==1;
            }
        }
    }
}

int main(){
    sieve();
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>m>>n;

        bool segment[n-m+1];
        for(int i = 0; i<n-m+1;i++){
            segment[i] = 0;
        }

        for(auto x : primes){
            
            if(x*x > n){
                break;
            }

            int start = (m/x)*x;

            if(x>=m and x<=n)
                start = x*2;

            for(int i = start; i <=n ; i+=x){
                segment[i-m] = 1;
            }
        }

        for(int i = m;i<=n;i++){
            if(segment[i-m]==0 && i!=1){
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
}