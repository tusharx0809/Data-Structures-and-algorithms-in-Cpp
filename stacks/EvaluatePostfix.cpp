//Cpp program to evaluate Postfix expression

#include<bits/stdc++.h>
using namespace std;
bool isOperator(char x){
    return(x == '^' || x == '/' || x == '*' || x == '+' || x == '-');
}
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
    string exp = "3.5 4 2 ^ 6 2 - * +";
    float result = evaluatePostfix(exp);
    cout<<result<<endl;

    string exp2 ="5 3 2 * + 9 6 / -";
    float result2 = evaluatePostfix(exp2);
    cout<<result2<<endl;
    return 0;
}