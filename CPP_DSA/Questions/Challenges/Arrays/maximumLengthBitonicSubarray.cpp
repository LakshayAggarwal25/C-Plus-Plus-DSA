/*
You are provided n numbers of array. You need to find the maximum length of bitonic subarray.
 A subarray A[i … j] is biotonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] 
 i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.

Input Format
First line contains integer t which is number of test case. 
For each test case, it contains an integer n which is the size of array and next line contains n space separated integers.

Constraints
1<=t<=100 1<=n<=1000000

Output Format
Print the maximum length.

Sample Input
2
6
12 4 78 90 45 23
4
40 30 20 10

Sample Output
5
4

Explanation
For Maximum length = 4, 78, 90, 45, 23
*/
#include <iostream>
using namespace std;
int bitonic(int *A, int n)
{
    // if A is empty
    if (n == 0)
        return 0;
          
    // initializing max_len
    int maxLen=1;
          
    int start=0;
    int nextStart=0;
          
    int j =0;
    while (j < n-1)
    { 
        // look for end of ascent       
        while (j<n-1 && A[j]<=A[j+1])
            j++;
              
        // look for end of descent       
        while (j<n-1 && A[j]>=A[j+1]){
                  
            // adjusting nextStart;
            // this will be necessarily executed at least once,
            // when we detect the start of the descent
            if (j<n-1 && A[j]>A[j+1])
                nextStart=j+1;
                  
            j++;
        }
              
        // updating maxLen, if required
        maxLen = max(maxLen,j-(start-1));
              
        start=nextStart;
    }
          
    return maxLen;
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
        int ans = bitonic(a,n);
        cout<<ans<<endl;
        test_cases--;
    }
}