#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
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

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;  // Operand, add to the postfix expression
        } else if (c == '(') {
            operatorStack.push(c);  // Push opening parenthesis onto the stack
        } else if (c == ')') {
            // Pop operators from the stack and add to the postfix expression until an opening parenthesis is encountered
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();  // Remove the opening parenthesis
        } else if (isOperator(c)) {
            // Pop operators from the stack and add to the postfix expression while their precedence is greater or equal
            // to the precedence of the current operator
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);  // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators from the stack and add to the postfix expression
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> operandStack;

    for (char c : postfix) {
        if (isalnum(c)) {
            operandStack.push(c - '0');  // Convert character to integer and push operand onto the stack
        } else if (isOperator(c)) {
            // Pop two operands from the stack, apply the operator, and push the result back onto the stack
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (c) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
            }
        }
    }

    // The final result is on top of the stack
    return operandStack.top();
}

int main() {
    string infixExpression;
    cout << "Enter the infix expression: ";
    cin >> infixExpression;

    // Convert infix to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfixExpression);
    cout << "Result of the expression: " << result << endl;

    return 0;
}
