/*
Take as input str, a string. We are concerned with all the possible subsequences of str. E.g.

a. Write a recursive function which returns the count of subsequences for a given string. Print the value returned.

b. Write a recursive function which prints all possible subsequences for a 
“abcd” has following subsequences “”, “d”, “c”, “cd”, “b”, “bd”, “bc”, “bcd”, “a”, “ad”, “ac”, “acd”, “ab”, “abd”, “abc”, 
“abcd”.given string (void is the return type for function).
Note: Use cin for input for C++

Input Format
Enter a string

Constraints
None

Output Format
Print all the subsequences in a space separated manner and isplay the total no. of subsequences.

Sample Input
abcd

Sample Output
 d c cd b bd bc bcd a ad ac acd ab abd abc abcd 
16

Explanation
Print all possible subsequences of the given string.
*/
#include<iostream>
using namespace std;

int count = 0;

void generateSubsequences(char *in, char *out, int i, int j){
    if(in[i] == '\0'){
        out[j] ='\0';
        cout<<out<<" ";
        count++;
        return;
    }

    generateSubsequences(in,out,i+1,j);
    out[j] = in[i];
    generateSubsequences(in, out, i+1, j+1);
}

int main(){
    char input[100];
    cin>>input;
    char output[100];
    generateSubsequences(input,output,0,0);
    cout<<endl;
    cout<<count;
}