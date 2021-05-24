#include<iostream>
#include<list>
#include<forward_list>

using namespace std;

class Queue{
    int currentSize;
    list<int> l;

    public:
    Queue(){
        currentSize = 0;
    }

    bool isEmpty(){
        return currentSize == 0;
    }

    void push(int data){
        l.push_back(data);
        currentSize++;
    }

    void pop(){
        if(!isEmpty()){
            l.pop_front();
            currentSize--;
        }
    }

    int getFront(){
        return l.front();
    }

};

int main(){

    Queue q;
    for (size_t i = 0; i < 10; i++)
    {
        q.push(i);
    }
    
    while (!q.isEmpty())
    {
        cout<<q.getFront()<<" ";
        q.pop();
    }
    

    return 0;
}