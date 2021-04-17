#include<iostream>
#include<vector>
using namespace std;
void outputVector(vector<int> a){
    cout<<endl;
    for(int x : a){
        cout<<x<<", ";
    }
    cout<<endl;
}
int main(){
    vector<int> d{1,2,3,10,14};
    // Push Back O(1) for most of the time
    d.push_back(16);
    outputVector(d);

    // Pop Back removes the last element O(1)
    d.pop_back();   
    outputVector(d);

    //Insert one element after x elements O(n)
    d.insert(d.begin() + 3,100); // this will insert 100 after the 3rd element
    outputVector(d);

    // Insert one element multiple times after x elements O(n)
    d.insert(d.begin() + 3, 4, 90); // this will insert 4 90's after the 3 element
    outputVector(d);

    // Erase element at (x+1)th index
    d.erase(d.begin()+2); // this will remove the element present at the 3rd index
    outputVector(d);

    // Erase multiple elements from the middle
    d.erase(d.begin()+1,d.begin()+5); // this will remove the elements present from 2nd index to 5th index
    outputVector(d);

    //Size
    cout<<"Size : "<<d.size()<<endl;
    cout<<"Underlying capacity : "<<d.capacity()<<endl;
  
    // to make the implementation efficient we avoid the shrink operation
    d.resize(8); // if the size is increasing then more memory will be allocated
    cout<<"Size : "<<d.size()<<endl;
    cout<<"Underlying capacity : "<<d.capacity()<<endl;
  
    // remove all the elements from the vector, doesn't delete the memory occupied by the array
    d.clear();
    cout<<"Size : "<<d.size()<<endl;
    cout<<"Underlying capacity : "<<d.capacity()<<endl;

    cout<<"----------------------------------------------"<<endl;
    //Reserve function
    // To avoid doubling, we will use reserve function
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int n0;
        cin>>n0;
        v.push_back(n0);
        cout<<"\nChaning Capacity : "<<v.capacity();
    }
    outputVector(v);
         
    
    cout<<"----------------------------------------------"<<endl;
    cout<<"If we use reverse function capacity will be fixed "<<endl;
    vector<int> v1;
    v1.reserve(100);
    int n1;
    cin>>n;
    for(int i = 0; i < n; i++){
        int n0;
        cin>>n0;
        v1.push_back(n0);
        cout<<"\nChaning Capacity : "<<v1.capacity();
    }
    outputVector(v1);
    return 0;

}