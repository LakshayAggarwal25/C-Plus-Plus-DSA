#include<iostream>
#include<stack>

using namespace std;

void stockSpan(int price[], int n ,int span[] ){
    stack<int> s;
    s.push(0);

    span[0] = 1;
    for (size_t i = 1; i < n; i++)
    {
        int currentPrice = price[i];
        while(!s.empty() and price[s.top()] <= currentPrice){
            s.pop();
        }

        if(!s.empty()){
        int prevHigh = s.top();
        span[i] =  i - prevHigh;
        }
        else{
            span[i] = i+1;
        }

        s.push(i);
    }
    return;
}

int main(){
    int prices[] = {100,80,60,70,60,75,85};
    int n = sizeof(prices)/sizeof(prices[0]);
    int span[n] = {0};

    stockSpan(prices,n,span);

    for(auto x : span){
        cout<<x<<" ";
    }

}