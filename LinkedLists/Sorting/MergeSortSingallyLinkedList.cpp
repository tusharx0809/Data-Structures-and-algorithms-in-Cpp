//CPP program to merge sort Singally Linked List

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class LinkedList{
    
    public:
        Node *head;
        LinkedList() : head(NULL) {}

        void insertAtBeginning(int value){
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }

        Node *split(Node *head){
            Node *fast = head;
            Node *slow = head;

            while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                if(fast != NULL){
                    slow = slow->next;
                }
            }
            Node *temp = slow->next;
            slow->next = NULL;
            return temp;
        }

        Node *merge(Node *first, Node *second){
            if(first == NULL) return second;
            if(second == NULL) return first;

            if(first->data < second->data){
                first->next = merge(first->next, second);
                return first;
            }else{
                second->next = merge(first, second->next);
                return second;
            }
        }

        Node  *mergeSort(Node *head){
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
                cout<<"List empty!"<<endl;
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
    list.display(); //List empty!

    for(int i=0;i<5;i++){
        list.insertAtBeginning(i);
    }
    list.display(); //4 -> 3 -> 2 -> 1 -> 0 -> NULL
    list.head = list.mergeSort(list.head);
    list.display(); //0 -> 1 -> 2 -> 3 -> 4 -> NULL
    return 0; 
}