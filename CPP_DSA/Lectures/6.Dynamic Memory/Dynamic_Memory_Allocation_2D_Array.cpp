#include <iostream>
using namespace std;
int main() {
    
    int **arr;
    int r,c;
    cin>>r>>c;
    
    //Create an array of row heads
    arr = new int*[r];
    
    //Create an 2-D array
    for(int i = 0; i < r; i++){
        arr[i] = new int[c];
    }

    //take input and print the elements
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> arr[i][j]; 
            cout<< arr[i][j]<<" ";
        }
        cout<< endl;
    }
    delete []arr;

    return 0;
}