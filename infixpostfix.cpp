#include <iostream>
#include <stack>
#include <cctype> // for isdigit function

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0; // Assuming operators are either '+', '-', '*', or '/'
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // Operand, add to postfix
        } else if (c == '(') {
            operatorStack.push(c); // Push '(' to stack
        } else if (c == ')') {
            // Pop operators from stack and add to postfix until '(' is encountered
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Remove '(' from stack
        } else if (isOperator(c)) {
            // Pop operators from stack and add to postfix while precedence is greater or equal
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c); // Push current operator to stack
        }
    }

    // Pop remaining operators from stack and add to postfix
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
        if (isdigit(c)) {
            operandStack.push(c - '0'); // Convert character to integer and push to stack
        } else if (isOperator(c)) {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            // Perform the operation and push the result back to the stack
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

    return operandStack.top(); // The final result is at the top of the stack
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
    cout << "Result after evaluation: " << result << endl;

    return 0;
}
