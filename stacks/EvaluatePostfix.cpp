//Cpp program to evaluate Postfix expression

#include<bits/stdc++.h>
using namespace std;

float evaluatePostfix(string exp){
    stack<string> st;
    float answer;
    string num;

    for(int i=0; i<exp.length();i++){
        char c = exp[i];
        if(c == ' '){
            continue;
        }
        if(isdigit(exp[i])){
            while(i<exp.length() && (isdigit(c) || exp[i] == '.')){
                num += s[i];
                i++;
            }
            st.push(num);
        }
    }
}

int main(){
    string exp = "10 20.4 30 4 ^ 50 - 6 70.32 8 * + ^ * 90 - +";
    float result = evaluatePostfix(exp);

    cout<<result;
    return 0;
}