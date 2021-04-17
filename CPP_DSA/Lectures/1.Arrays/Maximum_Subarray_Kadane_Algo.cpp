#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a[100],n;
    cin>>n;
    for (int i = 0; i< n ; i++){
        cin>>a[i];
    }

    int maxSum = 0; // maximum Sum
    int cSum = 0; // current Sum


    //Generating all the sum of max sub-arrays
    for(int i = 0 ; i < n ; i++){
        cSum = cSum + a[i];
        if(cSum < 0){
            cSum = 0;
        }
        maxSum = max(maxSum,cSum);
    }
    cout<<"\nSum : "<<maxSum;
}

