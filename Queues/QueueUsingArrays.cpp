//CPP implementation of queue usign arrays

#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int *queue; //array to hold queue elements
        int front; //index for front element
        int size; //current size of queue
        int capacity; //capacity of queue

    public:
        Queue(int c){ //Constructor to initialize the queue
            queue = new int[c];
            front = 0;
            size = 0;
            capacity = c;
        }

        ~Queue(){ // Destrcutor to delete the allocated memory
            delete[] queue;
        }

        void enqueue(int data){ //function to insert an element at the rear of queue
            if(size == capacity){
                cout<<"Queue is full"<<endl;
                return;
            }
            queue[front+size] = data;
            size++;
        }

        void dequeue(){
            if(size == 0){
                cout<<"Queue is empty"<<endl;
                return;
            }
            for(int i=1;i<size;i++){
                queue[i-1] = queue[i];
            }
            size--;
        }

        void display(){
            if(size == 0){
                cout<<"Queue is empty"<<endl;
                return;
            }

            for(int i=0;i<size;i++){
                cout<< queue[i]<<" <- ";
            }
            cout<<endl;
        }

        void getFront(){
            if(size == 0){
                cout << "Queue is empty"<<endl;
            }else{
                cout<<"Front element of queue is: "<<queue[front]<<endl;
            }
        }
};

int main(){
    Queue q(5);
    q.display();
    return 0;
}