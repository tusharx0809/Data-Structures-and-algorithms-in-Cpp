//CPP program to evaluate Prefix expressions

#include<bits/stdc++.h>
using namespace std;
bool isOperator(char x){
    return (x == '^' || x == '/' || x == '*' || x == '+' || x == '-');
}
string reverseFloatingNumber(string exp){
    string result="";
    for(int i = exp.length()-1; i >=0; i--){
        result += exp[i];
    }
    return result;
}
float evaluatePrefix(string exp){
    stack<float> st;
    string num;

    for(int i=exp.length(); i>=0; i--){
        char c = exp[i];
        
        if(c == ' '){
            continue;
        }
        if(isdigit(c)){
           num += c;
           if(i-1 == 0 || (!isdigit(exp[i-1]) && exp[i-1] != '.')){
                st.push(stof(reverseFloatingNumber(num)));
                num = "";
           }              
        }else if(isOperator(c)){
            float num1 = st.top();
            st.pop();
            float num2 = st.top();
            st.pop();
            switch(exp[i]){
                case('^'):
                    st.push(pow(num2, num1));
                    break;
                case('/'):
                    st.push(num2 / num1);
                    break;
                case('*'):
                    st.push(num2 * num1);
                    break;
                case('+'):
                    st.push(num2 + num1);
                    break;
                case('-'):
                    st.push(num2 - num1);
                    break;
            } 
        }
    }
    return st.top();
}
int main(){

    string exp = "+ 3.5 * ^ 4 2 - 6 2";
    float result = evaluatePrefix(exp);
    cout<<result;

    return 0;
}