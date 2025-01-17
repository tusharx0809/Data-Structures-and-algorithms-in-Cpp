//CPP program to bubble sort doubly circular list

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

class DoublyCircularList{
    Node *head;

    public:
        DoublyCircularList() : head(NULL) {};

        void insertAtBeginning(int value){
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = NULL;

            if(!head){
                head = newNode;
                newNode->next = head;
                newNode->prev = head;
                return;
            }
            Node *temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            newNode->prev = temp;
            head = newNode;
        }

        void display(){
            if(!head){
                cout<<"Empty List!"<<endl;
                return;
            }
            cout<<"HEAD <-> ";
            Node *temp = head;
            do{
                cout<<temp->data<<" <-> ";
                temp = temp->next;
            }while(temp != head);
            cout<<"HEAD"<<endl;
        }
};

int main(){
    DoublyCircularList list;
    for(int i=0; i<5; i++){
        list.insertAtBeginning(i);
    }
    list.display();
    return 0;
}