/*
Maximum Sum Submatrix in Row and Column Wise Sorted Matrix
In this question we can prepare a suffix sum submatrix and then traverse through the matrix to 
find the largest, and then that element will be the maximum sum submatrix
Suffix Sum Matrix 
If normal matrix is 
        0           1           2   
      |---------------------------|
  0   | a           b           c |
      |                           |  
  1   | d           e           f |
      |                           |        
  2   | g           h           i |
      |---------------------------|  

Suffix Sum matrix looks like    
        0           1               2   
      |-------------------------------------------------|
  0   | i+f+c+b+e+h+a+d+g   i+f+c+b+e+h     i+f+c       |
      |                                                 |  
  1   | d+e+f+h+i           e+f+h+i         i+f         |
      |                                                 |        
  2   | g+h+i               h+i             i           |
      |-------------------------------------------------|  
*/
#include <iostream>
#include<climits>
using namespace std;
void suffix(int a[][10], int m, int n){
    // Column Wise Addition
    for (int i = m - 1; i >= 0; i--){
        for (int j = n-2; j >= 0 ; j--){
                a[i][j] += a[i][j+1]; 
        }
    } 
    //Row Wise Addition
    for (int j = n - 1; j >= 0; j--){
        for (int i = m-2; i >= 0 ; i--){
                a[i][j] += a[i+1][j]; 
        }
    }
}
int maxSumSubmatrix(int a[][10], int m, int n){
    suffix(a,m,n);
    int res = INT_MIN;
    for(int i = 0 ; i < m; i++){
        for(int j = 0 ; j < n; j++){
                res = max(res, a[i][j]); 
        }
    }
    return res;
}
void input(int a[][10], int m, int n){
    for(int i = 0; i < m; i++ )
    {
        for(int j = 0; j < n; j++ )
        {   
            cin>>a[i][j];
        }
    }
}
void output(int a[][10], int m, int n){
    cout<<"-------------------"<<endl;
    for(int i = 0; i < m; i++ )
    {
        for(int j = 0; j < n; j++ )
        {   
            cout<<a[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<"-------------------"<<endl;
}
 int main() {
    int a[10][10], m, n;
    //input row and column 
    cin>>m>>n;
    input(a,m,n);
    output(a,m,n);
    cout<<maxSumSubmatrix(a,m,n);
}
