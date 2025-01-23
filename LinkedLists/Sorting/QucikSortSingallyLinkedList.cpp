//CPP to program to quick sort Singally Linked List

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class LinkedList{
    public:
        Node *head;
        LinkedList() : head(NULL) {}

        void insertAtBeginning(int value){
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }

        void display(){
            if(!head){
                cout<<"Empty List!"<<endl;
                return;
            }
            Node *temp = head;
            while(temp){
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    LinkedList list;
    list.display();

    // Initialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 6);

    set<int> generatedNumbers; // To ensure no duplicates
    for (int i = 0; i < 5; i++) {
        int generated;
        do {
            generated = dis(gen);
        } while (generatedNumbers.find(generated) != generatedNumbers.end());
        generatedNumbers.insert(generated);
        list.insertAtBeginning(generated);
    }

    list.display();
    return 0;
}