/*
!!!!!       Method 2 not working        !!!!!
Sum of all submatrices of a given Matrix
Explaination     
        1,1
        1,1

    Consists of 4 matrices : (1x1)  => 4 * 1 = 4
    Consists of 2 matrices : (2x1)  => 2 * 2 = 4
    Consists of 2 matrices : (1x2)  => 2 * 2 = 4
    Consists of 1 matrices : (4x4)  => 1 * 4 = 4
                                             = 16 

Method 1 : Brute Force
Find all the possible Submatrices then add their sum
Time Complexity n^6

__________________________________________________________________________________


Method 2 : Prefix Sum Matrix
If normal matrix is 
        0           1           2   
      |---------------------------|
  0   | a           b           c |
      |                           |  
  1   | d           e           f |
      |                           |        
  2   | g           h           i |
      |---------------------------|  

Prefix Sum matrix looks like    
        0           1               2   
      |-------------------------------------------------|
  0   | a           a+b             a+b+c               |
      |                                                 |  
  1   | d+a         d+e+a+b         d+e+f+a+b+c         |
      |                                                 |        
  2   | g+d+a       g+h+d+e+a+b     g+h+i+d+e+f+a+b+c   |
      |-------------------------------------------------|  

Now, if we consider a prefix sum matrix of 6x6
         0         1       2       3       4       5  
  0    |  0,0  |---------|-------|-------|-------|-------|
  1    |-------| i-1,j-1 |-------|-------| i-1,y |-------|
  2    |-------|---------|  i,j  |-------|-------|-------|
  3    |-------|---------|-------|-------|-------|-------|
  4    |-------|  x,j-1  |-------|-------|  x,y  |-------|
  5    |-------|---------|-------|-------|-------|-------|  

    if we want to find the sum of submatrix (i,j) -> (x,y)
    Since this is a prefix sum matrix then value at (x,y) already contains 
    sum of submatrix (0,0) -> (x,y)
    To find the sum of submatrix (i,j) -> (x,y)
    We need to subtract the sum of matrices (0,0) -> (i-1,y) and (0,0) -> (x,j-1)
    In this case since the sum of matrix (0,0) -> (i-1,j-1) is being subtracted twice we need to add it once 
    Therefore, Sum of submatix (i,j) -> (x,y) = Valueof{(x,y) - (i-1,y) - (x,j-1) + (i-1,j-1)}
    Let value of (x,y) = m
    Let value of (i-1,y) = u
    Let value of (x,j-1) = l
    Let value of (i-1,j-1) = e

__________________________________________________________________________________


Method 3 :
Every element will be a part of more than 1 sub matrix, In each submatrix the element will be 
contributing for the sum. 
So if we can find the
Contribution of each element in the final sum(element * no . of submatrices it is part of)
And then, sum of the contributions of all elements will be sum of all the submatrices 

*/

#include <iostream>
using namespace std;
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
void prefix(int a[][10], int pre[][10],int m,int n){
    int i=0,j=0;
    while(i<m){
        int j = 0;
        while(j<n){
            for(int c = 0; c <= j; c++){
                pre[i][j] += a[i][c];
            }
            j++;
        }
        i++;
    }
    i = 1;
    int r = 0;
    while(i<m){
        for(int c = 0; c < n ;c++){
            pre[i][c] += pre[r][c];
        }
        r++;
        i++;
    }
}
int method1(int a[][10], int m, int n){ 
    int sum = 0; 
    for(int tlx = 0 ; tlx < m; tlx++){ // tlx : top left x
        for(int tly = 0 ; tly < n; tly++){ // tly : top left y
            for(int brx = tlx+1 ; brx <= m; brx++){ // brx : bottom right x
                for(int bry = tly+1 ; bry <= n; bry++){ // bry : bottom right y
                    for(int i = tlx; i < brx; i++){
                        for(int j = tly; j < bry; j++){
                            sum += a[i][j];
                        }
                    }
                }
            }
        }  
    }
    return sum;
}
/*int method2(int a[][10], int m, int n){
    //Creating a prefix Sum matrix
    int pre[10][10] = {0};
    prefix(a,pre,m,n);
    output(pre,m,n);
    int sum = 0;
    for(int tlx = 0 ; tlx < m; tlx++){ // tlx : top left x
        for(int tly = 0 ; tly < n; tly++){ // tly : top left y
            for(int brx = tlx ; brx < m; brx++){ // brx : bottom right x
                for(int bry = tly ; bry <n; bry++){ // bry : bottom right y
                    int m = pre[brx][bry];
                    int u = 0;
                    if(tlx != 0){
                        u = pre[tlx-1][bry];
                    }
                    int s= pre[brx][0];
                    if(tly != 0){
                        s = pre[brx][tly-1];
                    }
                    int e = 0;
                    if(tlx != 0 && tly != 0){
                        e = pre[tlx-1][tly-1];
                    }
                    sum += m - u - s + e; 
                }
            }
        }
    }
    return sum;
}*/

int method3(int a[][10], int m, int n){
    int sum = 0;
    for(int  i = 0; i < n; i++){
        for(int  j = 0; j < n; j++){
            int tl = (i+1)*(j+1);
            int br = (n-i)*(m-j);
            sum += (tl * br) * a[i][j];
        }
    }
    return sum;
}
int main() {
    int a[10][10], m, n;
    //input row and column 
    cin>>m>>n;
    input(a,m,n);
    output(a,m,n);
    int s1 = method1(a,m,n);
    cout <<"Method 1(brute force, time complexity O(n^6)) "<< s1 << endl;
    /*
    int s2 = method2(a,m,n);
    cout<<s2;
    */
    int s3 = method3(a,m,n);
    cout<<s3;
}
