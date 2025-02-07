// CPP program to implement queue using linked list

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Queue
{
    Node *front;
    Node *tail;
    int size;
    int capacity;

public:
    Queue(int c) : front(nullptr), tail(nullptr), size(0), capacity(c) {}

    ~Queue()
    {
        while (tail != nullptr)
        {
            Node *temp = tail; // Store the current front
            tail = tail->next; // Move to the next node
            delete temp;       // Delete the old front
        }
        front = nullptr; // Ensure tail is also nullptr after cleanup
    }

    void enqueue(int data)
    {
        if (size == capacity)
        {
            cout << "Queue is full, cannot insert!" << endl;
            return;
        }

        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (!tail)
        { // Queue is empty
            tail = newNode;
            front = newNode;
        }
        else
        {
            newNode->next = tail;
            tail = newNode;
        }

        size++;
    }

    void getFront()
    {
        if (!tail)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element of queue is: "<<front->data << endl;
    }

    void dequeue()
    {
        if (!tail)
        {
            cout << "Queue is already empty" << endl;
            return;
        }
        if (tail == front)
        {
            delete tail;
            tail = nullptr;
            front = nullptr;
            size--;
            return;
        }
        Node *delNode = front;
        Node *temp = tail;
        while (temp->next != front)
        {
            temp = temp->next;
        }
        front = temp;
        front->next = nullptr;
        delete delNode;
        size--;
    }

    void display()
    {
        if (!tail)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = tail;
        cout << "TAIL ->";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "FRONT" << endl;
    }
};

int main()
{

    Queue q(5);  // Initialize queue of capacity 5
    q.display(); // Queue is empty

    for (int i = 0; i < 5; i++)
    {
        q.enqueue(i);
    }
    q.display();  // TAIL ->4 -> 3 -> 2 -> 1 -> 0 -> FRONT
    q.enqueue(5); // Queue is full, cannot insert!

    q.getFront(); // Front element of queue is: 0

    q.dequeue();
    q.display(); // TAIL ->4 -> 3 -> 2 -> 1 -> FRONT , 0 dequeued

    q.getFront(); // Front element of queue is: 1

    q.enqueue(5);
    q.display(); // TAIL ->5 -> 4 -> 3 -> 2 -> 1 -> FRONT

    for (int i = 0; i < 5; i++)
    {
        q.dequeue();
    }
    q.display(); // Queue is empty

    q.dequeue(); // Queue is already empty
    return 0;
}