#include<iostream>
#include<stack>

using namespace std;

bool isValid(char *s){
    stack<char> Stack;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        if(ch == '{')
        {
            Stack.push(ch);
        }
        else if( ch == '}'){
            if (Stack.empty() or Stack.top()!='{')
            {
                return false;
            }
            Stack.pop();
        }
    }
    return Stack.empty();    
}

int main(){
    char s[100] = "{-{}ae{as}{}}";
    cout<<isValid(s);
}