/*
Take as input str, a string. Write a recursive function which moves all ‘x’ from the string to its end.
E.g. for “abexexdexed” return “abeedeedxxx”.
Print the value returned

Input Format
Single line input containing a string

Constraints
Length of string <= 1000

Output Format
Single line displaying the string with all x's moved at the end

Sample Input
axbxc

Sample Output
abcxx

Explanation
All x's are moved to the end of string while the order of remaining characters remain the same.
*/

#include<iostream>
#include<cstring>

using namespace std;

void moveAllX(string &str, int idx){
    if(str[idx] == '\0'){
        return;
    }
    if(str[idx] == 'x'){
        int i = idx;
        while(str[i+1] !='\0'){
            str[i] = str[i+1];
            i++;
        }
        str[i] = 'x';
        moveAllX(str,idx+1);
    }
    else
        moveAllX(str,idx+1);
}

int main(){
    string str;
    cin>>str;
    moveAllX(str,0);
    cout<<str;
}