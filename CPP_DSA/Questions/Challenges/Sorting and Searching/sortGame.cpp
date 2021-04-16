/*
Sanju needs your help! He gets a list of employees with their salary. The maximum salary is 100.

Sanju is supposed to arrange the list in such a manner that the list is sorted in decreasing order of salary. 
And if two employees have the same salary, they should be arranged in lexicographical manner such that the 
list contains only names of those employees having salary greater than or equal to a given number x.

Help Sanju prepare the same!

Input Format
On the first line of the standard input, there is an integer x. The next line contans integer N, denoting the number of employees. 
N lines follow, which contain a string and an integer, denoting the name of the employee and his salary.

Constraints
1 <= N <= 10^5 1 <= | Length of the name | <= 100 1 <= x, salary <= 100

Output Format
You must print the required list.

Sample Input
79
4
Eve 78
Bob 99
Suzy 86
Alice 86

Sample Output
Bob 99
Alice 86
Suzy 86
*/
#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void mergeSalaryToSting(string s[], int a[], int n){
    for(int i = 0; i<n;i++){
        s[i] = s[i] + " " +to_string(a[i]);
    }
}
int getSalary(string S1){
    
    //Using 'c_str()' to convert strings to char* then using strcpy to copy the value in local variables for further use in string tokenizer
    char s1[S1.length()];
    strcpy(s1,S1.c_str());

    // Using string tokenizer to get the salaries
    char *ptr1 = strtok(s1," ");
    ptr1 = strtok(NULL," ");

    // Using 'atoi' to convert char* to int 
    return atoi(ptr1);

}
bool myComp(string S1,string S2){

    int s1 = getSalary(S1);
    int s2 = getSalary(S2);
    if(s1 == s2){
        return S1[0] < S2[0];
    }
    return s1 > s2;

}
int main() {
    int x ;
    cin>>x;
    string s[10000];
    int n ;
    cin>>n;
    int a[10000];
    cin.ignore();
    for(int i = 0; i < n; i++){
        cin >> s[i];
        cin >> a[i];
    } 
    mergeSalaryToSting(s,a,n);
    sort(s,s+n,myComp);
    for(int i = 0; i < n; i++){
         if(getSalary(s[i])>=x){
             cout<<s[i]<<endl;
         }
    }
}