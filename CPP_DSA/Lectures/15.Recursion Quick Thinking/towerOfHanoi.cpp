/*
TOWER OF HANOI

Move all disks from A to C
Pick 1 Disk at a time 
Can't place big disk on small disk

Print all the steps

*/

#include<iostream>

using namespace std;

int count = 0;

void move(int n, char src, char helper, char dest){

    if(n==0){
        return;
    }

    move(n-1,src,dest,helper);
    cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
    count++;
    move(n-1,helper,src,dest);
}

int main(){
    int n;
    cin>>n;
    move(n,'A','B','C');
    cout<<"Steps required : "<<count;
}