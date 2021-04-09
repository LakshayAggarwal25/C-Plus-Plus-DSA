/*
Given a 2D array of size N x N.Rotate the array 90 degrees anti-clockwise.

Input Format
First line contains a single integer N. Next N lines contain N space separated integers.

Sample Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Sample Output
4 8 12 16 
3 7 11 15 
2 6 10 14 
1 5 9 13 

*/
#include <iostream>
using namespace std;
void rotate_method1(int a[][100], int m){
   for(int i = m-1 ; i >-1 ; i--){
        for(int j = 0 ; j < m ; j++){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
}
void rotate_method2(int a[][100], int m){
    for(int row = 0; row < m; row++){
        int startcol = 0;
        int endcol = m-1;
        while(startcol<endcol){
            swap(a[row][startcol],a[row][endcol]);
            startcol++;
            endcol--;
        }
    }
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < m; j++){
            if(i<j){
                swap(a[i][j],a[j][i]);
            }
        }
    }    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int m;
    int a[100][100];
    cin>>m;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>a[i][j];
        }
    }
    rotate_method2(a, m);
}
