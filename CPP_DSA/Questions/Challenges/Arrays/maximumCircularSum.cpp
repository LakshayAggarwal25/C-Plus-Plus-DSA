/*
You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive numbers.

Input Format
First line contains integer t which is number of test case.
For each test case, it contains an integer n which is the size of array and 
next line contains n space separated integers denoting the elements of the array.

Constraints
1<=t<=100
1<=n<=1000
|Ai| <= 10000

Output Format
Print the maximum circular sum for each testcase in a new line.

Sample Input
1
7
8 -8 9 -9 10 -11 12

Sample Output
22

Explanation
Maximum Circular Sum = 22 (12 + 8 - 8 + 9 - 9 + 10)
*/
//-----------------------------------------------------------------------------------------------------------------------
/*
We will calculate the total sum of the given array.
We will declare variable curr_max, max_so_far, curr_min, min_so_far as the first value of the array.
Now we will use Kadaneâs Algorithm to find maximum subarray sum and minimum subarray sum.
Check for all the values in the array:- 
If min_so_far is equaled to sum, i.e. all values are negative, then we return max_so_far.
Else, we will calculate the maximum value of max_so_far and (sum â min_so_far) and return it.
*/
#include <iostream>
#include<climits>
using namespace std;
// Standard Kadane's algorithm to
// find maximum subarray sum
int kadane(int a[], int n);
 
// The function returns maximum
// circular contiguous sum in a[]
int maxCircularSum(int a[], int n)
{
    // Case 1: get the maximum sum using standard kadane'
    // s algorithm
    int max_kadane = kadane(a, n);
     // if maximum sum using standard kadane' is less than 0
    if(max_kadane < 0)
      return max_kadane;
 
    // Case 2: Now find the maximum sum that includes
    // corner elements.
    int max_wrap = 0, i;
    for (i = 0; i < n; i++) {
        max_wrap += a[i]; // Calculate array-sum
        a[i] = -a[i]; // invert the array (change sign)
    }
 
    // max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(a, n);
 
    // The maximum circular sum will be maximum of two sums
    return (max_wrap > max_kadane) ? max_wrap : max_kadane;
}
 
// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int a[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for (i = 0; i < n; i++) {
        max_ending_here = max_ending_here + a[i];
         
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
          if (max_ending_here < 0)
              max_ending_here = 0;
    }
    return max_so_far;
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
        int ans = maxCircularSum(a,n);
        cout<<ans<<endl;
        test_cases--;
    }
}