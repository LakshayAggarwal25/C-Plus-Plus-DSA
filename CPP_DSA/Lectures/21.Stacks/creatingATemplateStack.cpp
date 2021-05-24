#include <iostream>
#include <vector>
// Implementation of stack using vectors
using namespace std;
template<typename T>

class Stack
{
private:
    vector<T> v;

public:
    void push(T data)
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
    T top()
    {
        return v[v.size() - 1];
    }
};

int main()
{
    Stack<char> s;

    for (int i = 65; i <71 ; i++)
    {
        s.push(i);
    }

    while (!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
        
}