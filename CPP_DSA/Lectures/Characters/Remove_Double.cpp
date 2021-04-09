#include<iostream>
#include<cstring>
using namespace std;
// remove consecutive duplicate characters from a string
// ccooding --> coding
void removeDuplicates(char a[]){
    int l = strlen(a);
    if(l==1 || l == 0){
        return;
    }
    int prev = 0;
    for (int current =1; current < l ; current++){
        if(a[current]!= a[prev]){
            prev++;
            a[prev] = a[current];
        }
    }
    a[prev+1] = '\0';
    return;
}

int main(){
    char a[100];
    cin.getline(a,100);
    removeDuplicates(a);
    cout << a;

    return 0;
}
