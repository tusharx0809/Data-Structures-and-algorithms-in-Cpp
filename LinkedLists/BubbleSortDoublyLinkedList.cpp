//CPP program to bubble sort Doubly Linked List

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

class DoublyLinkedList{
    Node* head;
    public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtBeginning(int val){
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(!head){
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void display(){
        if(!head){
            cout<<"Empty List!"<<endl;
            return;
        }
        cout<< "NULL <-> ";
        Node *temp = head;
        while(temp){
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main(){
    DoublyLinkedList list;
    list.display(); //Empty List!

    for(int i=0;i<=5;i++){
        list.insertAtBeginning(i);
    }
    list.display();
    return 0;
}