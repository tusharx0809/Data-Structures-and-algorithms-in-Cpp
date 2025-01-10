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
        }else{
            Node* temp = head;
            while(temp->next != head){
                temp=temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head = newNode;
        }
    }

    void display(){
        if(!head){
            cout<<"List is empty!"<<endl;
            return;
        }
        cout<<"NULL <-> ";
        Node* temp = head;
        while(temp->next != head){
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main(){
    DoublyCircularLinkedList list1;
    list1.display();

    for(int i=0;i<5;i++){
        list1.insertAtBeginning(i);
    }
    list1.display();
    return 0;
}