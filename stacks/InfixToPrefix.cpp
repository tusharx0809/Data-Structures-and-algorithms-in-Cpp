// Program to convert Infix Notation to Prefix

// Infix: (A-B/C) * (A/K-L)
// PostFix: *-A/BC-/AKL

// Infix -> ReverseInfix( '(' to ')' and ')' to '(' ) -> Postfix -> ReversePostfix(Prefix)

#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string reverse(string s){
    string result;

    for(int i=s.length()-1;i>=0;i--){
        if(s[i] == '('){
            result += ')';
        }else if(s[i] == ')'){
            result += '(';
        }else{
            result += s[i];
        }
    }
    return result;
}

void infixToPrefix(string s)
{   
    string reverseInfix = reverse(s);
    stack<char> st;
    string result;

    for (int i = 0; i < reverseInfix.length(); i++)
    {
        char c = reverseInfix[i];
        if(c == ' '){
            continue;
        }
        // Handle multi-digit numbers
        if (isdigit(c))
        {
            string num = "";
            while (i < reverseInfix.length() && (isdigit(reverseInfix[i]) || reverseInfix[i] == '.'))
            {
                num += reverseInfix[i];
                i++;
            }
            result += num + ' '; // Separate numbers with a space
            i--; // Adjust index
        }
        else if (isalpha(c)) // Handle variables like a, b, c
        {
            result += c;
            result += ' ';
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                result += ' ';
                st.pop();
            }
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            
        }
        else // Operators
        {
            while (!st.empty() && precedence(c) < precedence(st.top()))
            {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        result += ' ';
        st.pop();
    }

    cout << reverse(result) << endl;
}

int main(){
    string s = "(A-B/C)*(A/K-L)";
    infixToPrefix(s); //* - A / B C - / A K L
    infixToPrefix("x+y*z/w+u"); //+ + x / * y z w u
    infixToPrefix("a+b*(c^d-e)^(f+g*h)-i"); //- + a * b ^ - ^ c d e + f * g h i
    infixToPrefix("10.23+20*(30^4-50)^(6+70*8)-90"); //- + 10 * 20 ^ - ^ 30 4 50 + 6 * 70 8 90
    infixToPrefix("3.5 + 4 ^ 2 * (6 - 2)");
    return 0;
}