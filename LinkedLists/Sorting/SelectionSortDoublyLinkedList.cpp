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
        DoublyLinkedList() : head(nullptr) {}

        void insertAtBeginning(int value){
            Node *newNode = new Node();
            newNode->data = value;
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

        void selectionSort(){
            if(!head || !head->next) return;

            Node *current = head;

            while(current){
                Node *minNode = current;
                Node *search = current->next;
                while(search){
                    if(search->data < minNode->data){
                        minNode = search;
                    }
                    search=search->next;
                }
                if(minNode != current){
                    swap(current->data, minNode->data);
                }
                current = current->next;
            }
        }

        void display(){
            if(!head){
                cout<<"List empty!"<<endl;
                return;
            }
            Node *temp = head;
            cout<<"nullptr <->";
            while(temp){
                cout<<temp->data<<" <-> ";
                temp = temp->next;
            }
            cout<<"nullptr"<<endl;
        }
};

int main(){
    DoublyLinkedList list;
    list.display(); //List empty!

    for(int i=0;i<5;i++){
        list.insertAtBeginning(i);
    }
    list.display(); //nullptr <->4 <-> 3 <-> 2 <-> 1 <-> 0 <-> nullptr

    list.selectionSort();
    list.display(); //nullptr <->0 <-> 1 <-> 2 <-> 3 <-> 4 <-> nullptr
    return 0;
}