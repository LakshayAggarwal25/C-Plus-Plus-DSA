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
    int currentSum = 0; // current Sum


    //Generating sum of the max sub-arrays

    for(int i = 0 ; i < n ; i++){
        currentSum = currentSum + a[i];
        if(currentSum < 0){
            currentSum = 0;
        }
        maxSum = max(maxSum,currentSum);
    }
    cout<<"Sum : "<<maxSum;

}

