#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define ll long long int

using namespace std;

void prime_seive(int *p){
    for(ll i = 3; i < 1000000; i+=2){
        p[i] = 1;
    }

    for(ll i =3 ; i < 1000000; i+=2){
        if(p[i] == 1){
            for( ll j = i*i; j <= 1000000; j += i ){
                p[j]=0;
            }
        }
    }
    p[2] = 1;
    p[0] = p[1] = 0;

}
int main(){
    int n;
    cin>>n;
    int p[1000000] = {0};
    prime_seive(p);
    for(ll i = 0;i <= n; i++){
        if(p[i] == 1){
            cout<<i<<", ";
        }
    }
    cout<<"END";
    getch();
}