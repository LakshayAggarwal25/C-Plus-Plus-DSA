#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    for (size_t i = 0; i < 5; i++)
    {
        s.push(i);
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}