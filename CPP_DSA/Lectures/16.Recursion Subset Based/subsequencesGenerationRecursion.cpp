#include<iostream>
using namespace std;

void generateSubsequences(char *in, char *out, int i, int j){
    if(in[i] == '\0'){
        out[j] ='\0';
        cout<<out<<", ";
        return;
    }

    out[j] = in[i];
    generateSubsequences(in, out, i+1, j+1);

    generateSubsequences(in,out,i+1,j);
}

int main(){
    char input[] = "abc";
    char output[10];

    generateSubsequences(input,output,0,0);
}