#include<iostream>
#define printArray(a,n) for(int i = 0; i<n;i++) cout<<a[i]<<", "; cout<<"END"<<endl;
#define rep(n) for(int i = 0;i<n ; i++)
using namespace std;

void bubbleSort(int *a, int n){
    if(n==1)
    {
        return;
    }
    for (int j = 0; j < n-1; j++)
    {
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
    bubbleSort(a,n-1);
    
}

void bubbleSortRecursive(int *a, int j, int n){
    if(n==1){
        return;
    }
    
    if(j==n-1){
       // Single pass of the current array has been done
        return bubbleSortRecursive(a,0,n-1);
    }

    if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }
    bubbleSortRecursive(a,j+1,n);
    return;
}

int main(){
    int a[] = {5,4,2,3,1};
    int n = 5;
    printArray(a,n);
    bubbleSortRecursive(a,0,n);
    printArray(a,n);

}