#include<iostream>
using namespace std;
int getBit(int n,int i);
void outputNAsBits(int n){
    cout<<'\n'<<n<<" as bits : ";
    for(int i = 7;i>=0;i--)
        cout<<getBit(n,i);
    cout<<endl<<endl;
}
bool isOdd(int n){
    if(n&1 == 1)
        return true;
    return false;
}

int getBit(int n, int i){
    int mask = (1<<i);
    return ((n & mask) > 0) ? 1 : 0; 
}

int setBit(int n,int i){
    // this function sets the i'th bit as 1 if it is 0 and doesn't update if it is already 1
    int mask = (1<<i);
    int ans = n | mask;
    return ans;
}

int clearBit(int n,int i){
    // this function sets the i'th bit as 0 if it is 1 and doesn't update if it is already 0
    int mask = ~(1<<i);
    int ans = n & mask;
    return ans;
}

int updateBit(int n, int i , int v){
    // this function updates the i'th bit as v
    n = clearBit(n,i);
    int mask = v<<i;
    int ans = n | mask;
    return ans;
}
int main(){
    int n = 5;
    cout<<n<<endl;
    if(isOdd(n)){
        cout<<"\n"<<n<<" is odd"<<endl;
    }
    else{
        cout<<"\n"<<n<<" is even"<<endl;
    }
    outputNAsBits(n);

    n = setBit(n,1);
    cout<<"Set Bit Called, n is now = "<<n<<endl;
    outputNAsBits(n);

    n = clearBit(n,2);
    cout<<"Clear Bit Called, n is now = "<<n<<endl;
    outputNAsBits(n);

    n = updateBit(n,4,1);
    cout<<"Update Bit Called, n is now = "<<n<<endl;
    outputNAsBits(n);

    n = updateBit(n,1,0);
    cout<<"Update Bit Called, n is now = "<<n<<endl;
    outputNAsBits(n);
}