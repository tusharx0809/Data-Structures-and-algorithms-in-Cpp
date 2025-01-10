//Array implementation of stack

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

class Stack{
    vector<int> arr;

    public:

    void push(int value){
        arr.push_back(value);
        cout<<value<<" pushed onto the stack."<<endl;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack Empty, cannot pop!"<<endl;
            return;
        }
        int topElement = arr.back();
        arr.pop_back();
        cout<<topElement<<" popped from stack."<<endl;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Empty Stack!"<<endl;
            return -1;
        }
        return arr.back();
    }
    bool isEmpty(){
        return arr.empty();
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        cout<<"Stack Elements: ";
        for(int ele: arr){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Stack stack;
    stack.display(); //Stack is empty!

    stack.push(10); //10 pushed onto the stack.
    stack.push(20); //20 pushed onto the stack.
    stack.push(30); //30 pushed onto the stack.
    stack.display(); //Stack Elements: 10 20 30

    stack.pop(); //30 popped from stack.
    stack.display(); //Stack Elements: 10 2

    int top = stack.peek();
    cout<<"Top Element: "<<top<<endl;

    return 0;

}