
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

bool isKeyword(std::string token) {
    // List of C++ keywords
    std::string keywords[] = {"int", "float", "if", "else", "for", "while", "do", "return", "class", "struct", "void"}; // Add more keywords as needed

    for (std::string keyword : keywords) {
        if (token == keyword) {
            return true;
        }
    }
    return false;
}

bool isIdentifier(std::string token) {
    if (isalpha(token[0]) || token[0] == '_') {
        for (char c : token) {
            if (!isalnum(c) && c != '_') {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isConstant(std::string token) {
    // Check if token is a constant (integer or float)
    return (token.find_first_not_of("0123456789.") == std::string::npos);
}

bool isOperator(char token) {
    // List of C++ operators
    std::string operators = "+-*/%=<>&|!^";

    return operators.find(token) != std::string::npos;
}

bool isSpecialSymbol(char token) {
    // List of C++ special symbols
    std::string symbols = "{}[](),.:;#";

    return symbols.find(token) != std::string::npos;
}

int main() {
    std::string statement;
    std::cout << "Enter a statement: ";
    std::getline(std::cin, statement);

    std::stringstream ss(statement);
    std::string token;

    while (ss >> token) {
        if (isKeyword(token)) {
            std::cout << token << " is a keyword" << std::endl;
        } else if (isIdentifier(token)) {
            std::cout << token << " is an identifier" << std::endl;
        } else if (isConstant(token)) {
            std::cout << token << " is a constant" << std::endl;
        } else {
            for (char c : token) {
                if (isOperator(c)) {
                    std::cout << c << " is an operator" << std::endl;
                } else if (isSpecialSymbol(c)) {
                    std::cout << c << " is a special symbol" << std::endl;
                }
            }
        }
    }

    return 0;
}
