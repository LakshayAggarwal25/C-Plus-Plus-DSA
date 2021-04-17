#include<iostream>
#include<list>
using namespace std;
// Linear search
int search(int a[],int n, int key){
    for(int i = 0;i<n;i++){
        if(key==a[i])
            return i;
    }
    return -1;
}

// Linear Search using template
template<typename T>
int search_temp(T arr[],int n,T key){
      for(int i = 0;i<n;i++){
        if(key==arr[i])
            return i;
    }
    return -1;
}

// Linear Search Using Iterators
template<class ForwardIterator,class T>
ForwardIterator search_itr(ForwardIterator start, ForwardIterator end, T key){
    while(start!=end){
        if(*start == key){
            return start;
        }
        start ++;
    }
    return end;
}


int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    int key = 5;
    cout<<"Found at : "<<search(a,9,key)<<endl;
    cout<<"Found at : "<<search_temp(a,9,key)<<endl;
    float b[] = {1.1,1.2,1.3};
    cout<<"Found at : "<<search_temp(b,3,1.2f)<<endl;
    list<int> l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(5);
    l.push_back(6);
    l.push_back(8);
    auto it = search_itr(l.begin(),l.end(),50);
    if(it==l.end()){
        cout<<"not present";
    }
    else{
    cout<<*it<<endl;    
    }
    return 0;
}