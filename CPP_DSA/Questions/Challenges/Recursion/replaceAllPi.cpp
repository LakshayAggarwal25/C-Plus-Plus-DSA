/*
Replace all occurrences of pi with 3.14

Input Format
Integer N, no of lines with one string per line

Constraints
0 < N < 1000
0 <= len(str) < 1000

Output Format
Output result one per line

Sample Input
3
xpix
xabpixx3.15x
xpipippixx

Sample Output
x3.14x
xab3.14xx3.15x
x3.143.14p3.14xx

Explanation
All occurrences of pi have been replaced with "3.14".
*/

#include<iostream>
using namespace std;

void replaceAllPi(string &str, int idx){
    //base case
    if(str[idx] == '\0' || str[idx + 1] == '\0'){
        return;
    }
    
    if(str[idx] == 'p' && str[idx+1] =='i'){
        int i = idx+2;
       
        while (str[i] != '\0'){
            i++;
        }

        while(i >= idx+2){
            str[i+2] = str[i];
            i--;
        }
        
        str[idx] = '3';
        str[idx+1] = '.';
        str[idx+2] = '1';
        str[idx+3] = '4';

        return replaceAllPi(str,idx+4);        
    }
    else
        return replaceAllPi(str,idx+1);
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string str;
        cin>>str;
        replaceAllPi(str,0);
        int i =0;
        while(str[i] != '\0')
            cout<<str[i++];
        cout<<endl;
    }
}