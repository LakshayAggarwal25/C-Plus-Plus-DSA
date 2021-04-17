#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a[100],n;
    cin>>n;

    int maxSum = INT_MIN; // maximum Sum
    int cSum = 0; // current Sum
    int cumSum[100] = {0}; // Array containing cumulative sums
    int left = -1; // lower bound of the max sub-array
    int right = -1; // upper bound of the max sub-array

    //Array input
    cin>>a[0];
    cumSum[0] = a[0];
    for (int i = 1; i< n ; i++){
        cin>>a[i];
        cumSum[i] = cumSum[i-1] + a[i];
    }

    //Generating all the sub-arrays
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            cSum = 0;
            cSum = cumSum[j] - cumSum[i-1];
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

