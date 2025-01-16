// CPP program to bubble sort Circular linked list

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList() : head(NULL) {}

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if (!head)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
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
        if (!head || head->next == head) return;  // Empty list or single node
        
        int len = getlen();
        for (int i = 0; i < len - 1; i++)
        {
            Node *current = head;
            Node *prev = NULL;
            Node *tail = head;
            while (tail->next != head) tail = tail->next;  // Find tail
            
            for (int j = 0; j < len - i - 1; j++)
            {
                Node *nextNode = current->next;
                
                if (current->data > nextNode->data)
                {
                    // Swap nodes
                    if (current == head)
                    {
                        current->next = nextNode->next;
                        nextNode->next = current;
                        head = nextNode;
                        tail->next = head;
                        prev = nextNode;
                    }
                    else
                    {
                        current->next = nextNode->next;
                        nextNode->next = current;
                        prev->next = nextNode;
                        prev = nextNode;
                    }
                }
                else
                {
                    prev = current;
                    current = current->next;
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
        Node *temp = head;
        cout << "HEAD -> ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
};

int main()
{
    CircularLinkedList list;
    list.display(); // Empty List!

    for (int i = 0; i <= 5; i++)
    {
        list.insertAtBeginning(i);
    }
    list.display(); // HEAD -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> HEAD
    list.bubbleSort();
    list.display();

    return 0;
}