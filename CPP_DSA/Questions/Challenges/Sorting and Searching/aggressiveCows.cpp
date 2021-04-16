/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, 
such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input Format
First line contains N and C, separated by a single space, representing the total number of stalls and number of cows respectively. 
The next line contains N integers containing the indexes of stalls.

Constraints
2 <= N <= 100,000
0 <= xi <= 1,000,000,000
2 <= C <= N

Output Format
Print one integer: the largest minimum distance.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

*/
#include <iostream>
#include<algorithm>
using namespace std;
bool can_place_cows(int a[100000],int n,int c,int min_sep){
    int last_cow = a[0];
    int count = 1;
    for(int i = 1; i < n;i++){
        if(a[i]-last_cow>= min_sep){
            last_cow = a[i];
            count ++;
            if(count == c){
                return true;
            }
        }
    }
    return false;
}
int distance_between_cows(int a[100000], int n, int c){
    int s = 0;
    int e = a[n-1]-a[0];
    int ans = 0;
    while(s<=e){
        int mid = (s+e)/2;
        if(can_place_cows(a,n,c,mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}
int main() {
        int n,c;
        cin>>n>>c;
        int a[100000];
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        sort(a,a+n);
        cout<<distance_between_cows(a,n,c)<<endl;
}