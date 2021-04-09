#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[10] = {'a','b','c'};
    cout<<a<<endl;

    char s[10];
    cout<<"Enter a word : ";
    cin >> s;
    cout <<s;

    char s1[100];
    cout<<"\nEnter a sentence : ";
    cin.ignore();
    cin.getline(s1, 100);
    cout<<s1;


    return 0;
}
