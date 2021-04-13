#include <iostream>
#include<stdlib.h>
using namespace std;
int main() {
    int *xptr;
    int x = 10;
    xptr = &x;
    cout<<&x<<endl;
    cout<<xptr<<endl;
    cout<<*xptr<<endl;

    /*
    Dereference Any Address
    * is know as dereference operator
    int x = 10;
    int *xptr ;
    xptr = &x;

       2054
    |-------|           |-------|
    |   10  | <-------- |  2054 |
    |-------|           |-------|
        x                  xptr

    &Bucket  -> Address
    *Address -> Bucket

    */

}
