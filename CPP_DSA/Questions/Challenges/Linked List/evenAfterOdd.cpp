#include <iostream>
using namespace std;
class node
{
public:
    long long data;
    node *next;
    node(long long d)
    {
        data = d;
        next = NULL;
    }
};
void input(node *&head, long long n)
{
    if (n == 0)
    {
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

void evenAfterOdd(node *&head)
{
    node *end = head;
    node *prev = NULL;
    node *curr = head;

    while (end->next)
    {
        end = end->next;
    }
    node *newEnd = end;

    while (curr->data % 2 == 0 and curr != end)
    {
        newEnd->next = curr;
        curr = curr->next;
        newEnd = newEnd->next;
        newEnd->next = NULL;
    }

    if (curr->data % 2 != 0)
    {
        head = curr;
        while (curr != end)
        {
            if (curr->data % 2 != 0)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                newEnd->next = curr;
                newEnd = curr;
                curr = prev->next;
            }
        }
    }
    else
    {
        prev = curr;
    }

    if (newEnd != end && (end->data) % 2 == 0)
    {
        prev->next = end->next;
        end->next = NULL;
        newEnd->next = end;
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    node *head = NULL;
    input(head, n);
    evenAfterOdd(head);
    output(head);
}
