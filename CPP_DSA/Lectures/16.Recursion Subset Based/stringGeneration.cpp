#include<iostream>
using namespace std;

void generateStrings(char *in, char *out, int i, int j){
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }

    int digit = in[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;
    generateStrings(in,out,i+1,j+1);

    if(in[i+1]!='\0'){
        int secondDigit = in[i+1] - '0';
        int no = digit*10 + secondDigit;
        if(no<=26){
            ch = no + 'A' - 1;
            out[j] = ch;
            generateStrings(in,out,i+2,j+1); 
        }
    }

    return;

}

int main(){
    char input[100];
    cin>>input;
    char output[100];
    generateStrings(input, output, 0, 0);
}