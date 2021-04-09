#include<iostream>
#include<climits>
using namespace std;

// For a given sorted array, Find Pair of Elements that sum to K(given)
int main(){
    int a[100],n;
    cin>>n;
    for (int i = 0; i< n ; i++){
        cin>>a[i];
    }

    int k;
    cin >>k;
    int i = 0,j = n-1;
    while(i<j){
        int current_sum = a[i] + a[j];
        if(current_sum>k){
            j--;
        }
        else if(current_sum<k){
            i++;
        }
        else if(current_sum = k){
            cout<<a[i] << "and"<<a[j]<<endl;
            i++;
            j--;
        }
    }
}


