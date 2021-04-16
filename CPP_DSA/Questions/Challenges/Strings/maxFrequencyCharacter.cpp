/*
Take as input S, a string. Write a function that returns the character with maximum frequency. Print the value returned.

Input Format
String

Constraints
A string of length between 1 to 1000.

Output Format
Character

Sample Input
aaabacb

Sample Output
a
Explanation
For the given input string, a appear 4 times. Hence, it is the most frequent character.
*/
#include<iostream>
using namespace std;
int main() {
	string s;
	int a[26] = {0};
	getline(cin,s);
	for(int i = 0; i < s.length(); i++){
		char ch = s[i];
		int x = ch;
        x-=97;
		a[x]++;
	}
    int max_freq = 0;
    int max_index = -1;
	for (int i = 0; i < 26; i++) {
        if(a[i]>max_freq){
            max_freq = a[i];
            max_index = i;
        }
	}
    char ch = max_index+97;
    cout<<ch<<endl;
}