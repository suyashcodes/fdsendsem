#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix;

    for (char ch : infix) {
        switch (ch) {
            case '(':
                operatorStack.push(ch);
                break;
            case ')':
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                if (!operatorStack.empty()) {
                    operatorStack.pop();
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(ch)) {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(ch);
                break;
            default:
                if (isalnum(ch)) {
                    postfix += ch;
                }
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;

    cout << "Enter infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
