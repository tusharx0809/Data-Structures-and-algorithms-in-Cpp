//CPP program to merge sort Singally Linked List

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class LinkedList{
    Node *head;

    public:
        LinkedList() : head(NULL) {}

        void insertAtBeginning(int value){
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }

        void display(){
            if(!head){
                cout<<"List empty!"<<endl;
                return;
            }
            Node *temp = head;
            while(temp){
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    LinkedList list;
    list.display();
    return 0;
}