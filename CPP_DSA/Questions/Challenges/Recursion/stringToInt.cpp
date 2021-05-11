/*
Take as input str, a number in form of a string. 
Write a recursive function to convert the number in string form to number in integer form. 
E.g. for “1234” return 1234. Print the value returned.

Input Format
Enter a number in form of a String

Constraints
1 <= Length of String <= 10

Output Format
Print the number after converting it into integer

Sample Input
1234

Sample Output
1234

Explanation
Convert the string to int. Do not use any inbuilt functions.
*/

#include<iostream>
#include<cstring>
using namespace std;

int convertStringToInt(string str, int idx, int n){
    if(str[idx]=='\0'){
        return n/10;
    }
    n += (str[idx]-48);                                 // ascii for 0 -> 48, 1->49 and so on till 9 ->57
    return convertStringToInt(str,idx+1,n*10); 
}

int main(){
    string str;
    cin>>str;
    cout<<convertStringToInt(str, 0, 0);
}