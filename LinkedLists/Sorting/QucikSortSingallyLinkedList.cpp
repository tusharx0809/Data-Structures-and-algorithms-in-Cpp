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
        LinkedList() : head(nullptr) {}

        void insertAtBeginning(int value){
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }
        Node *getTail(Node *cur){
            while(cur != nullptr && cur->next != nullptr){
                cur = cur->next;
            }
            return cur;
        }

        Node *partition(Node *head, Node *tail){
            Node *pivot = head;

            Node *pre = head;
            Node *cur = head;

            while(cur != tail->next){
                if(cur->data < pivot->data){
                    swap(cur->data, pre->next->data);
                    pre = pre->next;
                }
                cur = cur->next;
            }
            swap(pivot->data, pre->data);
            return pre;
        }

        void quickSortHelper(Node *head, Node *tail){
            if(head == nullptr || head == tail){
                return;
            }

            Node *pivot = partition(head, tail);
            quickSortHelper(head, pivot);
            quickSortHelper(pivot->next, tail);
        }


        Node *quickSort(Node *head){
            Node *tail = getTail(head);
            quickSortHelper(head, tail);
            return head;
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
            cout<<"nullptr"<<endl;
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

    list.head = list.quickSort(list.head);
    list.display();
    return 0;
}