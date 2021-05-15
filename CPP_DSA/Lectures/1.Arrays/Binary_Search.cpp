#include<iostream>
using namespace std;
// This Searching technique can only be used on a sorted array in O(log(n)) time

int binarySearch(int arr[],int n, int key){
    //arr-> sorted array in which searching needs to be done, n-> size of arr, key -> element to be searched
    int low = 0;
    int high = n-1;
    // we need to loop until low is less than high
    while(low<=high){
        /*
        Since this is a sorted array we initially check the element at the mid if it is equal to the key we return the index,
        if it value at mid is less then the key then we search in the upper half of the array(i.e. mid+1 to high),
        else we search in the lower half of the array(i.e. low to mid-1) 
        */
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
