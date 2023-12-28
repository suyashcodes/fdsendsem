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

string infixToPostfix(string infix){
    string postfix;
    stack<char> operatorstack;
    for(char ch:infix){
        switch(ch){
            case '(':
            operatorstack.push(ch);
            break;
            case ')':
            while(!operatorstack.empty()&&operatorstack.top()!='('){
                postfix+=operatorstack.top();
                operatorstack.pop();
            }
            if(!operatorstack.empty()){
                operatorstack.pop();
            }
            break;
            case '+':
            case '-':
            case '/': 
            case '*':
            while(!operatorstack.empty()&&getPrecedence(operatorstack.top())>=getPrecedence(ch)){
                postfix+=operatorstack.top();
                operatorstack.pop();
            }
            operatorstack.push(ch);
            default:
            if(isalnum(ch)){
                postfix+=ch;
            }

        }
    }
    while(!operatorstack.empty()){
        postfix+=operatorstack.top();
        operatorstack.pop();
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
