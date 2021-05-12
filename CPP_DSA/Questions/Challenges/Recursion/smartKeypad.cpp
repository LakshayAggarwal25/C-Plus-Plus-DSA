/*
You will be given a numeric string S. Print all the possible codes for S.

Following vector contains the codes corresponding to the digits mapped.

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

For example, string corresponding to 0 is " " and 1 is ".+@$"

Input Format
A single string containing numbers only.

Constraints
length of string <= 10

Output Format
All possible codes one per line in the following order.

The letter that appears first in the code should come first

Sample Input
12

Sample Output
.a
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c

Explanation
For code 1 the corresponding string is .+@$ and abc corresponds to code 2.
*/
#include<iostream>
#include<cstring>

using namespace std;

char table[10][5] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };


void makePermutations(char *input, char *output, int inputIdx, int outputIdx){
    if(input[inputIdx]=='\0'){
        output[outputIdx] = '\0';
        cout<<output<<endl;
        return;
    }

    int digit = input[inputIdx] - '0'; // ascii for 0 is 48
            
    for (int i = 0; table[digit][i] != '\0'; i++)
    {
        output[outputIdx] = table[digit][i];
        makePermutations(input,output,inputIdx+1,outputIdx+1);
    }
}

int main(){
    char input[15];
    char output[15];
    cin>>input;
    makePermutations(input,output,0,0); 
}