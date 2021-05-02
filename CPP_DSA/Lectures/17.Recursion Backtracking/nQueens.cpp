#include<iostream>
#include<bitset>

using namespace std;

bitset<30> columns, leftDiagonal, rightDiagonal;

void solveNQueen(int n, int rowIdx, int board[20][20]){
    //Base Case
    if(rowIdx == n){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(board[i][j] == 1)
                    cout<<" Q ";
                else
                    cout<<" _ ";
            }
            cout<<endl;
        }
        cout<<"--------------------"<<endl;
        return;
    }
    for (int col = 0; col < n; col++){
        if(columns[col] == 0 && leftDiagonal[rowIdx+col] == 0 && rightDiagonal[rowIdx-col+n-1] == 0){ // checking if it is safe to place queen in current cell or not
            columns[col] = leftDiagonal[rowIdx+col] = rightDiagonal[rowIdx-col+n-1] = board[rowIdx][col] = 1;
            solveNQueen(n,rowIdx+1,board);
            columns[col] = leftDiagonal[rowIdx+col] = rightDiagonal[rowIdx-col+n-1] = board[rowIdx][col] = board[rowIdx][col] = 0; //backtracking
        }
    }
}
int main(){
    int n;
    cin>>n;
    int board[20][20] = {0};
    solveNQueen(n,0,board);
}