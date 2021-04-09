#include <iostream>
using namespace std;
int main() {
    
    int a[5][3] = {0};
    int val = 1;
    for(int row = 0; row<5;row++){
        for(int col = 0; col<3;col++){
            a[row][col] = val;
            val = val+1;            
            cout<< a[row][col]<<" ";
        }
        cout<<endl;
    }
}
