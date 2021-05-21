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

void insertAtStart(node *&head, int data)
{
    node *n = new node(data);
    node *tempHead = head;
    n->next = head;
    if (tempHead != NULL)
    {
        while (tempHead->next != head)
        {
            tempHead = tempHead->next;
        }
        tempHead->next = n;
    }
    else
        n->next = n; // this is only for the 1st node, when we insert the first node we need to create a self loop
    head = n;
    return;
}

ostream &operator<<(ostream &os, node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty " << endl;
        return os;
    }
    node *tempHead = head;
    while (tempHead->next != head)
    {
        cout << tempHead->data << " -> ";
        tempHead = tempHead->next;
    }
    cout << tempHead->data << endl;
    return os;
}

node *getNode(node *head, int key)
{
    // Returns the address of the node where is data is present, returns null if data is not present
    node *tempHead = head;
    while (tempHead->next != head)
    {
        if (tempHead->data == key)
        {
            return temphead;
        }
        tempHead = tempHead->next;
    }
    // checking for the last node
    if (tempHead->data == key)
    {
        return tempHead;
    }

    return NULL;
}

void deleteNode(node *&head, int key)
{
    // deletes the node containing the data = key
    node *del = getNode(head, key);
    if (del == NULL)
    {
        return;
    }

    if (del == head)
    {
        head = head->next;
    }

    node *tempHead = head;
    //stop 1 node before the node to be deleted
    while (tempHead->next != del)
    {
        tempHead = tempHead->next;
    }
    tempHead->next = del->next;
    delete del;
    return;
}

int main()
{
    int n;
    cout << "Enter the number of Elements in List : ";
    cin >> n;
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insertAtStart(head, data);
    }
    cout << head;
}