#include<iostream>
using namespace std;
char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void generateNames(char *in, char *out, int i,int j){

    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }

    int digit = in[i] - '0';
    if(digit == 1 || digit == 0){
        generateNames(in, out, i+1,j);
    }
    for (int k = 0; keypad[digit][k]!= '\0'; k++){
        out[j]  = keypad[digit][k];
        generateNames(in,out,i+1,j+1);

    }        
}

int main(){
    char out[1000];
    char in[1000];
    cin>> in;

    generateNames(in,out,0,0);
}