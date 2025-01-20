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
            newNode->next = NULL;

            if(!head){
                head = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }
        
        void selectionSort(){
            if(!head || !head->next){
                return;
            }
            
            Node *current = head;

            while(current){
                Node *minNode = current;
                Node *searcher = current->next;
                while(searcher){
                    if(searcher->data < current->data){
                        minNode = searcher;
                    }
                    searcher = searcher->next;
                }
                swap(minNode->data, current->data);
                current = current->next;
            }

        }

        void display(){
            if(!head){
                cout<<"Empty List!"<<endl;
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

    for(int i=0;i<5;i++){
        list.insertAtBeginning(i);
    }
    list.display();
    
    list.selectionSort();
    list.display();
    return 0;
}