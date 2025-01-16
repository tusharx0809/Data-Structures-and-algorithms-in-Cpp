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
                    Node *ptr = traverseNode->next;
                    if(traverseNode->data > ptr->data){
                        swapped = true;
                        if(traverseNode == head){
                            traverseNode->next = ptr->next;
                            ptr->next = traverseNode;
                            prevNode = ptr;
                            head = prevNode;
                        }else{
                            traverseNode->next = ptr->next;
                            ptr->next = traverseNode;
                            prevNode->next = ptr;
                            prevNode = ptr;
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
            cout<<"NULL"<<endl;
        }
};

int main(){
    LinkedList list;
    list.display(); //Empty List!

    for(int i=0; i<=5 ; i++){
        list.insertAtBeginning(i);
    }
    list.display(); //5 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL

    list.bubbleSort();
    list.display(); //0 -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    return 0;
}