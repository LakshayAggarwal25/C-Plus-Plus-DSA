/*
Pair Container : It is container that helps us bind two values as a single entity
*/
#include <iostream>
#include<cstring>
using namespace std;
int main() {
    // Pair
    pair<int,char> p;
    p.first = 10;
    p.second = 'B';

    //Another Way
    pair<int, char> p2(p);
    cout<<p2.first<<endl;
    cout<<p2.second<<endl;
    
    //make_pair method
    pair<int, string> p3 = make_pair(100,"Audi");
    cout<<p3.first<<" "<<p3.second<<endl;
    
    //Taking input
    int a,b;
    cin>>a>>b;
    pair<int, int> p4 = make_pair(a,b); 
    cout<<p4.first<<" "<<p4.second<<endl;

}
