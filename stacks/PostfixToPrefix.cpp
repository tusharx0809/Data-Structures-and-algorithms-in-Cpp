#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

// Function to check if a token is an operator
bool isOperator(const string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/" || token == "^");
}

// Function to convert postfix to prefix
string postfixToPrefix(string postfix) {
    stack<string> s;
    stringstream ss(postfix);
    string token;

    // Split the input into tokens using a space delimiter
    while (ss >> token) {
        // If the token is an operator
        if (isOperator(token)) {
            // Pop two operands from the stack
            if (s.size() < 2) return "Invalid Expression";

            string operand1 = s.top(); s.pop();
            string operand2 = s.top(); s.pop();

            // Concatenate the operator and the operands in prefix order
            string prefix = token + " " + operand2 + " " + operand1;

            // Push the result back onto the stack
            s.push(prefix);
        }
        // If the token is an operand
        else {
            // Push the operand directly onto the stack
            s.push(token);
        }
    }

    // The final element in the stack is the prefix expression
    return s.size() == 1 ? s.top() : "Invalid Expression";
}

int main() {
    string postfix = "A B C / - A K / L - *";

    string prefix = postfixToPrefix(postfix);
    cout << "The prefix expression is: " << prefix << endl; //* - A / B C - / A K L

    return 0;
}
