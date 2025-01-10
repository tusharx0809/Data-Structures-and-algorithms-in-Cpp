//This program consists operations on Doubly Circular Linked Lists

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
    Node* prev = NULL;
};

class DoublyCircularLinkedList{
    Node* head;

    public:
    DoublyCircularLinkedList() : head(NULL) {};

    void insertAtBeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;
        if(!head){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev=newNode;
        head = newNode;
        
    }
    void insertAtEnd(int value){
        Node* newNode = new Node();
        newNode->data = value;
        if(!head){
            head=newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
        
    }
    void insertAtPosition(int value, int position){
        Node* newNode = new Node();
        newNode->data = value;
        if(!head){
            return;
        }
        if(position == 1){
            insertAtBeginning(value);
            return;
        }
        int pos = 1;
        Node* temp = head;
        while(position-1 != pos){
            pos++;
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
    }
    void deleteFromBeginning(){
        if(!head){
            cout<<"List is empty!";
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        Node* delNode = head;
        temp->next = head->next;
        head->next->prev = temp;
        head = head->next;
        delete delNode;
    }
    void display(){
        if(!head){
            cout<<"List is empty!"<<endl;
            return;
        }
        cout<<"HEAD <-> ";
        Node* temp = head;
        do{
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }while(temp != head);
        cout<< "HEAD" <<endl;
    }
};

int main(){
    DoublyCircularLinkedList list1;
    list1.display(); //List is empty!

    for(int i=0;i<5;i++){
        list1.insertAtBeginning(i);
    }
    list1.display(); //HEAD <-> 4 <-> 3 <-> 2 <-> 1 <-> 0 <-> HEAD

    for(int i=5;i>0;i--){
        list1.insertAtEnd(i);
    }
    list1.display(); //HEAD <-> 4 <-> 3 <-> 2 <-> 1 <-> 0 <-> 5 <-> 4 <-> 3 <-> 2 <-> 1 <-> HEAD

    list1.insertAtPosition(40,3);
    list1.display(); //HEAD <-> 4 <-> 3 <-> 40 <-> 2 <-> 1 <-> 0 <-> 5 <-> 4 <-> 3 <-> 2 <-> 1 <-> HEAD

    list1.deleteFromBeginning();
    list1.display();
    return 0;
}