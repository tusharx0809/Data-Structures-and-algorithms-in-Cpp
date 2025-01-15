#include<bits/stdc++.h>
using namespace std;

bool isOperator(char x) {
    return (x == '^' || x == '/' || x == '*' || x == '+' || x == '-');
}

float evaluatePrefix(string exp) {
    stack<float> s;
    string num;

    for(int i=exp.length()-1; i>=0; i--){
        char c = exp[i];
        if(c == ' '){
            continue;
        }
        if(isdigit(c) || c == '.'){
            num = c + num;
        }
    }
}

int main() {
    string exp = "+ 3.5 * ^ 4 2 - 6 2";  // Example: 3.5 + (4^2 * (6-2)) = 67.5
    float result = evaluatePrefix(exp);
    cout<<result<<endl;
    return 0;
}