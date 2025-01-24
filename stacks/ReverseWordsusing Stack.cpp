//CPP program to reverse using stack

#include<bits/stdc++.h>
using namespace std;

void reverseWords(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i] != ' '){
            st.push(s[i]);
        }else{
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            cout<<" ";
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}

int main(){
    string s = "Reverse these words";
    reverseWords(s);
    return 0;
}