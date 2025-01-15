#include<bits/stdc++.h>
using namespace std;

bool isOperator(char x) {
    return (x == '^' || x == '/' || x == '*' || x == '+' || x == '-');
}

float evaluatePrefix(string exp) {
    stack<float> st;
    string num="";

    for(int i=exp.length()-1; i>=0; i--){
        char c = exp[i];
        if(c == ' '){
            continue;
        }
        if(isdigit(c) || c == '.'){
            num = c + num;
            if(i-1 < 0 || (!isdigit(exp[i-1]) && exp[i-1] != '.')){
                st.push(stof(num));
                num="";
            }
        }else{
            if(st.size() < 2){
                cout<<"Infsufficient operands";
                return -1;
            }
            float num2 = st.top();
            st.pop();
            float num1 = st.top();
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

int main() {
    string exp = "+ 3.5 * ^ 4 2 - 16 2";  // Example: 3.5 + (4^2 * (16-2)) = 227.5
    float result = evaluatePrefix(exp);
    cout<<result<<endl;
    return 0;
}