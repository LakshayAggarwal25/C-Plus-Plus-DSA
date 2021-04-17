#include<iostream>
#include<vector>
using namespace std;
int main(){

    //Creating and Initializing  a vector
    vector<int> a;
    vector<int> b(5,10); // five int with value 10
    vector<int> c(b.begin(),b.end());
    vector<int> d{1,2,3,4,5};

    //Iterate over the vector
    for(int i = 0;i<c.size();i++){
        cout<<c[i]<<", ";
    }
    cout<<"END"<<endl;
    
    for(auto it = d.begin(); it != d.end();it++){ // we can replace auto by vector<int> :: iterator
        cout<<(*it)<<", ";
    }
    cout<<"END"<<endl;

    for(int x:b){
        cout<<x<<", ";
    }
    cout<<"END"<<endl;

    //More Functions
    vector<int> v;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int no;
        cin>>no;
        v.push_back(no); // adds an element to the end of the vector
    }

    for(int x : v){
        cout<<x<<", ";
    }
    cout<<"END"<<endl;

    // Understand at memory level, what are the differences vectors v and d since they both have 5 elements now 
    cout<<"V "<<endl;
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl; // size of underlying array
    cout<<v.max_size()<<endl; // maximum no. of elements a vector can hold in the worst case acc to available memory in the system
    
    cout<<"D "<<endl;
    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl; // size of underlying array
    cout<<d.max_size()<<endl; // maximum no. of elements a vector can hold in the worst case acc to available memory in the system

}