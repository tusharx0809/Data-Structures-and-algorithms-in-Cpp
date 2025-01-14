//Prefix to Postfix

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
string postfixToPrefix(string exp) {
    stack<string> s;
    int length = exp.size();

    // Start from the end of the string and process from right to left
    for (int i = 0; i < length; i++ ) {
        // Skip spaces (if present in the input)
        if (exp[i] == ' ') {
            continue;
        }

        // If the current character is an operator
        if (isOperator(exp[i])) {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // Create the infix expression with parentheses
            string temp = exp[i] + " " + op2 + " " + op1;
            s.push(temp);

 
        } else {
            // For multi-character operands, extract the entire operand
            string operand = "";

            // Traverse backward to find the full operand
            while (i < length && !isOperator(exp[i]) && exp[i] != ' ') {
                operand = exp[i] + operand; // Add character to the front of the operand
                i++;
            }

            i--;
            s.push(operand);
        }
    }

    
    return s.top();
}

int main() {
    string s = "A B C / - A K / L - *";
    cout << "Prefix: " << postfixToPrefix(s) << endl; //A B C / - A K / L - *
    string s2 = "10 20 30 4 ^ 50 - 6 70 8 * + ^ * + 90 -"; 
    cout <<"Prefix: "<<postfixToPrefix(s2) <<endl; //10 20 30 4 ^ 50 - 6 70 8 * + ^ * + 90 -
    return 0;
}
