#include <iostream>
#include<algorithm>
using namespace std;
// Defining a Comparator Function
bool compare(int a, int b){
    return b<a;
}
int main() {

    int arr[] = {1,10,11,9,100};
    int n = sizeof(arr)/sizeof(int);
    // Search in an unsorted array --> find(array_name,array_name + number_of_elements,key)

    int key;
    cin>>key;
    auto it = find(arr, arr+n,key);
    int index = it - arr; // find returns the address where the key is present so 'it' is a pointer here
                          //  Hence, if we subtract the 'it' with 'arr' then we will get the index where the key is present
    if(index == n){
        cout<<key<<" not present"<<endl;
    }
    else{
    cout<<key<<" Present at "<<index;
    }

    // Search in a sorted array --> binary_search(array_name,array_name + number_of_elements,key)

    int arr1[] = {1,9,10,11,11,11,11,130,1000};
    n = sizeof(arr1)/sizeof(int);
    cin>>key;
    bool present = binary_search(arr1,arr1+n,key);
    if(present){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }

    // Get the index of the element
    // lower_bound(s,e,key) and upper_bound(s,e,key)
    //lower_bound gives the 1st index where element present <= key in the array
    //whereas, upper_bound gives the index where the element present > key

    auto lb = lower_bound(arr1,arr1+n,11);
    cout<<"Lower bound of 11 : "<<(lb-arr1)<<endl;
    auto ub = upper_bound(arr1,arr1+n,11);
    cout<<"Upper bound of 11 : "<<(ub-arr1)<<endl;

    cout<<"Occurences of 11 : "<<(ub-lb)<<endl;

    //Sort function 
    int arr2[20];
    int n2;
    cin >> n2;
    for(int i = 0 ; i< n2;i++){
        cin>>arr2[i];
    }
    for(int i = 0 ; i< n2;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    sort(arr2,arr2+n2);
    for(int i = 0 ; i< n2;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    // To sort it in descending order we need to define a comparator function
    sort(arr2,arr2+n2,compare);
    for(int i = 0 ; i< n2;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;



}
