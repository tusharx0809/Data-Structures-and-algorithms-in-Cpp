// CPP program to implement priority queue using linked list

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int priority;
    Node *next;

    Node(int d, int p){
        data = d;
        priority = p;
        next = nullptr;
    }
};

Node *head = nullptr;

void push(int val, int pri)
{
    Node *newNode = new Node(val, pri);
    

    if (head == nullptr || head->priority < pri)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != nullptr && temp->next->priority >=pri){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int peek()
{
    if (head == nullptr)
    {
        cout << "Priority Queue is empty!\n";
        return -1;
    }
    return head->data;
}

void pop()
{
    if (head == nullptr) {
        cout << "Priority Queue is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

int main()
{

    push(4, 1);
    push(5, 2);
    push(6, 3);
    push(7, 0);

    while(head){
        cout<<peek()<<" ";
        pop();
    }
    //6 5 4 7
    return 0;
}