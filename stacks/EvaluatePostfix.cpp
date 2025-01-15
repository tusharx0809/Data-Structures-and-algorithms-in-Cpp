//Cpp program to evaluate Postfix expression including digits greater than 9 and floating point numbers

#include<bits/stdc++.h>
using namespace std;

float evaluatePostfix(string exp){
    stack<float> st;
    string num;

    for(int i=0; i<exp.length();i++){
        char c = exp[i];
        if(c == ' '){
            continue;
        }
        if(isdigit(c) || c == '.'){
            num += c;
            if(i+1 == exp.length() || (!isdigit(exp[i+1]) && exp[i+1] != '.')){
                st.push(stof(num));
                num="";
            }
        }else{
            float num1 = st.top();
            st.pop();
            float num2 = st.top();
            st.pop();
            switch (exp[i])
            {
                case '+': 
                    st.push(num2 + num1);
                    break;
                case '-':
                    st.push(num2 - num1);
                    break;
                case '/':
                    st.push(num2 / num1);
                    break;
                case '*':
                    st.push(num2 * num1);
                    break;
                case '^':
                    st.push(pow(num2, num1));
                    break;
            }
        }
    }
    
    return st.top();
}

int main(){
    string exp = "3.5 4 2 ^ 16 2 - * +";
    float result = evaluatePostfix(exp);
    cout<<result<<endl;

    string exp2 ="5 3 2 * + 9 6 / -";
    float result2 = evaluatePostfix(exp2);
    cout<<result2<<endl;

    string exp3 = "15 7 1 1 + - / 3 * 2 1 1 + + -";
    float result3 = evaluatePostfix(exp3);
    cout<<result3<<endl;
    return 0;
}