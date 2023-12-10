#include <iostream>
#include <stack>
#include <string>

bool isWellParenthesized(const std::string& expression) {
    std::stack<char> charStack;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            charStack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (charStack.empty()) {
                return false;  // Unbalanced closing parenthesis without an opening one
            }

            char top = charStack.top();
            charStack.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;  // Mismatched closing parenthesis
            }
        }
    }

    return charStack.empty();  // Check if there are any unmatched opening parenthesis left
}

int main() {
    std::string expression;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    if (isWellParenthesized(expression)) {
        std::cout << "The expression is well-parenthesized.\n";
    } else {
        std::cout << "The expression is not well-parenthesized.\n";
    }

    return 0;
}
