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
        LinkedList() : head(nullptr) {}

        void insertAtBeginning(int val){
            Node *newNode = new Node();
            newNode->data = val;
            newNode->next = nullptr;
            if(!head){
                head = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }

        int getLength(){
            int len = 0;
            Node *temp = head;
            while(temp){
                len++;
                temp = temp->next;
            }
            return len;
        }

        void bubbleSort(){
            int len = getLength();
            int itr = 0;
            bool swapped;

            while(itr < len){
                Node *traverseNode = head;
                Node *prevNode = head;
                swapped = false;

                while(traverseNode->next){
                    Node *nextNode = traverseNode->next;
                    if(traverseNode->data > nextNode->data){
                        swapped = true;
                        if(traverseNode == head){
                            traverseNode->next = nextNode->next;
                            nextNode->next = traverseNode;
                            prevNode = nextNode;
                            head = prevNode;
                        }else{
                            traverseNode->next = nextNode->next;
                            nextNode->next = traverseNode;
                            prevNode->next = nextNode;
                            prevNode = nextNode;
                        }
                        continue;
                    }
                    prevNode = traverseNode;
                    traverseNode = traverseNode->next;
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
            Node *temp= head;
            while(temp){
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<"nullptr"<<endl;
        }
};

int main(){
    LinkedList list;
    list.display(); //Empty List!

    for(int i=0; i<=5 ; i++){
        list.insertAtBeginning(i);
    }
    list.display(); //5 -> 4 -> 3 -> 2 -> 1 -> 0 -> nullptr

    list.bubbleSort();
    list.display(); //0 -> 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    return 0;
}