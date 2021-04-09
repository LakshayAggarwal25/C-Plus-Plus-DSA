/*NOT WORKING*/
#include <iostream>
#include<conio.h>
using namespace std;
void spiralPrint(int a[][10], int m, int n){
    int startRow = 0;
    int startCol = 0;
    int endRow = m-1;
    int endCol = n-1;

    while(startRow<=endRow && startCol<=endCol){
        //first row
        for (int i = startCol; i<=endCol;i++){
            cout<<a[startRow][i]<<" ";
        }
        startRow++;

        for (int i = startRow; i<=endRow;i++){
            cout<<a[i][endCol]<<" ";
        }
        endCol--;

        //Bottom row
        if(endRow>startRow){
            for(int i = endCol; i>=startCol;i--){
                cout<<a[endRow][i]<<" ";
            }
            endRow--;
        }

        //start col
        if(endCol>startCol){
            for(int i = endRow; i >= startRow;i--){
                cout<<a[i][startCol]<<" ";
            }
            startCol++;
        }
    }
}
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
    spiralPrint(a, 5,3);
    getch();
    return 0;
}
