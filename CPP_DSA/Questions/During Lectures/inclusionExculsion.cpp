/*
After the release of Avengers, Ironman and Thor got into a fight and Ironman challenged 
Thor to find out the number of numbers between 1 and n which are divisible by any of the prime numbers less than 20.
Ironman being great at maths quickly answered the question but then Thor asked him to write a program for it.
Ironman however found it quite difficult as he did not wanted to write so many lines of code. 
He knows that you are smart and can code this up easily. 
Can you do it?

Input Format
The first line consists of number of test cases t. then follow t lines which consists of number n for each test case.

Constraints
1 <= test cases <= 10 1 <= n <= 10^18

Output Format
the answer to each test case each in different line

Sample Input
5
5
10
12
15
18

Sample Output
4
9
11
14
17

Explanation
for n = 5 2 and 4 are divisible by 2 and 3 is divisible by 3 and 5 by 5. hence ans = 4.

Logic Used to Solve
1. Figured out that there are 8 prime numbers less than 20 so there would be 2^8 - 1 subsets, -1 because we
   removed the null subset
2. Now we iterate over all the subsets
3. Initiallize denominator with = 1 and answer as 0
4. Consider the following : 

Array of primes < 20    [2, 3, 5, 7, 9, 11, 13, 17, 19]

           1    -->     [0, 0, 0, 0, 0,  0,  0,  0,  1]   -->   Since this subset has a set bit a position 
           .                                                    corresponding to 19 we will mutliply the denominator
           .                                                    by 19, and then find out all the numbers that are 
           .                                                    divisible by denominator in the n
           .                                                    i.e. = floorValue(n/denominator)
           .                                                    And since there are odd number of set bits we will 
           .                                                    add this in our result due to principle of inclusion
           .                                                    exclusion
           .
           .
          18    -->     [0, 0, 0, 0, 1,  0,  0,  1,  0]   -->   Since this subset has a set bit a position 
           .                                                    corresponding to 17 and 9 we will mutliply the 
           .                                                    denominator by 17 and 9, and then find out all  
           .                                                    the numbers that are divisible by the 
           .                                                    denominator in the n 
           .                                                    i.e. = floorValue(n/denominator)
           .                                                    And since there are even number of set bits we 
           .                                                    will subtract this from our result due to principle 
           .                                                    of inclusion exclusion 
           .
           .
     (2^8-1)    -->     [1, 1, 1, 1, 1,  1,  1,  1,  1]
 
*/
#include<iostream>
using namespace std;
#define ll long long int

ll primes[] = {2,3,5,7,11,13,17,19};

int main(){
    ll tc;
    cin>>tc;
    while(tc--){
        ll n;
        cin>>n;
        ll ans = 0;
        ll subsets = (1<<8)-1; // Since number of primes is less than 8, -1 is because we dont want 0 as a subset
                               // 1<<n = 2^n;
        
        // iterating over all the subsets
        for(ll i = 1; i <= subsets; i++){
            ll denom = 1LL;
            ll setBits = __builtin_popcount(i); // fcn used to find the number of set bits 
            for(ll j = 0; j<8 ; j++){
                if(i & (1<<j)){
                    denom =denom*primes[j];
                }
            }
            if(setBits & 1){     // (n & 1) == 1 if number is odd
                ans+= n/denom;
            }
            else{
                ans -= n/denom;
            }
        }
        cout<<ans<<endl;
    }
}