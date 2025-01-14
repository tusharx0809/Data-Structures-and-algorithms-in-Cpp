#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix to prefix
string postfixToPrefix(string postfix) {
    stack<string> s;

    // Traverse the postfix expression from left to right
    for (int i = 0; i < postfix.length(); i++) {
        // If the character is an operator
        if (isOperator(postfix[i])) {
            // Pop two operands from the stack
            if(s.size() < 2) return "Invalid Expression";
            
            string operand2 = s.top(); s.pop();
            string operand1 = s.top(); s.pop();

            // Concatenate the operator and the operands in prefix order
            string prefix = postfix[i] + operand1 + operand2;

            // Push the result back onto the stack
            s.push(prefix);
        }
        // If the character is a digit, handle multiple digits
        else if (isdigit(postfix[i])) {
            string num = "";
            // Read the whole number (in case of multiple digits)
            while (i < postfix.length() && isdigit(postfix[i])) {
                num += postfix[i++];
            }
            i--; // Decrease index because the loop will increment it
            s.push(num);
        }
    }

    // The final element in the stack is the prefix expression
    return s.top();
}

int main() {
    string postfix = "A B C / - A K / L - *";
    

    string prefix = postfixToPrefix(postfix);
    cout << "The prefix expression is: " << prefix << endl;

    return 0;
}
