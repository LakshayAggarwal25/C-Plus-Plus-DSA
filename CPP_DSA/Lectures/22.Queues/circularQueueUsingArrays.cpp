#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front, rear, currentSize, maxSize;
    public:
    Queue(int defaultSize = 5){
        arr = new int[defaultSize];
        currentSize = 0;
        maxSize = defaultSize;
        front = 0;
        rear = maxSize-1;
    }
    bool isFull(){
        return currentSize == maxSize;
    }

    bool isEmpty(){
        return currentSize==0;
    }

    void push(int data){
        if(!isFull()){
            rear = (rear+1)%maxSize;
            arr[rear] = data;
            currentSize++;
        }
    }

    void pop(){
        if(!isEmpty()){
            front = (front + 1)%maxSize;
            currentSize--;
        }
    }

    int getFront(){
        if(!isEmpty()){
            return arr[front];
        }
    }

    ~Queue(){
        if(arr != NULL){
            delete [] arr;
            arr = NULL;
        }
    }
};

int main(){
    Queue q(50);
    for (size_t i = 1; i < 7; i++)
    {
        q.push(i);
    }

    q.pop();
    q.pop();
    q.push(7);

    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.pop();
    }
    
    return 0;
}