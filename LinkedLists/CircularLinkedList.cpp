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

    void display(){
        if(!head){
            cout<<"List is empty!";
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
    for(int i=0;i<5;i++){
        list1.insertAtBeginning(i);
    }
    list1.display();
    return 0;
}