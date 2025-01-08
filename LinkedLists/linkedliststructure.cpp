#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

class LinkedList{
    Node* head; //Pointer to the first node

    public:
    
    LinkedList() : head(NULL) {} //Constructor intitializes head to NULL

    void insertAtBeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void display(){
        if(!head){
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList list1;

    list1.insertAtBeginning(10);
    list1.insertAtBeginning(20);

    list1.display();
    return 0;
}