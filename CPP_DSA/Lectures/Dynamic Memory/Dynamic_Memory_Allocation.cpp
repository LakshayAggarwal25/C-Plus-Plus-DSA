#include <iostream>
using namespace std;
int main() {
    //Allocation + Deallocation is done by the compiler 
    int b[100];
    cout<<sizeof(b)<<endl;
    cout<<b<<endl; // Value in symbol table i.e its base address
    //Here, b can not be overwritten, b is a constant that is stored inside the symbol, hence 
    // b is part of read only memory

    //Dynamic Allocation
    int n;
    cin>>n;
    int *a = new int[n];
    cout<<sizeof(a)<<endl;
    cout<<a<<endl;// Variable a that is created inside the static memory that can be overwritten
    //a = new char[];


    for(int i = 0; i < n; i++){
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    //Deallocation / Free up the space in heap
    delete []a;
    return 0;
}