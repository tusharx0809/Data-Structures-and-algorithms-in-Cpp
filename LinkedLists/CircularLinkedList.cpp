//This program includes operations(insertion, deletion and reverse) on a Circular linked list



    // --->  1 -> 2 -> 3 -> 4 --
    // |_______________________|



#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

class CircularLinkedList{
    Node* head;

    public:
    CircularLinkedList() : head(NULL) {};

    //Insertions
    void insertAtBeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;
        if(!head){
            head = newNode;
            newNode->next = head;
        }else{      
            Node*temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtEnd(int value){
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
            newNode->next = head;
        }
    }
    void insertAtPosition(int value, int position){
        Node* newNode = new Node();
        newNode->data = value;
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
        temp->next = newNode;
    }

    //Deletions
    void deleteFromBeginning(){
        if(!head){
            cout<<"List is empty!";
        }
        Node* delNode= head;
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        delete delNode;
    }
    void deleteFromEnd(){
        if(!head){
            cout<<"List is empty!";
        }
        Node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = head;
        delete delNode;
    }
    void deleteFromPosition(int position){
        if(!head){
            cout<<"List is empty!";
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
        delete delNode;
    }
    void reverse(){
        if(!head){
            cout<<"List is empty!";
        }
        if(!head->next){
            return;
        }
        
        Node* prevNode = NULL;
        Node* cur = head;
        Node* nextNode = NULL;
    
        do{
            nextNode = cur->next;
            cur->next = prevNode;
            prevNode = cur;
            cur = nextNode;
        }while(cur != head);

        head->next = prevNode;
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
        cur->next = newHead;
    }
    void recursiveReverse(){
        Node* newHead = NULL;
        recursiveReverseHelper(head, newHead);
        head = newHead;
    }
    void display(){
        if(!head){
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head); // Stop when we return to the head
        cout << "HEAD" << endl;
    }
};

int main(){
    CircularLinkedList list1;
    list1.display(); //List is empty!
    for(int i=0;i<5;i++){
        list1.insertAtBeginning(i);
    }
    list1.display(); //4 -> 3 -> 2 -> 1 -> 0 -> HEAD

    for(int i=5;i>0;i--){
        list1.insertAtEnd(i);
    }
    list1.display(); //4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 -> HEAD

    list1.insertAtPosition(100,3);
    list1.display(); //4 -> 3 -> 100 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 -> HEAD

    list1.insertAtPosition(50,1);
    list1.display(); //50 -> 4 -> 3 -> 100 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 -> HEAD

    list1.deleteFromBeginning();
    list1.display(); //4 -> 3 -> 100 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> 1 -> HEAD

    list1.deleteFromEnd();
    list1.display(); //4 -> 3 -> 100 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> HEAD

    list1.deleteFromPosition(3);
    list1.display(); //4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> HEAD

    list1.deleteFromPosition(1);
    list1.display(); //3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> HEAD

    list1.insertAtBeginning(100);
    list1.display(); //100 -> 3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> HEAD

    list1.reverse();
    list1.display(); //2 -> 3 -> 4 -> 5 -> 0 -> 1 -> 2 -> 3 -> 100 -> HEAD

    list1.recursiveReverse();
    list1.display(); //100 -> 3 -> 2 -> 1 -> 0 -> 5 -> 4 -> 3 -> 2 -> HEAD
    return 0;
}