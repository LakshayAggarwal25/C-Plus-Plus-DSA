/*
Staircase Problem : Search in Row and Column Wise Sorted Array 
Sample input 
4 4 16
1 4 8 10
2 5 9 15
6 16 18 20
11 17 19 23

Sample Output
Element found at : a[2][1]
*/
#include <iostream>
using namespace std;
void find(int a[][100], int m, int n, int k){
    bool flag = false;
    int i = 0;
    int j = n-1;
    while(!flag && i < m && j >- 1){
        if (a[i][j] == k){
            flag = true;
            break;
        }
        if(a[i][j] < k){
            i++;
        }
        if(a[i][j] > k){
            j--;
        }
    }
    if(flag){
        cout << "Element found at : a[" << i << "][" << j << "]";
    }
    else{
        cout<<"Not Found";
    }
}
int main() {
    int m,n,key;
    int a[100][100];
    cin>>m>>n>>key;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>a[i][j];
        }
    }
    find(a, m, n, key);
}
