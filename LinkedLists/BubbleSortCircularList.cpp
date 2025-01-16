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
    void bubbleSort(){
        int len = getlen();
        int itr = 0;
        bool swapped;

        while(itr < len){
            Node *trav = head;
            Node *prevN = head;
            swapped = false;
            do{
                Node *ptr = trav->next;
                if(trav->data > ptr->data){
                    swapped = true;
                    if(trav == head){
                        trav->next = ptr->next;
                        ptr->next = trav->next;
                        prevN = ptr;
                        head = prevN;
                    }else{
                        trav->next = ptr->next;
                        ptr->next = trav->next;
                        prevN->next = ptr;
                        prevN = ptr;
                    }
                    continue;
                }
                prevN = trav;
                trav = trav->next;
            }while(trav != head);
            if(!swapped){
                break;
            }
            itr++;
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
        cout << "HEAD"<<endl;
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
    list.display();

    list.bubbleSort();
    list.display();
    return 0;
}