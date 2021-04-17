#include <iostream>
#include<string>
using namespace std;
int main() {
    //String init
    string s0;
    string s1("hello");
    string s2 = "Hello World";
    string s3(s2);
    string s4 = s3;
    char a[] = {'a','b','c','d','\0'};
    string s5(a); 
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;

    if(s0.empty()){
        cout<<"s0 is an empty string"<<endl;
    }

    //Append
    s0.append("Appending strings in c++ using append functions ");
    cout<<s0<<endl;
    s0 += " '+=' also works";
    cout<<s0<<endl;

    //Remove
    cout<<s0.length()<<endl;
    s0.clear();
    cout<<s0.length()<<endl;

    //Compare two Strings
    s0 = "Apple";
    s1 = "Mango";
    cout<<s0.compare(s1)<<endl;

    //Find Substrings
    string s = "I want to have apple juice";
    int idx = s.find("apple");
    cout<<idx<<endl;

    //Remove a word from the string
    string word = "apple";
    int len = word.length();
    cout<<s<<endl;
    s.erase(idx,len+1);
    cout<<s<<endl;

}