/*
Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

Input Format
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints
Both M and N are between 1 to 10.

Output Format
All M * N integers separated by commas with 'END' written in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44

Sample Output
11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END

Explanation
For spiral level anti-clockwise traversal, Go for first column-> last row ->last column-> first row 
and then do the same traversal for the remaining matrix .
*/
#include <iostream>
using namespace std;
void counterClockspiralPrint(int m, int n, int arr[10][10])
{
    int i, start_row = 0, start_col = 0;
  
    //  start_row - starting row index
    //    m - ending row index
    //    start_col - starting column index
    //    n - ending column index
    //    i - iterator 
  
    // initialize the count
    int count = 0;
  
    // total number of 
    // elements in matrix
    int total = m * n;
  
    while (start_row < m && start_col < n) 
    {
        if (count == total)
            break;
  
        // Print the first column 
        // from the remaining columns
        for (i = start_row; i < m; ++i)
        {
            cout << arr[i][start_col] << ", ";
            count++;
        }
        start_col++;
  
        if (count == total)
            break;
  
        // Print the last row from
        // the remaining rows 
        for (i = start_col; i < n; ++i) 
        {
            cout << arr[m - 1][i] << ", ";
            count++;
        }
        m--;
  
        if (count == total)
            break;
  
        // Print the last column 
        // from the remaining columns 
        if (start_row < m) 
        {
            for (i = m - 1; i >= start_row; --i) 
            {
                cout << arr[i][n - 1] << ", ";
                count++;
            }
            n--;
        }
  
        if (count == total)
            break;
  
        // Print the first row 
        // from the remaining rows 
        if (start_col < n) 
        {
            for (i = n - 1; i >= start_col; --i) 
            {
                cout << arr[start_row][i] << ", ";
                count++;
            }
            start_row++;
        }
    }
    cout<<"END";
}
int main(){
    int m,n,a[10][10];
    cin>>m>>n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }       
    }
    counterClockspiralPrint(m,n,a);
}
