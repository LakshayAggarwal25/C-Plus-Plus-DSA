/*
Take as input N, the size of array. 
Take N more inputs and store that in an array. 
Take as input M, the size of second array and take M more inputs and store that in second array. 
Write a function that returns the sum of two arrays. Print the value returned.


Constraints
Length of Array should be between 1 and 1000.

Sample Input
4
1 0 2 9
5
3 4 5 6 7

Sample Output
3, 5, 5, 9, 6, END

Explanation
Sum of [1, 0, 2, 9] and [3, 4, 5, 6, 7] is [3, 5, 5, 9, 6] and the first digit represents carry over , if any (0 here ) .
*/ 

/*NOT WORKING*/
#include<iostream>
#include<cstring>
using namespace std;
int addArrays(int a[],int b[],int n,int m,int c[]){
    int k = n-1;
    int noeic = 0; // length of c
    int j = m-1;
    int carry = 0;
    for(int i = n-1;i > 0;i--){
        int sum = 0;
        if(j>-1){
           sum =  (a[i]+b[j]+carry)%10;
           carry = (a[i]+b[j]+carry)/10;
           c[k] = sum;
           j--;
           k--;
           noeic++;
        }
        else{
            break;
        }
    }
    return noeic;
}
int main(){
    int n,m,a[1000],b[1000],c[1000],k;
    cin >>n;
    for(int i = 0; i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i = 0; i<m;i++){
        cin>>b[i];
    }
    if(n>m){ // by this bigger array will always be passed as a
        k = addArrays(a,b,n,m,c);
    }
    else{
        k = addArrays(b,a,m,n,c);
    }
    for(int i = 0; i<k;i++){
        cout<<c[i]<<" ";
    }
}