#include<iostream>
#include<cmath>

using namespace std;

void printBoard(int board[][9], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isThisNumberSafe(int board[][9], int row, int col, int n, int number){
    // Checking if the number is already present in the current row or column
    for(int i = 0; i < n; i++){
        if(board[i][col] == number || board[row][i] == number){
            return false;
        }
    }

    // Checking the current box
    int rootN = sqrt(n);
    int startOfThisBoxX = (row/rootN) * rootN;
    int startOfThisBoxY = (col/rootN) * rootN;

    for (int i = startOfThisBoxX; i < (startOfThisBoxX + rootN); i++){
        for (int j = startOfThisBoxY; j < (startOfThisBoxY + rootN); j++){
            if(board[i][j] == number){
                return false;
            }
        }       
    }
    
    return true;
}

bool sudokuSolver(int board[][9], int row, int column, int n){
    // Base case -> Sudoku Solved
    if(row == n){
        printBoard(board, n);
        return true;
    }

    // Column does not go out of bound
    if(column == n){
        return sudokuSolver(board,row+1,0,n);
    }

    // Checking if current cell empty
    if(board[row][column] != 0){
        return sudokuSolver(board,row,column+1,n);
    }

    //Recursive case ->
    for (int j = 1; j <= 9; j++)
    {
        if(isThisNumberSafe(board,row,column,n,j)){
            board[row][column] = j;
            bool isSudokuSolved = sudokuSolver(board,row,column+1,n);
            if(isSudokuSolved){
                return true;
            }
        }
    }
    board[row][column] = 0;
    return false;
}

int main(){
    int n = 9 ;
    int board[][9] = { 
        { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
        { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
        { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
        { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
        { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
        { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
        { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
        { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
        { 7, 4, 5, 0, 8, 6, 3, 1, 0 } 
        };
    sudokuSolver(board,0,0,n);
}