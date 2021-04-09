
#include <iostream>
#include<cstring>

using namespace std;

char *mystrtok(char *str, char delim){
    static char *input = NULL;
    if(str!=NULL){
        //making the first call
        input = str;
    }
    //
    if(input == NULL){
        return NULL;
    }
    //start extracting tokens and store them in an array
    char *output = new char[strlen(input)+1];
    int i=0;
    for(;input[i]!='\0';i++){
        if(input[i]!=delim){
            output[i] = input[i];
        }
        else{
            output[i] = '\0';
            input = input+i+1;
            return output;
        }
    }
    //corner case
    output[i] = '\0';
    input = NULL;
    return output;
}

void mytokenizer(){
    char s[100] = "Tomorrow will be a good day";
    char *ptr = mystrtok(s,' ');
    cout<<ptr<<endl;

    while(ptr!=NULL){
        ptr = mystrtok(NULL,' ');
        cout<<ptr<<endl;
    }
}
int main() {
    cout<<"Making string tokenizer"<<endl;
    mytokenizer();

    cout<<"\n\nDefault tokenizer";

    char s[100] = "Today is a rainy day";
    char *ptr = strtok(s," ");
    cout<<ptr<<endl;

    while(ptr!=NULL){
        ptr = strtok(NULL," ");
        cout<<ptr<<endl;
    }
}
