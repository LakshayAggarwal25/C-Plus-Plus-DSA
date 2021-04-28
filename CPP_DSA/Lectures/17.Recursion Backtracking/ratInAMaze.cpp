#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10], int sol[10][10], int i, int j, int m, int n){
    if(i==m and j==n){
        sol[m][n] = 1;
        for (int x = 0; x <= m; x++){
            for (int y = 0; y <= n; y++){
                cout<<sol[x][y]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //Rat should be inside the grid
    if(i>m or j>n){
        return false;
    }

    if(maze[i][j] == 'X'){
        return false;
    }

    //Assume solution exists through current cell
    sol[i][j] = 1;
    bool rightSuccess = ratInMaze(maze,sol,i,j+1,m,n);
    bool downSuccess = ratInMaze(maze,sol,i+1,j,m,n);

    //Backtracking
    sol[i][j] = 0;
    if(rightSuccess or downSuccess){
        return true;
    }
    return false;
}

int main(){
    char maze[10][10] = {"0000",
                         "00X0",                           
                         "000X",
                         "0X00"};

   int sol[10][10] = {0}; 
   int m,n;
   m=n=4;
   ratInMaze(maze,sol,0,0,m-1,n-1);
            
}