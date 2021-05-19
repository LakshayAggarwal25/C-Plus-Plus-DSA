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

int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtStart(node *&head, int d)
{
    /*
        here we are pasing a pointer variable by reference because when we insert the new element at head we
        need to update the value of the head
        Eg. 
        3 -> 2 -> 5 -> 1 -> NULL
        |
        (head pointing towards 3)

        if we want to insert 8 at begining then we need to put the head's value(i.e the address of the 1st element) into 8
        then need to update head with the address of 8 
        
        So, to update the value of head in the main we pass head pointer as reference   
    */

    if (head == NULL)
    {
        head = new node(d);
        return;
    }

    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    node *temp = new node(d);
    tail->next = temp;
    return;
}

void insertAtIndex(node *&head, int d, int p)
{

    if (head == NULL or p == 0)
    {
        insertAtStart(head, d);
        return;
    }
    else if (p > length(head))
    {
        insertAtEnd(head, d);
        return;
    }
    else
    {
        int i = 1;
        node *temp = head;
        while (i < p)
        {
            temp = temp->next;
            i++;
        }
        node *toBeAddedInList = new node(d);
        toBeAddedInList->next = temp->next;
        temp->next = toBeAddedInList;
        return;
    }
    return;
}

void deleteAtStart(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head; // to avoid memory leak we clear the memory
    head = temp;
    return;
}

void deleteAtEnd(node *head)
{
    if (head == NULL)
    {
        return;
    }
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    node *temp = head->next;
    delete temp;
    head->next = NULL;
}

void deleteAtIndex(node *&head, int p)
{
    if (head == NULL or p == 0)
    {
        deleteAtStart(head);
        return;
    }
    else if (p > length(head))
    {
        deleteAtEnd(head);
        return;
    }
    int i = 0;
    node *tempHead = head;
    while (i < p - 1)
    {
        tempHead = tempHead->next;
        i++;
    }
    node *temp = tempHead->next;
    tempHead->next = temp->next;
    delete temp;
    return;
}

bool isPresentInLinkedList(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }
    while (head->next != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

void inputCompleteLinkedList(node *&head)
{
    cout << "Enter the delimiter to stop taking input : ";
    int n;
    cin >> n;
    int data;
    cout << "Input List : ";
    cin >> data;

    while (data != n)
    {
        insertAtEnd(head, data);
        cin >> data;
    }
    return;
}

//Operator Overloading
// using << to directly give output of Linked List
ostream &operator<<(ostream &os, node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data << endl;
    return os;
}

//Using >> to take input of Linked List
istream &operator>>(istream &is, node *&head)
{
    inputCompleteLinkedList(head);
    return is;
}

void reverse(node *&head)
{
    node *previous = NULL;
    node *current = head;
    node *tempNext;
    while (current)
    { // while(current) is same as while(current != NULL)
        tempNext = current->next;
        current->next = previous;
        previous = current;
        current = tempNext;
    }
    head = previous;
    return;
}

node *recursiveReverse(node *head)
{
    if (head->next == NULL or head == NULL)
    {
        return head;
    }

    node *newHead = recursiveReverse(head->next);

    head->next->next = head;
    head->next = NULL;
    return newHead;
}

node *midPoint(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *kThNodeFromTheEnd(node *head, int k)
{
    // We keep a fast pointer and a slow pointer at the start and then intially we move the fast pointer k steps ahead,
    // then after that we move both the pointers 1 step at a time and when the fast pointer reaches NULL then slow pointer would
    // be pointing at the kth node from the end.
    if (head == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head;
    int i = 0;
    while (i < k and fast->next != NULL)
    {
        fast = fast->next;
        i++;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    // take a head pointer
    node *c;

    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node *mergeSort(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    node *mid = midPoint(head);

    // Break the list in 2 parts
    node *a = head;
    node *b = mid->next;

    mid->next = NULL;

    // Recursively sort the 2 parts
    a = mergeSort(a);
    b = mergeSort(b);

    // merge them
    node *c = merge(a, b);

    return c;
}

bool detectCycle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

node *determineCycleStart(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head;
    bool flag = false;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            slow = head;
            flag = true;
            break;
        }
    }
    if (flag)
    {
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast)
            {
                return fast;
            }
        }

        if (fast->next->next == slow)
        {
            return fast;
        }
    }
    return nullptr;
}

void print(node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data << endl;
}

int main()
{
    // node *head = NULL;
    // // insertAtStart(head, 3);
    // // insertAtStart(head, 2);
    // // insertAtStart(head, 5);
    // // insertAtStart(head, 1);
    // // insertAtStart(head, 8);
    // // print(head);
    // // insertAtIndex(head,10,1);
    // // insertAtIndex(head,63,1);
    // // insertAtIndex(head,89,90);
    // // print(head);
    // // insertAtEnd(head,40);
    // // print(head);
    // // deleteAtStart(head);
    // // print(head);
    // // deleteAtEnd(head);
    // // print(head);
    // // deleteAtIndex(head,2);
    // // print(head);
    // // cout<<isPresentInLinkedList(head,89)<<endl;
    // // cout<<isPresentInLinkedList(head,100)<<endl;
    // // print(head);
    // inputCompleteLinkedList(head);
    // // node *head2 = NULL;
    // // cin>>head2;
    // // cout<<head<<head2;
    // cout << head;
    // reverse(head);
    // cout << head;
    // head = recursiveReverse(head);
    // cout << head;
    // node *mid = midPoint(head);
    // cout<<mid->data<<endl;
    // node *k = kThNodeFromTheEnd(head,3);
    // cout<<k->data<<endl;

    node *a = NULL, *b = NULL;
    cin >> a >> b;
    cout << a << b;
    node *c = merge(a, b);
    cout << c;
}