/*
We are given an array containg n numbers. 
All the numbers are present twice except for two numbers which are present only once. 
Find the unique numbers in linear time without using any extra space.

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
n < 10^5

Output Format
Output a single line containing the unique numbers separated by space

Sample Input
4
3 1 2 1

Sample Output
2 3

Explanation
Smaller number comes before larger number
*/
#include<iostream>
using  namespace std;
int main(){
    int n;
    cin>>n;
    int resXOR = 0;
    int no;
    int arr[10000];
    for(int i = 0;i<n;i++){
        cin>>no;
        arr[i] = no;
        resXOR = resXOR^no;
    }
    int temp =resXOR;
    int pos = 0;
    while((temp & 1) != 1){
        pos++;
        temp = temp>>1;
    }


    //the 1st set bit in result xor
    int mask = 1<<pos ;


    int x = 0;
    int y = 0;

    for(int i = 0; i < n; i++){
        if((arr[i] & mask) >0){
            x = x ^ arr[i];
        }
    }
    y = x^resXOR;

    cout<<min(x,y)<<" "<<max(x,y);

}