//CPP program to merge sort doubly linked list

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

class DoublyLinkedList{
    public:
    Node *head;
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
    Node *split(Node *head){
        Node *fast = head;
        Node *slow = head;

        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        Node *temp = slow->next;
        slow->next = NULL;
        if(temp != NULL){
            temp->prev = NULL;
        }
        return temp;
    }
    Node *merge(Node *first, Node *second){
        if(first == NULL) return second;
        if(second == NULL) return first;

        if(first->data < second->data){
            first->next = merge(first->next, second);
            if(first->next != NULL){
                first->next->prev = first;
            }
            first->prev = NULL;
            return first;
        }else{
            second->next = merge(first, second->next);
            if(second->next != NULL){
                second->next->prev = second;
            }
            second->prev = NULL;
            return second;
        }

    }
    Node *mergeSort(Node *head){
        if(!head || !head->next){
            return head;
        }
        Node *second = split(head);

        head = mergeSort(head);
        second = mergeSort(second);

        return merge(head, second);
    }

    void display(){
        if(!head){
            cout<<"Empty List!"<<endl;
            return;
        }
        Node *temp = head;
        cout<<"NULL <-> ";
        while(temp){
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    DoublyLinkedList list;
    list.display(); //Empty List!

    for(int i=0;i<5;i++){
        list.insertAtBeginning(i);
    }
    list.display(); //NULL <-> 4 <-> 3 <-> 2 <-> 1 <-> 0 <-> NULL

    list.head = list.mergeSort(list.head);
    list.display();
    return 0;
}