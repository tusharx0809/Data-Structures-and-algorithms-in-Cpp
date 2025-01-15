#include<bits/stdc++.h>
using namespace std;

bool isOperator(char x) {
    return (x == '^' || x == '/' || x == '*' || x == '+' || x == '-');
}

float evaluatePrefix(string exp) {
    
}

int main() {
    string exp = "+ 3.5 * ^ 4 2 - 6 2";  // Example: 3.5 + (4^2 * (6-2)) = 67.5
    float result = evaluatePrefix(exp);
    cout<<result<<endl;
    return 0;
}