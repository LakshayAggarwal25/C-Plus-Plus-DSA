/*
Take as input str, a string. Write a recursive function which returns a new string in which all duplicate consecutive characters 
are separated by a ‘ * ’. E.g. for “hello” return “hel*lo”. Print the value returned

Input Format
Enter a String

Constraints
1<= Length of string <= 10^4

Output Format
Display the resulting string (i.e after inserting (*) b/w all the duplicate characters)

Sample Input
hello

Sample Output
hel*lo

Explanation
We insert a "*" between the two consecutive 'l' .
*/

#include<iostream>
#include<cstring>
using namespace std;

string ans;

void formatString(string str, int mainIdx , int ansIdx){
    //Initial case
    if(ansIdx == 0 && mainIdx == 0){
        ans[ansIdx] = str[mainIdx];
        return formatString(str,mainIdx+1,ansIdx+1);
    }

    //Base case
    if(str[mainIdx] == '\0'){
        ans[ansIdx] = '\0';
        return ;
    }

    //Next char is same as previous char
    if(str[mainIdx] == str[mainIdx-1]){
        ans[ansIdx] = '*';
        ansIdx++;
        ans[ansIdx] = str[mainIdx];
        return formatString(str,mainIdx+1,ansIdx+1);
    }

    //Next char is not same as previous char
        ans[ansIdx] = str[mainIdx];
        return formatString(str,mainIdx+1,ansIdx+1);
}

int main()
{
    string str;
    cin>>str;
    formatString(str,0,0);
    int i = 0;
    while(ans[i] != '\0')
        cout<<ans[i++];
    return 0;
}
