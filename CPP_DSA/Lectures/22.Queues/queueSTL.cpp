#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;

    for (size_t i = 0; i < 5; i++)
    {
        q.push(i*i);
    }

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
    
    
}