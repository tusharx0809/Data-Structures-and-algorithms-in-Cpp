//CPP program to reverse string using stack

#include<bits/stdc++.h>
using namespace std;

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
    cout<<revS;
    return 0;
}