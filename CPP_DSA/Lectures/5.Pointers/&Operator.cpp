#include<iostream>
using namespace std;
int main()
{
    int n = 10;
    // & gives the address of a variable 
    cout<<&n<<endl;
    float y = 5.5;
    cout<<&y<<endl;
    //It doesn't work for character variables
    char c = 'A';
    cout<<&c<<endl;
    //Explicit Typecasting from char* to void*
    cout<<(void*)&c<<endl;
}
