/*
Given a linked list of length N and an long longeger K , append the last K elements of a linked list to the front. 
Note that K can be greater than N.

Input Format
First line contains a single long longeger N denoting the size of the linked list.
Second line contains N space separated long longegers denoting the elements of the linked list.
Third line contains a single long longeger K denoting the number of elements that are to be appended.

Constralong longs
1 <= N <= 10^4
1 <= K <= 10^4

Output Format
Display all the elements in the modified linked list.

Sample Input
7
1 2 2 1 8 5 6
3
Sample Output
8 5 6 1 2 2 1
Explanation
Initially the linked list is
1→ 2→ 3 → 4 → 5 → 6→ null
and k = 2. After appending the last two elements to the front , the new linked list looks like
5→ 6→ 1→ 2→ 3 → 4 → null

*/
#include <iostream>
using namespace std;
class node
{
public:
    long long data;
    node *next;
    node (long long d)
    {
        data = d;
        next = NULL;
    }
};
void input(node *&head, long long n)
{
    if(n==0){
        return;
    }
    long long d;
    cin >> d;

    head = new node(d);
    node *tempHead = head;

    long long i = 1;
    while (i < n)
    {
        cin >> d;
        node *temp = new node(d);
        tempHead->next = temp;
        tempHead = tempHead->next;
        i++;
    }
    return;
}

void output(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void kAppend(node *&head,long long k, long long n){
    if(k<=0 or n == 0 or k%n == 0){
        return;
    }
    
    node *tempHead = head;
    node *newHead;
    node *tempNewHead;

    long long i = 0;
      
    k = k%n ;

    k = ((n -k)-1);
    while(i < k){
        tempHead = tempHead->next;
        i++;
    }
    newHead = tempHead->next;
    tempNewHead = newHead;

    tempHead->next = NULL;

    while(tempNewHead->next != NULL){
        tempNewHead = tempNewHead->next;
    }
    
    tempNewHead->next = head;
    head = newHead;
    return;
}

int main(){
    long long n ,k;
    cin>>n;
    node *head;
    input(head,n);
    cin>>k;
    kAppend(head,k,n);
    output(head);

}