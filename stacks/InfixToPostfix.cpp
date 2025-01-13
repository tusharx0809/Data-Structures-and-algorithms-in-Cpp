// This program consists conversion of infix to postfix expression

// Infix:  a+b*(c^d-e)^(f+g*h)-i
// Postfix: abcd^e-fgh*+^*+i-

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

void infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // Handle multi-digit numbers
        if (isdigit(c))
        {
            while (i <  s.length() && isdigit(s[i]))
            {
                result += s[i];
                i++;
            }
            result += ' '; // Separate numbers with a space
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
            while (st.top() != '(')
            {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.pop();
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

    cout << result << endl;
}

int main()
{
    string exp = "10+20*(30^4-50)^(6+70*8)-90";
    infixToPostfix(exp);
    // Output: 10 20 30 4 ^ 50 - 6 70 8 * + ^ * + 90 -

    infixToPostfix("a+b*(c^d-e)^(f+g*h)-i");
    //Output: a b c d ^ e - f g h * + ^ * + i -

    return 0;
}
