//CPP program to implement queue using linked list

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct node *next;
};

class Queue{
    Node *front;
    Node *tail;

    public:
        Queue() : front(nullptr), tail(nullptr) {}
};

int main(){
    return 0;
}