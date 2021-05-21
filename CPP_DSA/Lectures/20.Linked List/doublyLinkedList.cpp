#include <iostream>

using namespace std;

class node{
    public :
        int data;
        node *next;
        node *previous;
        node(int d){
            data = d;
            next = NULL;
            previous = NULL;
        }
};

int length(node *head){
    int n = 0;
    while(head){
        head = head->next;
        n++;
    }
    return n;
}

void insertAtStart(node *&head){
    int d;
    cin>>d;
    if(head == NULL){
        head = new node(d);
        return;
    }
    
    node *temp = new node(d);
    temp->next = head;
    temp->previous = NULL;
    head->previous = temp;
    head = temp;
    return ;
}

void insertAtEnd(node *&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node *temp = new node(d);
    node *tempHead = head;
    while(tempHead->next){
        tempHead = tempHead->next;
    }
    tempHead->next = temp;
    temp->previous = tempHead;
    return;
}

void insertAtKthIdx(node *&head, int k){
    if(head == NULL or k == 0){
        insertAtStart(head);
        return;
    }
    int d ;
    cin>>d;
    if(k>=length(head)){
        insertAtEnd(head,d);
        return;
    }
    node *temp = new node(d);
    node *tempNext;
    node *tempHead = head;
    int i = 0;
    while(i<k-1){
        tempHead = tempHead->next;
        i++;
    }
    tempNext = tempHead->next;
    temp->next = tempHead->next;
    temp->previous = tempHead;
    tempHead->next = temp;
    tempNext->previous = temp;
    return;
}

void deleteAtStart(node *&head){
    if(head==NULL){
        return;
    }
    node *temp = head->next;
    delete head;
    temp->previous = NULL;
    head = temp;
    return;
}

void deleteAtEnd(node *head){
    if(head == NULL){
        return;                                        
    }                                        
    node *tempHead = head;                                        
    while(tempHead->next->next != NULL){                                        
        tempHead = tempHead->next;                                        
    }
    node *temp = tempHead->next;
    tempHead->next = NULL;
    delete temp;
    return;
}

void deleteAtKthIdx(node *&head, int k){
    if(head == NULL or k == 0){
        return deleteAtStart(head);
    }
    if(k >= length(head)){
        cout<<"Index does not exist"<<endl;
    }
    if(k == length(head)-1){
        return deleteAtEnd(head);
    }
    
    int i = 0 ;
    node *tempPrev = head;
    while(i<k-1){
        tempPrev = tempPrev->next;
        i++;
    }
    node *temp = tempPrev->next;
    node *tempNext = temp->next;
    
    tempNext->previous = temp->previous;
    tempPrev->next = temp->next;
    delete temp;
    return;
}

bool isPresent(node *head, int key){
    if(head == NULL){
        return false;
    }
    while(head){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

int find(node* head, int key){
    if(head == NULL){
        return -1;
    }
    int i = 0;
    while(head){
        if(head->data == key){
            return i;
        }
        head= head->next;
        i++;
    }
    return -1;
}

void inputList(node *&head){
    int n;
    cout<<"Enter the delimiter to stop taking input : ";
    cin>>n;
    int data;
    cin>>data;
    while(data != n){
        insertAtEnd(head,data);
        cin>>data;
    }
    return;
}

void print(node *head){
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    while(head->next){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
    return;
}

void printReverse(node *head){
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    while(head->next){
        head = head ->next;
    }
    while(head->previous){
        cout<<head->data<<"->";
        head = head->previous;
    }
    cout<<head->data<<endl;
    return;
}

ostream &operator<<(ostream &os, node *head){
    print(head);
    return os;
}

istream &operator>>(istream &is, node *&head){
    inputList(head);
    return is;
}

int main() {
    // node *head = NULL;
    // insertAtStart(head);
    // insertAtStart(head);
    // insertAtStart(head);
    // print(head);
    // insertAtEnd(head);
    // insertAtEnd(head);
    // print(head);
    // cout<<"Length : "<<(length(head))<<endl;
    // int k;
    // cin>>k;
    // insertAtKthIdx(head, k);
    // cin>>k;
    // insertAtKthIdx(head, k);
    // cin>>k;
    // insertAtKthIdx(head, k);
    // print(head);
    // printReverse(head);
    // deleteAtStart(head);
    // print(head);
    // deleteAtEnd(head);
    // print(head);
    // cout<<"Deleteing 3rd Index "<<endl;
    // deleteAtKthIdx(head,3);
    // print(head);
    // printReverse(head);
    // cout<<"Searching for 4"<<endl;
    // if(isPresent(head,4)){
    //     cout<<"4 is Present"<<endl;
    // }
    // else{
    //     cout<<"4 is Not Present"<<endl;
    // }
    // cout<<"Searching for 2"<<endl;
    // if(isPresent(head,2)){
    //     cout<<"2 is Present"<<endl;
    // }
    // else{
    //     cout<<"2 is Not Present"<<endl;
    // }
    // cout<<"Index of 6 : "<<find(head,6)<<endl;
    // cout<<"Index of 4 : ";
    // if(find(head,4)==-1){
    //     cout<<"4 is not Present in the List"<<endl;
    // }
    // else{
    //     cout<<find(head,4)<<endl;
    // }
    
    
    node *head = NULL;
    // inputList(head);
    // print(head);
    // printReverse(head);
    
    cin>>head;
    cout<<head;
    return 0;
}