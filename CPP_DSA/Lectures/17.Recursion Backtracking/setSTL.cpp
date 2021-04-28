#include<iostream>
#include<set>
#include<cstring>

using namespace std;

void permute(char* input, int idx, set<string> &s){
    if(input[idx] == '\0'){
        string temp(input);
        s.insert(temp);
        return;
    }
    for (int j = idx; input[j] != '\0'; j++){
        swap(input[idx],input[j]);
        permute(input,idx+1,s);
        swap(input[idx],input[j]);
    }
    return;
}

int main(){
    char a[100];
    cin>>a;
    set<string> s;

    permute(a,0,s);
    for(auto temp : s){
        cout<<temp<<", ";
    }
}