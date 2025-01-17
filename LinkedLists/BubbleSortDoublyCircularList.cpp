// CPP program to bubble sort doubly circular list

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

class DoublyCircularList
{
    Node *head;

public:
    DoublyCircularList() : head(NULL) {};

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (!head)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        newNode->prev = temp;
        head = newNode;
    }
    int getlen()
    {
        int len = 0;
        Node *temp = head;
        do
        {
            len++;
            temp = temp->next;
        } while (temp != head);
        return len;
    }

    void bubbleSort()
    {
        int len = getlen();
        if (!head || !head->next)
            return;

        for (int i = 0; i < len - 1; i++)
        {
            Node *cur = head;
            Node *prevNode = NULL;
            Node *tail = head;
            while (tail->next != head)
                tail = tail->next;
            for (int j = 0; j < len - 1; j++)
            {
                Node *nextNode = cur->next;
                if (cur->data > nextNode->data)
                {
                    if (cur == head)
                    {
                        cur->next = nextNode->next;
                        nextNode->next = cur;
                        nextNode->prev = cur->prev;
                        cur->prev = nextNode;
                        head = nextNode;
                        tail->next = nextNode;
                        prevNode = nextNode;
                    }
                    else
                    {
                        cur->next = nextNode->next;
                        nextNode->next = cur;
                        nextNode->prev = cur->prev;
                        cur->prev = nextNode;
                        prevNode->next = nextNode;
                        prevNode = nextNode;
                    }
                }
                else
                {
                    prevNode = cur;
                    cur = cur->next;
                }
            }
        }
    }

    void display()
    {
        if (!head)
        {
            cout << "Empty List!" << endl;
            return;
        }
        cout << "HEAD <-> ";
        Node *temp = head;
        do
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
};

int main()
{
    DoublyCircularList list;
    list.display(); // Empty List!

    for (int i = 0; i <= 5; i++)
    {
        list.insertAtBeginning(i);
    }
    list.display(); // HEAD <-> 5 <-> 4 <-> 3 <-> 2 <-> 1 <-> 0 <-> HEAD

    list.bubbleSort();
    list.display(); //HEAD <-> 0 <-> 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> HEAD

    return 0;
}