/*
Given 2 sorted linked lists , merge the two given sorted linked list and print the final Linked List.

Input Format
First Line contains T the number of test cases.
For each test case :
Line 1 : N1 the size of list 1
Line 2 : N1 elements for list 1
Line 3 : N2 the size of list 2
Line 4 : N2 elements for list 2

Constraints
1 <= T <= 1000
0<= N1, N2 <= 10^6
-10^7 <= Ai <= 10^7

Output Format
For each testcase , print the node data of merged linked list.

Sample Input
1
4
1 3 5 7
3
2 4 6

Sample Output
1 2 3 4 5 6 7 

Explanation
The two lists after merging give the sorted output as [1,2,3,4,5,6,7] .
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

node *merge(node *head1, node *head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    node *ans;

    if(head1->data < head2->data){
        ans = head1;
        ans->next = merge(head1->next,head2);
    }
    else{
        ans = head2;
        ans->next = merge(head1, head2->next);
    }

    return ans;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n1, n2;
        node *head1 = NULL, *head2 = NULL;
        cin >> n1;
        input(head1, n1);
        cin >> n2;
        input(head2, n2);
        node* ans = merge(head1, head2);
        output(ans);   
        cout<<endl;
    }
}