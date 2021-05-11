/*
Take as input S, a string. Write a function that removes all consecutive duplicates. 
Print the value returned.

Input Format
String

Constraints
A string of length between 1 to 1000

Output Format
String

Sample Input
aabccba

Sample Output
abcba

Explanation
For the given example, "aabccba", Consecutive Occurrence of a is 2, b is 1, and c is 2.

After removing all of the consecutive occurrences, the Final ans will be : - "abcba".
*/
#include<iostream>
using namespace std;

void formatString(string &str, int mainIdx ){
    //Initial case
    if(mainIdx == 0){
        return formatString(str,mainIdx+1);
    }

    //Base case
    if(str[mainIdx] == '\0'){
        return ;
    }

    //Next char is same as previous char
    if(str[mainIdx] == str[mainIdx-1]){
        int i = mainIdx;
        while( str[i] != '\0'){
            str[i] = str[i+1];
            i++;
        }
        return formatString(str,mainIdx);
    }

    //Next char is not same as previous char
    return formatString(str,mainIdx+1);
}

int main(){
    string str;
    cin>>str;
    formatString(str,0);
    int i = 0;
    while(str[i] != '\0')
        cout<<str[i++];
}