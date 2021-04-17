#include<iostream>
#include<cstring>
#include<list>
using namespace std;
class book{
    public:
    string name;
    int price; 
    book(){

    }
    book(string name,int price){
        this->name = name;
        this->price = price;
    }
};
class bookCompare{
    public:
        bool operator()(book a, book b){
            cout<<"\nInside Compare function\n";
            if(a.name == b.name){
                return true;
            }
            return false;
        }
};

// Template + Iterators + Comparators
template <class ForwardIterator, class T,class Compare> // generic function to search for in a class with custom comparators
ForwardIterator search(ForwardIterator start, ForwardIterator end ,T key, Compare cmp){
    while(start!=end){
        if(cmp(*start,key)){
            return start;
        }
        start ++;
    }
    return end;
}
int main(){
    book b1("C++",100);         // old edition
    book b2("Python",130);
    book b3("Java",150);

    list<book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    book bookToFind("C",110); //  new edition
    bookCompare cmp;
    if(cmp(b1,bookToFind)){
        cout<<"same books!!"<<endl;
    }
    auto it = search(l.begin(),l.end(),bookToFind,cmp);
    // list<book> :: iterator it  = search(l.begin(),l.end(),bookToFind,cmp);
    if(it==l.end()){
        cout<<"Book not found"<<endl;
    }
    else{
        cout<<"Book Found"<<endl;
    }
} 