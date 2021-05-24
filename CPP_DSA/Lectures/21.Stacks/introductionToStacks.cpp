#include <iostream>
#include <vector>
// Implementation of stack using vectors
using namespace std;

class Stack
{
private:
    vector<int> v;

public:
    void push(int data)
    {
        v.push_back(data);
    }
    bool isEmpty()
    {
        return v.size() == 0;
    }
    void pop()
    {
        if (!isEmpty())
        {
            v.pop_back();
        }
    }
    int top()
    {
        return v[v.size() - 1];
    }
};

int main()
{
    Stack s;

    for (size_t i = 0; i <5 ; i++)
    {
        s.push(i*i);
    }

    while (!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
        
}