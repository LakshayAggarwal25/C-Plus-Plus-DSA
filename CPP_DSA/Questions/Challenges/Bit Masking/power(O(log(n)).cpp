/*
Take as input x and n, two numbers. 
Write a function to calculate x raise to power n. Target complexity is O(logn). 
NOTE: Try bitmasking approach.

Input Format
Enter the number N and its power P

Constraints
None

Output Format
Display N^P

Sample Input
2
3
Sample Output
8
*/
#include<iostream>
using namespace std;
int powerExp(int a, int b){
    int ans = 1;
    while(b>0){
        int last_bit = b&1;
        if(last_bit){
            ans = ans*a;
        }
        a=a*a;
        b >>= 1;
    }

    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<powerExp(a,b);
}