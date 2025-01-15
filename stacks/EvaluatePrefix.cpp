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
int main(){
    // string exp = "+ 3.5 * ^ 4 2 - 6 2";
    // float result = evaluatePrefix(exp);
    // cout<<result;

    string exp = "5.3";
    string res = floatingNumber(exp);
    cout<<res;
    return 0;
}