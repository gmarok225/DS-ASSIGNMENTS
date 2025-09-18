#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expr) {
    stack<int>s;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        // Ignore spaces
        if (c == ' ')
            continue;

        // If operand (digit), push to stack
        if (isdigit(c)) {
            s.push(c - '0');  // Convert char to int or it will push ascii value
        }
        // If operator, pop two operands and apply operator
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop(); // p/q form

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string expr;
    cout << "Enter a postfix expression (single digits only): ";
    getline(cin, expr);

    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}

