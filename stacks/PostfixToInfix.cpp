#include <bits/stdc++.h>
using namespace std;

// Check if character is an operator
bool isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

// Get Infix for a given postfix expression
string postfixToInfix(string exp) {
    stack<string> s;
    string number = "";
    
    for (int i = 0; i < exp.length(); i++) {
        // Handle multi-digit numbers
        if (isdigit(exp[i])) {
            // Keep adding digits to number string
            while (i < exp.length() && isdigit(exp[i])) {
                number += exp[i];
                i++;
            }
            s.push(number);
            number = "";
            i--; // Adjust i since for loop will increment it
        }
        // Handle variables (a-z, A-Z)
        else if (isalpha(exp[i])) {
            string operand(1, exp[i]);
            s.push(operand);
        }
        // Handle operators
        else if (isOperator(exp[i])) {
            if (s.size() < 2) {
                return "Invalid Expression";
            }
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    
    if (s.size() != 1) {
        return "Invalid Expression";
    }
    
    return s.top();
}

// Driver code
int main() {
    // Test cases
    vector<string> tests = {
        "23 45 +",          // Infix: (23+45)
        "123 456 *",        // Infix: (123*456)
        "ab*c+",           // Infix: ((a*b)+c)
        "12 3 * 4 +",      // Infix: ((12*3)+4)
        "5 abc *+",         //Infix: Invalid Expression
        "10 20 30 4 ^ 50 - 6 70 8 * + ^ * + 90 -", //((10+(20*(((30^4)-50)^(6+(70*8)))))-90)
        "15 20 + 30 12 - * 18 /" //(((15+20)*(30-12))/18)
    };
    
    for (const string& exp : tests) {
        cout << "Postfix: " << exp << endl;
        cout << "Infix: " << postfixToInfix(exp) << endl << endl;
    }
    
    return 0;
}