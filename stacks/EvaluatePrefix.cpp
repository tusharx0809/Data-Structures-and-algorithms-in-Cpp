//CPP program to evaluate Prefix expressions

#include<bits/stdc++.h>
using namespace std;
bool isOperator(char x){
    return (x == '^' || x == '/' || x == '*' || x == '+' || x == '-');
}
string reverseFloatingNumber(string exp){
    string result="";
    for(int i = exp.length()-1; i >=0; i--){
        result += exp[i];
    }
    return result;
}
float evaluatePrefix(string exp){
    string<float> st;
    string num;

    for(int i=exp.length(); i>=0; i--){
        char c = exp[i];
        
        if(c == ' '){
            continue;
        }
        if(isdigit(c) ){
                         
        }
    }
}
int main(){

    string exp = "+ 3.5 * ^ 4 2 - 6 2";
    float result = evaluatePrefix(exp);
    cout<<result;

    return 0;
}