#include<iostream>
#define printArray(a,n) for(int i = 0; i<n;i++) cout<<a[i]<<", "; cout<<"END"<<endl;
using namespace std;

int partition(int *a, int s, int e){
    int i = s-1;
    int j = s;

    int pivot = a[e];

    while (j <= e-1){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
        j++;
    }
    
    swap(a[i+1],a[e]);

    return i+1;

}

void quickSort(int *a,int s,int e){
    if(s>=e){
        return;
    }

    int p = partition(a,s,e);

    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

int main(){
    int arr[] = {1,5,2,6,3,0};
    int n = sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    printArray(arr,n)
}