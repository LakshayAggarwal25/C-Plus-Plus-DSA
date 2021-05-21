#include<iostream>
#include<list>
// list include a doubly linked list as a data structure 
using namespace std;

void print(list<string> List){
    for(auto x : List){
        cout<<x<<" -> ";
    }
    cout<<endl;
    return;
}

int main(){
    list<int> l;

    //Initialization 
    list<int> l1{1,2,3,4,5};

    //List of different types can be created as it is a template class
    list<string> l2{"apple","pineapple","mango"};
    l2.push_back("watermelon");
    l2.push_front("orange");
    print(l2);
    l2.sort();// this function will sort the list lexicographically
    print(l2);

    cout<<l2.front()<<endl; // gives the 1st element in the list
    cout<<l2.back()<<endl; // gives the last element in the list

    l2.pop_front(); // deletes the 1st element present in the list
    print(l2);

    l2.pop_back(); //deletes the last element present in the list
    print(l2);

    l2.push_front("kiwi"); // inserts the element in the starting of the list
    print(l2);

    l2.push_back("banana"); // inserts the element at the end of the list
    print(l2);

    l2.push_front("banana");
    print(l2);


    l2.remove("banana"); // removes all the nodes where the key is present
    print(l2);


}