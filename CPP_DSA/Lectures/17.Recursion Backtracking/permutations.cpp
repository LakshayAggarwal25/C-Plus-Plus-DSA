#include<iostream>
using namespace std;

void permute(char *in, int idx){
    if(in[idx] == '\0'){
        cout<<in<<endl;
        return;
    }


    for (int j = idx; in[j] != '\0'; j++){
        swap(in[idx],in[j]);
        permute(in,idx+1);
        swap(in[idx],in[j]);
    }
    return;
}
int main(){
    char in[100];
    cin>>in;
    permute(in,0);
}