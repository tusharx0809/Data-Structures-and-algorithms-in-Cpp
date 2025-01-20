//CPP Program sort a singally linked list using selection sort

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class LinkedList{
    Node *head;

    public:
        LinkedList() : head(NULL) {}

        void insertAtBeginning(int value){
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;

            if(!head){
                head = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }
        
        void selectionSort(){
            if(!head || !head->next){
                return;
            }
            
            Node *current = head;
            Node *prevCurrent = NULL;

            while(current){
                Node *minNode = current;
                Node *prevMin = prevCurrent;
                Node *search = current->next;
                Node *prevSearch = current;

                while(search){
                    if(search->data < minNode->data){
                        minNode = search;
                        prevMin = prevSearch;
                    }
                    prevSearch = search;
                    search = search->next;
                }

                if(minNode != current){
                    Node *temp = minNode->next;

                    if(prevCurrent){
                        prevCurrent->next = minNode;
                    }else{
                        head = minNode;
                    }

                    if(prevMin){
                        prevMin->next = current;
                    }
                    minNode->next = current->next;
                    current->next = temp;
                }
                prevCurrent = (minNode == current) ? current : minNode;
                current = prevCurrent->next;
            }

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

    for(int i=0;i<5;i++){
        list.insertAtBeginning(i);
    }
    list.display();
    
    list.selectionSort();
    list.display();
    return 0;
}