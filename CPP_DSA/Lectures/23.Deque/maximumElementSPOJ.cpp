// NOT WORKING

// Problem Statement : https://www.spoj.com/problems/ARRAYSUB/
#include<iostream>
#include<deque>

using namespace std;


int main(){
    int n, a[100000], k;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cin>>k;

    // We have to process first k elements separtely
    deque<int> q;
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() and a[i]>a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for(;i<n;i++){
        cout<<a[Q.front()]<<" ";
        //1.Remove the elements which are not the part of the window(Contraction)

        //2.Remove the elements which are not useful and are in window

        //3.Add the new element(Expansion)
    }





    return 0;
}