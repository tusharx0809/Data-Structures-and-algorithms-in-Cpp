#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList
{
    Node *head; // Pointer to the first node

public:
    LinkedList() : head(NULL) {} // Constructor intitializes head to NULL

    // Insertion
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void insertAtPosition(int value, int position)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
        }

        int pos = 1;

        Node *temp = head;
        while (position - 1 != pos)
        {
            pos++;
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // Deletion
    void deleteFromBegenning()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        temp = temp->next;
        head = temp;
    }
    void deleteFromEnd()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (!head->next)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        // Traverse to second last node
        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void deleteFromPosition(int position)
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if(position == 1){
            head = head->next;
            return;
        }
        int pos = 1;
        Node *temp = head;
        while (position - 1 != pos)
        {
            pos++;
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    void reverse()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL)
        {
            return;
        }

        Node *prev = NULL;
        Node *cur = head;
        Node *next = NULL;

        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void recursiveReverseHelper(Node *cur, Node *&newHead)
    {
        if (!cur)
        {
            return;
        }
        if (!cur->next)
        {
            newHead = cur;
            return;
        }
        recursiveReverseHelper(cur->next, newHead);
        cur->next->next = cur;
        cur->next = NULL;
    }

    void recursiveReverse()
    {
        Node *newHead = NULL;
        recursiveReverseHelper(head, newHead);
        head = newHead;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list1;
    list1.display(); // List is empty!

    for (int i = 0; i < 7; i += 2)
    {
        list1.insertAtBeginning(i);
    }
    list1.display(); // 6 -> 4 -> 2 -> 0 -> NULL

    for (int i = 0; i < 7; i += 2)
    {
        list1.insertAtEnd(i);
    }
    list1.display(); // 6 -> 4 -> 2 -> 0 -> 0 -> 2 -> 4 -> 6 -> NULL

    list1.insertAtPosition(5, 2); // 6 -> 5 -> 4 -> 2 -> 0 -> 0 -> 2 -> 4 -> 6 -> NULL
    list1.display();

    list1.deleteFromBegenning();
    list1.display(); // 5 -> 4 -> 2 -> 0 -> 0 -> 2 -> 4 -> 6 -> NULL

    list1.deleteFromEnd();
    list1.display(); // 5 -> 4 -> 2 -> 0 -> 0 -> 2 -> 4 -> NULL

    list1.deleteFromPosition(3);
    list1.display(); // 5 -> 4 -> 0 -> 0 -> 2 -> 4 -> NULL

    list1.reverse();
    list1.display(); // 4 -> 2 -> 0 -> 0 -> 4 -> 5 -> NULL Reverse

    list1.recursiveReverse(); // 5 -> 4 -> 0 -> 0 -> 2 -> 4 -> NULL Recursive Reverse
    list1.display();
    return 0;
}