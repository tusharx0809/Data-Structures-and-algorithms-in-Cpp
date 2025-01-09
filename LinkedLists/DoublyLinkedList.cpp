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

    void display()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
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
    list1.display();

    for (int i = 0; i < 8; i += 2)
    {
        if (i > 0)
        {
            list1.insertAtBeginning(i);
        }
    }
    list1.display();
    return 0;
}
