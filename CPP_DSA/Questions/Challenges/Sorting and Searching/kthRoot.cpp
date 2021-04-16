/*
You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.

Input Format
First line contains number of test cases, T. Next T lines contains integers, n and k.

Constraints
1<=T<=10
1<=N<=10^15
1<=K<=10^4

Output Format
Output the integer x

Sample Input
2
10000 1
1000000000000000 10

Sample Output
10000
31

Explanation
For the first test case, for x=10000, 10000^1=10000=n
*/

/* Programing not for big number  n - 10^15*/
#include <iostream>
#include<cmath>
using namespace std;
long long int power(long long int x, long long int k){
    long long int ans = x;
    for(int i = 1; i < k ; i++){
        ans *= x;
    }
    return ans;
}
long long int findKthRoot(long long int n,long long int k){
    int s = 0;
    long long int e  = sqrt(n);
    long long int ans = -1;
    while(s<=e){
        long long int mid = (s+e)/2;
        long long int pw = power(mid,k);
        if(pw == n){
            return mid;
        }
        else if(pw < n){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}
int main() {
    int test_cases ;
    cin>>test_cases;
    while(test_cases--){
        long long int n;
        cin>>n;
        long long int k;
        cin>>k;
        if(k == 1){
            cout<<n<<endl;
        }
        else{
            cout<<findKthRoot(n,k)<<endl;
        }
    }
}
