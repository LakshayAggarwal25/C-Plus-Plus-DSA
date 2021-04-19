#include<iostream>
using namespace std;

int getBit(int n, int i);
int setBit(int n, int i);
int clearBit(int n, int i);
int clearLastIBits(int n,int i);
int clearRangeOfBits(int n, int i, int j);
int updateBit(int n, int i, int v);
bool isOdd(int n);
void outputNAsBits(int n);


void outputNAsBits(int n){
    cout<<'\n'<<n<<" as bits : ";
    for(int i = 11;i>=0;i--)
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

int updateBit(int n, int i, int v){
    // this function updates the i'th bit as v
    n = clearBit(n,i);
    int mask = v<<i;
    int ans = n | mask;
    return ans;
}

int clearLastIBits(int n, int i){
    int mask = -1<<i;
    return (n & mask);
}

int clearRangeOfBits(int n, int i, int j){
    int rightSideOnes = -1<<(j+1);
    int leftSideOnes = (1<<i) - 1;
    int mask = rightSideOnes | leftSideOnes;
    return (n & mask);
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
    cout<<"Set Bit called, n is now = "<<n<<endl;
    outputNAsBits(n);

    n = clearBit(n,2);
    cout<<"Clear Bit called, n is now = "<<n<<endl;
    outputNAsBits(n);

    n = updateBit(n,4,1);
    cout<<"Update Bit called, n is now = "<<n<<endl;
    outputNAsBits(n);

    n = updateBit(n,1,0);
    cout<<"Update Bit called, n is now = "<<n<<endl;
    outputNAsBits(n);

    n = clearLastIBits(n,4);
    cout<<"Clear Last i bits called (4 in this case), n is now = "<<n<<endl;
    outputNAsBits(n);

    n = 183;
    cout<<"N changed to : "<<n<<endl;
    outputNAsBits(n);

    n = clearRangeOfBits(n,3,5);
    cout<<"Clear Range of bits called (3,5 in this case), n is now = "<<n<<endl;
    outputNAsBits(n);
}