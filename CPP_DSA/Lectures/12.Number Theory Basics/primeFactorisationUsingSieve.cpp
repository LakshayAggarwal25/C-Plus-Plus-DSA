#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

//Optimised sieve of eranthoses method to get a vector of prime numbers
vector<int> primeSieve(int *p, int n){
    //Here, 0 means not a prime and 1 means a prime number
    p[0]= p[1] = 0;
    p[2] = 1;
    for(int i = 3; i <= n; i+=2){
        // 2 is the only even prime number, hence we mark all the odd number as possible prime numbers
        p[i] = 1;
    }

    // in the following loop we will mark all the multiples of a prime number as not prime
    for(int i = 3; i<=n; i+=2){
        if(p[i]){
            for(int j = i*i; j<=n;j+=i){
                p[j] = 0;
            }
        }
    }

    vector<int> primes;
    primes.reserve(n);

    primes.push_back(2);
    for(int i = 3;i<=n;i++){
        if(p[i]){
            // if p[i] is marked as a prime number then we will push that number inside the vector
            primes.push_back(i);
        }
    }
    return primes;
}

vector<pair<int,int>> factorize(int m,vector<int> &primes){
    vector<pair<int,int>> factors;
    factors.clear(); // this will create an empty vector
    
    int i = 0;
    int p = primes[0];

    while(p*p<=m){
        int count = 0;
        if(m%p==0){
            while(m%p==0){
                count++;
                m=m/p;
            }
            factors.push_back(make_pair(p,count));
        }

        i++;
        p = primes[i]; 
    }
    if(m!=1){
        factors.push_back(make_pair(m,1));
    }
    return factors;

}

int main(){
    int n = 10000;
    int p[n+1] = {0};
    vector<int> primes = primeSieve(p,n);
    int tc ;
    cin>>tc;
    while(tc--){
        int no;
        cin>>no;
        vector<pair<int,int>> factors = factorize(no,primes);

        for(auto f : factors){
            cout<<f.first<<"^"<<f.second<<" = "<<(pow(f.first,f.second))<<endl;
        }
        cout<<endl;
    }
}