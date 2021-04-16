/*
Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which tests if the array is a palindrome and returns a Boolean value. Print the value returned.

Input Format
Enter a number N , add N more numbers

Constraints
None

Output Format
Display the Boolean result

Sample Input
4
1
2
2
1

Sample Output
true
*/
#include<iostream>
using namespace std;
bool isPalindrome(int *a, int n){
    int forward_itr = 0;
    int reverse_itr = n-1;
    while(forward_itr<=reverse_itr){
        if(a[forward_itr] == a[reverse_itr]){
            forward_itr++;
            reverse_itr--;
        }else{
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    if(isPalindrome(a,n)){
        cout<<"true";
    }else{
        cout<<"false";
    }
}