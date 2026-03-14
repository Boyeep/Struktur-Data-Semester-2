#include <cctype>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

int main() {
    string infix;
    cin >> infix;

    stack<char> ops;
    string postfix;

    for (char c : infix) {
        if (isalnum(static_cast<unsigned char>(c))) {
            postfix += c;
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();
                ops.pop();
            }
            if (!ops.empty()) {
                ops.pop();
            }
        } else {
            while (!ops.empty() && ops.top() != '(' &&
                   (precedence(ops.top()) > precedence(c) ||
                    (precedence(ops.top()) == precedence(c) && !isRightAssociative(c)))) {
                postfix += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        postfix += ops.top();
        ops.pop();
    }

    cout << postfix << '\n';
    return 0;
}
