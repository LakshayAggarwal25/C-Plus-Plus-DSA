/*
Nishant is a very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. 
Your task is to help Nishant Sort all the strings ( lexicographically ) but if a string is present completely as a prefix in another string, 
then string with longer length should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - 
then sorted order should have - Batman, bat.

Input Format
N(integer) followed by N strings.

Constraints
N<=1000

Output Format
N lines each containing one string.

Sample Input
3
bat
apple
batman

Sample Output
apple
batman
bat

Explanation
In mathematics, the lexicographic or lexicographical order (also known as lexical order, dictionary order, alphabetical order or 
lexicographic(al) product) is a generalization of the way words are alphabetically ordered based on the alphabetical order of their component letters.
*/
#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool my_compare(string a, string b)
{
    // Check if a string is present as prefix in another string, then compare the size of the string and return the larger size
    if (a.compare(0, b.size(), b) == 0|| b.compare(0, a.size(), a) == 0)
        return a.size() > b.size();

    // Else return lexicographically smallest string
    else
        return a < b;

}
int main() {
    int n;
    cin>>n;
    string s[1000];
    cin.ignore();
    for(int i = 0; i < n; i++){
        string input;
        getline(cin,input);
        s[i] = input;
    }
    sort(s,s+n,my_compare);
    for(int i = 0; i < n ; i++){
        cout<<s[i]<<endl;
    }
}