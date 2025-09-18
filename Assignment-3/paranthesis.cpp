#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Function to check balanced parentheses
int isBalanced(string expr) {
    stack<char>s;  // empty stack
int len=expr.length(); // strlen is for strings
    for (int i = 0; i < len; i++) {
        char c = expr[i];

        // If opening bracket, push to stack
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        // If closing bracket
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return 0;  // no opening bracket

            char top = s.top();  // top element
            s.pop();

            if ((top == '(' && c != ')') ||     // || stands for 'or'
    (top == '{' && c != '}') ||                // correct pair to be matched
    (top == '[' && c != ']'))
    return 0;
             //code ithe hi end ho jna je mismatch hoya te
        }
    }

    if (s.empty())     // saare match hoge ta saare pop hojne te stack khaali hojna
        return 1; // balanced // code pura chlana va jd tk empty na hoje stack, problem vich vi ho skdi
    else
        return 0; // ()} de case ch } bachu te empty ni hoya
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr) == 1)
        cout << "Balanced!" << endl;
    else
        cout << "Not Balanced!" << endl;

    return 0;
}

