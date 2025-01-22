//CPP program to reverse string using stack

#include<bits/stdc++.h>
using namespace std;

class Stack{
    vector<char> arr;
    
    public:

    void push(char value){
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

    char peek(){
        if(isEmpty()){
            cout<<"Empty Stack!"<<endl;
            return -1;
        }
        return arr.back();
    }
    bool isEmpty(){
        return arr.empty();
    }

    void reverse(){
        vector<char> revArr;
        if(isEmpty()){
            cout<<"Empty Stack!"<<endl;
        }

        while(!isEmpty()){
            revArr.push_back(arr.back());
            arr.pop_back();
        }

        arr = revArr;
    }
    
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        cout<<"Stack Elements: ";
        for(char ele: arr){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
};

string reverseString(string s){
    stack<char> st;
    string result;

    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }

    while(!st.empty()){
        result += st.top();
        st.pop();
    }

    return result;

}

int main(){
    string s = "reversethisstring";
    string revS = reverseString(s);
    cout<<revS<<endl; //gnirtssihtesrever

    
    Stack st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }
    st.display(); //Stack Elements: r e v e r s e t h i s s t r i n g
    st.reverse();
    st.display(); //Stack Elements: g n i r t s s i h t e s r e v e r
    return 0;
}