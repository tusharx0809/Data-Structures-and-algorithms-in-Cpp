// This program contains operation(Insertion, deletion and reverse) on Doubly Linked Lists.


#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}; // Constructor initializes head pointer to nullptr;

    // Insertion
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (!head)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (!head)
        {
            head = newNode;
        }
        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertAtPosition(int value, int position)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (!head)
        {
            cout << "List is empty" << endl;
        }
        if (head == nullptr || position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        int pos = 1;
        Node *temp = head;
        while (position - 1 != pos)
        {
            pos++;
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
    }
    // Deletion
    void deleteFromBeginning()
    {
        if (!head)
        {
            cout << "List is empty!";
            return;
        }
        Node *temp = head;
        head = head->next;

        delete temp;
    }
    void deleteFromEnd()
    {
        if (!head)
        {
            cout << "List is empty!";
            return;
        }
        Node *temp = head;

        while (temp->next->next)
        { // Traverse till second last node
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void deleteFromPosition(int position)
    {
        if (!head)
        {
            cout << "List is empty!";
        }
        if (position == 1)
        {
            deleteFromBeginning();
            return;
        }
        Node *temp = head;
        int pos = 1;
        while (position - 1 != pos)
        {
            pos++;
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        delNode->next->prev = temp;
        delete delNode;
    }

    void reverse(){
        if(!head){
            cout<<"List is empty";
            return;
        }
        if(!head->next){
            return;
        }
        Node* nextNode = nullptr;
        Node* cur = head;
        Node* prevNode = nullptr;

        while(cur){
            nextNode = cur->next;
            cur->next = prevNode;
            cur->prev = nextNode;
            prevNode = cur;
            cur = nextNode;
        }
        head=prevNode;
    }
    void recursiveReverseHelper(Node* cur, Node*& newHead){
        if(!cur){
            return;
        }
        if(!cur->next){
            newHead = cur;
            return;
        }
        recursiveReverseHelper(cur->next, newHead);
        cur->next->next = cur;
        cur->prev = cur->next;
        cur->next = nullptr;
    }
    void recursiveReverse(){
        Node* newHead = nullptr;
        recursiveReverseHelper(head, newHead);
        head = newHead;
    }

    void stackReverse(){
        stack<Node*> st;

        if(!head){
            cout<<"Empty List!"<<endl;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            st.push(temp);
            temp = temp->next;
        }

        head = temp;
        while(!st.empty()){
            temp->next = st.top();
            temp->next->prev = temp;
            st.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
        head->prev = nullptr;
    }
    void display()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        cout << "nullptr <-> ";
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    DoublyLinkedList list1;
    list1.display(); // List is empty!

    for (int i = 0; i < 8; i += 2)
    {
        if (i > 0) // Adding even numbers greater than 0 and less than 8
        {
            list1.insertAtBeginning(i);
        }
    }
    list1.display(); // nullptr <-> 6 <-> 4 <-> 2 <-> nullptr

    for (int i = 0; i < 8; i += 2)
    {
        if (i > 0) // Adding even numbers greater than 0 and less than 8
        {
            list1.insertAtEnd(i);
        }
    }
    list1.display(); // nullptr <-> 6 <-> 4 <-> 2 <-> 2 <-> 4 <-> 6 <-> nullptr

    list1.insertAtPosition(5, 2);
    list1.display(); // nullptr <-> 6 <-> 5 <-> 4 <-> 2 <-> 2 <-> 4 <-> 6 <-> nullptr

    list1.insertAtPosition(7, 1); // nullptr <-> 7 <-> 6 <-> 5 <-> 4 <-> 2 <-> 2 <-> 4 <-> 6 <-> nullptr
    list1.display();

    list1.deleteFromBeginning();
    list1.display(); // nullptr <-> 6 <-> 5 <-> 4 <-> 2 <-> 2 <-> 4 <-> 6 <-> nullptr

    list1.deleteFromEnd();
    list1.display(); // nullptr <-> 6 <-> 5 <-> 4 <-> 2 <-> 2 <-> 4 <-> nullptr

    list1.deleteFromPosition(3);
    list1.display(); // nullptr <-> 6 <-> 5 <-> 2 <-> 2 <-> 4 <-> nullptr

    list1.reverse(); 
    list1.display(); //nullptr <-> 4 <-> 2 <-> 2 <-> 5 <-> 6 <-> nullptr

    list1.recursiveReverse();
    list1.display(); //nullptr <-> 6 <-> 5 <-> 2 <-> 2 <-> 4 <-> nullptr

    list1.stackReverse();
    list1.display(); //nullptr <-> 4 <-> 2 <-> 2 <-> 5 <-> 6 <-> nullptr
    return 0;
}
