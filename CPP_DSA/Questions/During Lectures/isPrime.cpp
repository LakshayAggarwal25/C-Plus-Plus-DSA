/*
Take as input a number N, print "Prime" if it is prime if not Print "Not Prime".

Input Format
Constraints
2 < N <= 1000000000

Output Format

Sample Input
3

Sample Output
Prime

Explanation
The output is case specific
*/
#include<iostream>
using namespace std;
#define ll long long int

using namespace std;

int p[10000000] = {0};


void prime_seive(int *p){
    for(ll i = 3; i < 10000000; i+=2){
        p[i] = 1;
    }

    for(ll i =3 ; i < 10000000; i+=2){
        if(p[i] == 1){
            for( ll j = i*i; j <= 10000000; j += i ){
                p[j]=0;
            }
        }
    }
    p[2] = 1;
    p[0] = p[1] = 0;
}

int check(ll n){
    if(n < 10000000){
        return (p[n]==1)?1:0;
    }
    for(ll i = 0; p[i]*p[i]<=n; i++){
        if(n % p[i] == 0){
            return 0;
        }
    }
	return 1;
}
int main(){
    ll n;
    cin>>n;
	prime_seive(p);
    if(check(n)){
        cout<<"Prime";
    }
    else{
        cout<<"Not Prime";
    }

}