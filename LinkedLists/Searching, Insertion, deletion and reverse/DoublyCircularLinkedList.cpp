//This program consists operations on Doubly Circular Linked Lists

#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class DoublyCircularLinkedList{
    Node* head;

    public:
    DoublyCircularLinkedList() : head(nullptr) {};

    //Insertion
    void insertAtBeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;
        if(!head){
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
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

    //Deletion
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
    void deleteFromEnd(){
        if(!head){
            cout<<"List is empty!";
            return;
        }
        Node*temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = head;
        head->prev = temp;
        delete delNode;
    }
    void deleteFromPosition(int position){
        if(!head){
            cout<<"List is empty!";
            return;
        }
        if(position == 1){
            deleteFromBeginning();
            return;
        }
        int pos = 1;
        Node* temp = head;
        while(position-1 != pos){
            pos++;
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delNode->next->prev = temp;
        delete delNode;
    }

    void reverse(){
        if(!head){
            cout<<"List is empty!";
        }
        if(!head->next){
            return;
        }
        Node* nextNode = nullptr;
        Node* cur = head;
        Node* prevNode = nullptr;

        Node* originalNext = head->next;

        do{
            nextNode = cur->next;
            cur->next = prevNode;
            cur->prev = nextNode;
            prevNode = cur;
            cur = nextNode;
        }while(cur != head);

        head->next = prevNode;
        head->prev = originalNext;
        head = prevNode;
    }
    void recursiveReverseHelper(Node* cur, Node*& newHead){
        if(!cur){
            return;
        }
        if(cur->next == head){
            newHead = cur;
            return;
        }
        recursiveReverseHelper(cur->next, newHead);
        cur->next->next = cur;
        cur->prev = cur->next;
        cur->next = newHead;
    }
    void recursiveReverse(){
        Node* newHead = nullptr;
        recursiveReverseHelper(head, newHead);
        head = newHead;
    }

    void stackReverse(){
        stack<Node*> st;
        if(!head){
            cout<<"List Empty!"<<endl;
            return;
        }

        Node * temp = head;
        do{
            st.push(temp);
            temp = temp->next;
        }while(temp->next != head);

        head = temp;
        while(!st.empty()){
            temp->next = st.top();
            temp->next->prev = temp;
            st.pop();
            temp = temp->next;
        }
        temp->next = head;
        head->prev = temp;
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
    list1.display(); //HEAD <-> 3 <-> 40 <-> 2 <-> 1 <-> 0 <-> 5 <-> 4 <-> 3 <-> 2 <-> 1 <-> HEAD

    list1.deleteFromEnd();
    list1.display(); //HEAD <-> 3 <-> 40 <-> 2 <-> 1 <-> 0 <-> 5 <-> 4 <-> 3 <-> 2 <-> HEAD

    list1.deleteFromPosition(2);
    list1.display(); //HEAD <-> 3 <-> 2 <-> 1 <-> 0 <-> 5 <-> 4 <-> 3 <-> 2 <-> HEAD

    list1.reverse();
    list1.display(); //HEAD <-> 2 <-> 3 <-> 4 <-> 5 <-> 0 <-> 1 <-> 2 <-> 3 <-> HEAD

    list1.recursiveReverse();
    list1.display(); // HEAD <-> 3 <-> 2 <-> 1 <-> 0 <-> 5 <-> 4 <-> 3 <-> 2 <-> HEAD

    list1.stackReverse();
    list1.display(); //HEAD <-> 2 <-> 3 <-> 4 <-> 5 <-> 0 <-> 1 <-> 2 <-> 3 <-> HEAD
    return 0;
}