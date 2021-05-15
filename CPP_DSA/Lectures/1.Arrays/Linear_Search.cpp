#include<iostream>
using namespace std;

// This searching technique can search an element in O(n) time
// and can search in both sorted and unsorted array

int linearSearch(int arr[],int n, int key){ 
  // arr -> array in which the item is to searched, n-> size of arr, key -> element to be searched
  // Loops over array to check if the current element is equal to key, and if it is then it returns the index at which element is found
  for(int i = 0; i < n; i++){               
    if(arr[i] == key)
        return i;
  }
  // We will only get out of the loop if element is not found, so we return -1 
  return -1;
}

int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int n;
    n = sizeof(a)/sizeof(a[0]);
    cout<<"Key found at : "<<linearSearch(a,n,15);
    return 0;
}
