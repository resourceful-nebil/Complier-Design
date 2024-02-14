#include <iostream>
#include <stack>
#include <unordered_set>

std::string validateArithmeticExpression(const std::string &s) {
    std::stack<char> charStack;
    int size = s.length();
    std::unordered_set<char> operation = {'*', '-', '+', '/', '%'};
    std::unordered_set<char> symbols = {'*', '-', '+', '/', '%', '(', ')'};
    int count = 0;

    for (int idx = 0; idx < size; ++idx) {
        char currentChar = s[idx];
        if (operation.find(currentChar) != operation.end()) {
            if (!charStack.empty() && idx + 1 != size) {
                if (operation.find(charStack.top()) != operation.end() || charStack.top() == '(') {
                    return "Invalid Expression";
                } else {
                    charStack.push(currentChar);
                }
            } else {
                return "Invalid Expression";
            }
        } else if (currentChar == '(') {
            if (!charStack.empty() && operation.find(charStack.top()) == operation.end() && charStack.top() != '(') {
                return "Invalid Expression";
            }
            charStack.push(currentChar);
            count += 1;
        } else if (currentChar == ')') {
            if (count <= 0 || operation.find(charStack.top()) != operation.end()) {
                return "Invalid Expression";
            }
            if (charStack.top() == '(') {
                charStack.pop();
            }
            count -= 1;
        } else {
            charStack.push(currentChar);
        }
    }
    if (count == 0 && operation.find(charStack.top()) == operation.end()){
        return "Valid Expression";
    }else{
        return "Invalid Expression";
    }
}

int main() {
    std::string expression;
    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, expression);

    std::string result = validateArithmeticExpression(expression);
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}
