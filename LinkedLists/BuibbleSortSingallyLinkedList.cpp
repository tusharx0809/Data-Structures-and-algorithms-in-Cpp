//CPP program to bubble sort a Singally linked list

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class LinkedList{
    Node* head;

    public:
        LinkedList() : head(NULL) {}

        void insertAtBeginning(int val){
            Node *newNode = new Node();
            newNode->data = val;
            newNode->next = NULL;
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
            Node *temp= head;
            while(temp){
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL";
        }
};

int main(){
    LinkedList list;
    list.display();

    for(int i=0; i<=5 ; i++){
        list.insertAtBeginning(i);
    }
    list.display();
    return 0;
}