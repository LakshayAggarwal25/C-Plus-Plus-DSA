/*
Given a head to Linked List L, write a function to reverse the list taking k elements at a time. 
Assume k is a factor of the size of List.

You need not have to create a new list. Just reverse the old one using head.

Input Format
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints
0 <= N <= 10^6 0 <= K <= 10^6

Output Format
Display the linkedlist after reversing every k elements

Sample Input
9 3
9 4 1 7 8 3 2 6 5

Sample Output
1 4 9 3 8 7 5 6 2

Explanation
N = 9 & K = 3

Original LL is : 9 -> 4 -> 1 -> 7 -> 8 -> 3 -> 2 -> 6 -> 5

After k Reverse : 1 -> 4 -> 9 -> 3 -> 8 -> 7 -> 5 -> 6 -> 2
*/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void input(node *&head, int n)
{
    int data;
    cin >> data;
    head = new node(data);
    node *tempHead = head;
    int i = 1;
    while (i < n)
    {
        cin >> data;
        node *temp = new node(data);
        tempHead->next = temp;
        tempHead = tempHead->next;
        i++;
    }
    return;
}

node* reverse(node *&head, int k)
{
    node *previousNode = NULL;
    node *currentNode = head;
    node *nextNode;

    int count = 0;
    while (currentNode and count < k)
    {
        // this loop will reverse the first k nodes in the list
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
        count++;
    }
    if (nextNode)
    {
        head->next = reverse(nextNode, k);
    }
    // now previous node will be our head node;
    return previousNode;
}

void print(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return;
}

int main()
{
    node *head = NULL;
    int n;
    cin >> n;
    int k;
    cin >> k;
    input(head, n);
    head = reverse(head, k);
    print(head);
}