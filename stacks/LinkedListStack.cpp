//Stack implementation using linked list

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

class Stack{
    Node* top;

    public:
    //Constructor
    Stack() : top(NULL) {};

    //Destructor
    ~Stack(){
        while(top != NULL){
            pop(); //Clean up memory
        }
    }

    void push(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout<<"Value pushed to stack."<<endl;
    }

    void pop(){
        if(!isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout<< temp->data <<" popped from stack"<<endl;
        delete temp;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Empty Stack!"<<endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty(){
        return top == NULL;
    }
    void display(){
        if(isEmpty()){
            cout<<"Empty Stack!"<<endl;
            return;
        }
        Node* temp = top;
        cout<<"Stack: ";
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Stack stack;
    stack.display();

    return 0;
}