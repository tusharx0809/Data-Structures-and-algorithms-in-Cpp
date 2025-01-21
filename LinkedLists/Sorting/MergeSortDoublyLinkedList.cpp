//CPP program to merge sort doubly linked list

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

class DoublyLinkedList{
    public:
    Node *head;
    DoublyLinkedList() : head(NULL) {}

    void insertAtBeginning(int value){
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(!head){
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void display(){
        if(!head){
            cout<<"Empty List!"<<endl;
            return;
        }
        Node *temp = head;
        cout<<"NULL <-> ";
        while(temp){
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main(){
    DoublyLinkedList list;
    list.display();
    return 0;
}