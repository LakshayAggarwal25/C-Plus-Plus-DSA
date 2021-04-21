#include<iostream>
#define rep(n) for(int i = 0; i < n; i++)
#define printArray(a,n) for(int i = 0; i < n; i++) cout<<a[i]<<", "; cout<<"End"<<endl

using namespace std;

void merge(int *a, int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[100];
    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }else{
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j<=e){
        temp[k] = a[j];
        j++;
        k++;       
    }

    for (int i = s; i <=e ; i++)
    {
        a[i] = temp[i];
    }
}

void mergeSort(int *a, int s, int e){
    //Base Case
    if(s>=e){
        return;
    }

    //Step 1. Divide
    int mid = (s+e)/2;

    //Step 2.Recursively call the divided arrays to sort them
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);

    //Step 3.Merge two parts
    merge(a,s,e);
}

int main(){
    int a[100];
    int n;
    cin >> n;
    rep(n){
        cin>>a[i];
    }
    printArray(a,n);
    mergeSort(a,0,n-1);
    printArray(a,n);
}