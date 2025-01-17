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
            newNode->pev = NULL;

            if(!head){
                head = newNode;
                newNode->next = head;
            }
        }
};