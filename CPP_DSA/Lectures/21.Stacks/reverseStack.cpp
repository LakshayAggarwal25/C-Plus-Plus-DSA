#include <iostream>
#include <stack>

using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s1)
{
    // helper stack
    stack<int> s2;
    int n = s1.size();
    for (size_t i = 0; i < n; i++)
    {
        // Pick the elemenet from the top of the stack and remove it from the stack
        int x = s1.top();
        s1.pop();

        //transfer n-1-i elements from stack s1 into s2
        transfer(s1, s2, n - i - 1);

        //insert the element x in s1
        s1.push(x);

        //transfer n-1-i elements from s2 to s1
        transfer(s2, s1, n - i - 1);
    }
}

void insertAtBottom(stack<int> &s1, int x){
    if(s1.empty()){
        s1.push(x);
        return;
    }

    int data = s1.top();
    s1.pop();
    insertAtBottom(s1,x);
    s1.push(data);
    return ;
}

void reverseStackRecursively(stack<int> &s1){
    if(s1.empty()){
        return;
    }

    int x = s1.top();
    s1.pop();
    reverseStackRecursively(s1);
    insertAtBottom(s1,x);
    return;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseStackRecursively(s);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}