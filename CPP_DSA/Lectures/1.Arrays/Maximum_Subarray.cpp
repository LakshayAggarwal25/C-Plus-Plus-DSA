#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a[100],n;
    cin>>n;
    for (int i = 0; i< n ; i++){
        cin>>a[i];
    }

    int maxSum = INT_MIN; // maximum Sum
    int cSum = 0; // current Sum
    int left = -1; // lower bound of the max sub-array
    int right = -1; // upper bound of the max sub-array

    //Generating all the sub-arrays
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            cSum = 0;
            for(int k = i ; k <= j ; k++){
                cSum += a[k];
            }
            if(cSum > maxSum){
                maxSum = cSum;
                left = i;
                right = j;
            }
        }
    }
    cout<<"\nMax SubArray : "<<endl;
    for(int i=left;i<=right;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\nSum : "<<maxSum;
}
