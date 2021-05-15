#include<iostream>
using namespace std;
// Generate SubArrays
void printAllSubArrays(int *a, int n){
    for(int i = 0 ; i < n ; i++){           // This loop determines the starting point of the current subArray
        for(int j = i ; j < n ; j++){       // This loop determines the end point of the current subArray and it start from i, else
                                            // end point would be before starting point which make no sense

            cout<<"[";                     // This loop prints the array from starting point to end point
            for(int k = i ; k < j ; k++){  
                cout<<a[k]<<",";
            }
            cout<<a[j]<<"]";
            cout<<endl;
        }
    }
    cout<<"END";
    return ;
}
int main(){
    int a[100],n;
    cin>>n;
    for (int i = 0; i< n ; i++){
        cin>>a[i];
    }
    // Printing all SubArrays
    printAllSubArrays(a,n);    
}

