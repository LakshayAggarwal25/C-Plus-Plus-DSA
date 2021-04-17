#include<iostream>
#include<stdlib.h>
#include <conio.h>
using namespace std;
int main(){
	int a[10];
	for(int i = 0; i < 5; i++){
		cin>>a[i];
	}
	for(int i = 0; i < 5; i++){
		cout<<a[i]<<'\n';
	}
	getch();
	return 0;
}
