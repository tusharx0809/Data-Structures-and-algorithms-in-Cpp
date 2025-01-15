//Prefix to Postfix

#include <bits/stdc++.h>
using namespace std;

// Check if the character is an operator
bool isOperator(char x) {
    return (x == '^' || x == '/' || x == '*' || x == '+' || x == '-');
}

// Function to convert prefix to infix
string prefixToPostfix(string exp) {
    stack<string> s;
    int length = exp.size();

    // Start from the end of the string and process from right to left
    for (int i = length - 1; i >= 0; i--) {
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
            string temp = op1 + " " + op2 + " " + exp[i];
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
    cout << "Postfix: " << prefixToPostfix(s) << endl; //A B C / - A K / L - *
    string s2 = "- + 10 * 20 ^ - ^ 30 4 50 + 6 * 70 8 90"; 
    cout <<"Postfix: "<<prefixToPostfix(s2) <<endl; //10 20 30 4 ^ 50 - 6 70 8 * + ^ * + 90 -
    return 0;
}
