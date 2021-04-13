/*
We will calculate the total sum of the given array.
We will declare variable curr_max, max_so_far, curr_min, min_so_far as the first value of the array.
Now we will use Kadane’s Algorithm to find maximum subarray sum and minimum subarray sum.
Check for all the values in the array:- 
If min_so_far is equaled to sum, i.e. all values are negative, then we return max_so_far.
Else, we will calculate the maximum value of max_so_far and (sum – min_so_far) and return it.
*/
#include <iostream>
#include<climits>
using namespace std;
int max_circular_subarray(int *a, int n)
{
    int curr_max_sum = a[0];
    int maxsum = a[0];
    int curr_min_sum = a[0];
    int minsum = a[0];
    int SUM = a[0];
    for(int i = 1; i < n; i++){
        SUM += a[i];
        curr_max_sum = curr_max_sum+ a[i];
        if(curr_max_sum < 0){
            curr_max_sum = 0;
        }
        maxsum = max(curr_max_sum,maxsum);

        curr_min_sum = min((curr_min_sum + a[i]), a[i]);
        minsum = min(curr_min_sum,minsum);
    }
    if(minsum == SUM){
        return maxsum;
    }
    return max(maxsum, SUM-minsum);
}
int main() {
    int test_cases;
    cin>>test_cases;
    while(test_cases>0){
        int n;
        cin>>n;
        int a[100000];
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int ans = max_circular_subarray(a,n);
        cout<<ans<<endl;
        test_cases--;
    }
}
