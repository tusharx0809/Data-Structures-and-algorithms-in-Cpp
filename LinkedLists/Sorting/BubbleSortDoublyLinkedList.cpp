//CPP program to bubble sort Doubly Linked List

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

class DoublyLinkedList{
    Node* head;
    public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val){
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if(!head){
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    int getlen(){
        int len=0;
        Node *temp = head;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }
    void bubbleSort(){
        int len = getlen();
        int itr = 0;
        bool swapped;

        while(itr < len){
            Node *trav = head;
            Node *prevN = head;
            swapped = false;
            while(trav->next){
                Node *nextNode = trav->next;
                if(trav->data > nextNode->data){
                    swapped = true;
                    if(trav == head){
                        trav->next = nextNode->next;
                        nextNode->next = trav;
                        nextNode->prev = trav->prev;
                        trav->prev = nextNode;
                        prevN = nextNode;
                        head = prevN;
                    }else{
                        trav->next = nextNode->next;
                        nextNode->next = trav;
                        nextNode->prev = trav->prev;
                        trav->prev = nextNode;
                        prevN->next = nextNode;
                        prevN = nextNode;
                    }
                    continue;
                }
                prevN = trav;
                trav = trav->next;
            }
            if(!swapped){
                break;
            }
            itr++;
        }
    }
    void display(){
        if(!head){
            cout<<"Empty List!"<<endl;
            return;
        }
        cout<< "nullptr <-> ";
        Node *temp = head;
        while(temp){
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<"nullptr"<<endl;
    }
};

int main(){
    DoublyLinkedList list;
    list.display(); //Empty List!

    for(int i=0;i<=5;i++){
        list.insertAtBeginning(i);
    }
    list.display(); //nullptr <-> 5 <-> 4 <-> 3 <-> 2 <-> 1 <-> 0 <-> nullptr

    list.bubbleSort();
    list.display(); //nullptr <-> 0 <-> 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> nullptr
    return 0;
}