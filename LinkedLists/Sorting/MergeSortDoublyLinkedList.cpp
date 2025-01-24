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
    Node *split(Node *head){
        Node *fast = head;
        Node *slow = head;

        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        Node *temp = slow->next;
        slow->next = nullptr;
        if(temp != nullptr){
            temp->prev = nullptr;
        }
        return temp;
    }
    Node *merge(Node *first, Node *second){
        if(first == nullptr) return second;
        if(second == nullptr) return first;

        if(first->data < second->data){
            first->next = merge(first->next, second);
            if(first->next != nullptr){
                first->next->prev = first;
            }
            first->prev = nullptr;
            return first;
        }else{
            second->next = merge(first, second->next);
            if(second->next != nullptr){
                second->next->prev = second;
            }
            second->prev = nullptr;
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
        cout<<"nullptr <-> ";
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

    for(int i=0;i<5;i++){
        list.insertAtBeginning(i);
    }
    list.display(); //nullptr <-> 4 <-> 3 <-> 2 <-> 1 <-> 0 <-> nullptr

    list.head = list.mergeSort(list.head);
    list.display();
    return 0;
}