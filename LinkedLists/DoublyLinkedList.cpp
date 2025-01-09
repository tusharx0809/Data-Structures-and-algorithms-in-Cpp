#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
    Node *prev = NULL;
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList() : head(NULL) {}; // Constructor initializes head pointer to NULL;

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

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
        newNode->next = NULL;
        newNode->prev = NULL;

        if (!head)
        {
            head = newNode;
        }
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertAtPosition(int value, int position)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (!head)
        {
            cout << "List is empty" << endl;
        }
        if(head==NULL || position == 1){
            newNode->next = head;
            head = newNode;
            return;
        }
        int pos = 1;
        Node * temp = head;
        while(position-1 != pos){
            pos++;
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        cout << "NULL <-> ";
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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
    list1.display(); // NULL <-> 6 <-> 4 <-> 2 <-> NULL

    for (int i = 0; i < 8; i += 2)
    {
        if (i > 0) // Adding even numbers greater than 0 and less than 8
        {
            list1.insertAtEnd(i);
        }
    }
    list1.display(); // NULL <-> 6 <-> 4 <-> 2 <-> 2 <-> 4 <-> 6 <-> NULL

    list1.insertAtPosition(5, 2);
    list1.display(); //NULL <-> 6 <-> 5 <-> 4 <-> 2 <-> 2 <-> 4 <-> 6 <-> NULL

    list1.insertAtPosition(7,1); //NULL <-> 7 <-> 6 <-> 5 <-> 4 <-> 2 <-> 2 <-> 4 <-> 6 <-> NULL
    list1.display();
    return 0;
}
