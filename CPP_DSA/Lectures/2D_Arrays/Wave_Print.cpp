#include <iostream>
using namespace std;
int main() {
    
    int a[10][10] = {0};
    int m,n;
    cin>>m>>n;
    int val = 1;
    for(int row = 0; row<m;row++){
        for(int col = 0; col<n;col++){
            a[row][col] = val;
            val = val+1;            
            cout<< a[row][col]<<" ";
        }
        cout<<endl;
    }

    //Wave Print
    for(int col = 0; col < n; col++){
        if(col%2==0){
            for(int row = 0; row < m; row++){
                cout<<a[row][col]<<" ";
            }    
        }
        else{
            for(int row = m - 1; row > -1; row--){
                cout<<a[row][col]<<" ";
            }    
        }
    }

}
