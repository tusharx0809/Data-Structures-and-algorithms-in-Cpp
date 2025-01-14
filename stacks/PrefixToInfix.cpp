#include <bits/stdc++.h>
using namespace std;

// Check if the character is an operator
bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            return true;
    }
    return false;
}

// Function to convert prefix to infix
string prefixToInfix(string exp) {
    stack<string> s;
    int length = exp.size();

    // Start from the end of the string and process from right to left
    for (int i = length - 1; i >= 0; ) {
        // Skip spaces (if present in the input)
        if (exp[i] == ' ') {
            i--;
            continue;
        }

        // If the current character is an operator
        if (isOperator(exp[i])) {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // Create the infix expression with parentheses
            string temp = "(" + op1 + exp[i] + op2 + ")";
            s.push(temp);

            i--; // Move to the next character
        } else {
            // For multi-character operands, extract the entire operand
            string operand = "";

            // Traverse backward to find the full operand
            while (i >= 0 && !isOperator(exp[i]) && exp[i] != ' ') {
                operand = exp[i] + operand; // Add character to the front of the operand
                i--;
            }

            // Push the complete operand to the stack
            s.push(operand);
        }
    }

    // The final result is the only element left in the stack
    return s.top();
}

int main() {
    string s = "* - A / B C - / A K L";
    cout << "Infix: " << prefixToInfix(s) << endl;
    string s2 = "- + 10 * 20 ^ - ^ 30 4 50 + 6 * 70 8 90";
    cout <<"Infix: "<<prefixToInfix(s2) <<endl;
    return 0;
}
