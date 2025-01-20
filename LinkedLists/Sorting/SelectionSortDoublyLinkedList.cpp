#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node * prev;
};

class DoublyLinkedList{
    Node *head;

    public:
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
                cout<<"List empty!"<<endl;
                return;
            }
            Node *temp = head;
            cout<<"NULL <->";
            while(temp){
                cout<<temp->data<<" <-> ";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    DoublyLinkedList list;
    list.display(); //List empty!

    for(int i=0;i<5;i++){
        list.insertAtBeginning(i);
    }
    list.display(); //NULL <->4 <-> 3 <-> 2 <-> 1 <-> 0 <-> NULL
    return 0;
}