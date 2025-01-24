//CPP program to implement queue using linked list

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class Queue{
    Node *front;
    Node *tail;
    int size;
    int capacity;

    public:
        Queue(int c) : front(nullptr), tail(nullptr), size(0), capacity(c) {}

        ~Queue() {
            while (tail != nullptr) {
                Node* temp = tail;  // Store the current front
                tail = tail->next; // Move to the next node
                delete temp;         // Delete the old front
            }
            front = nullptr; // Ensure tail is also nullptr after cleanup
        }

        void enqueue(int data){
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;

            if(!tail){
                tail = newNode;
                front = newNode;
                size++;
                return;
            }

            if(size == capacity){
                cout<<"Queue is full, cannot insert!"<<endl;
                return;
            }else{
                newNode->next = tail;
                tail = newNode;
                size++;
            }
            Node *temp = tail;
            while(temp->next != NULL){
                temp = temp->next;
            }
            front = temp;              
        }
        
        void getFront(){
            if(!tail){
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<front->data<<endl;
        }

        void dequeue(){
            if(!tail){
                cout<<"Queue is empty"<<endl;
                return;
            }
            if(!tail->next){
                delete tail;
                return;
            }
            Node *delNode = front;
            Node *temp = tail;
            while(temp->next != front){
                temp = temp->next;
            }
            front = temp;
            front->next = nullptr;
            delete delNode;
            size--;
        }

        void display(){
            if(!tail){
                cout<<"Queue is empty"<<endl;
                return;
            }
            Node *temp= tail;
            cout<<"TAIL ->";
            while(temp != nullptr){
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"FRONT"<<endl;
        }

};

int main(){

    Queue q(5); //Initialize queue of capacity 5
    q.display(); //Queue is empty

    for(int i=0;i<5;i++){
        q.enqueue(i);
    }
    q.display(); //TAIL ->4 -> 3 -> 2 -> 1 -> 0 -> FRONT
    q.enqueue(5); //Queue is full, cannot insert!

    q.getFront(); //0
    
    q.dequeue();
    q.display();  //TAIL ->4 -> 3 -> 2 -> 1 -> FRONT , 0 dequeued

    q.getFront(); //1

    q.enqueue(5);
    q.display(); //TAIL ->5 -> 4 -> 3 -> 2 -> 1 -> FRONT
    return 0;
}