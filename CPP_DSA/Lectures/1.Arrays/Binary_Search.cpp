#include<iostream>
using namespace std;
int binarySearch(int arr[],int n, int key){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int n;
    n = sizeof(a)/sizeof(int);
    cout<<binarySearch(a,n,5);
    return 0;
}
