#include <iostream>
using namespace std;

int applyOperation(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    }
    if (op == '-') {
        return a - b;
    }
    if (op == '*') {
        return a * b;
    }
    return 0;
}

int computeWithFunctionPointer(int a, int b, int (*operation)(int, int, char), char op) {
    return operation(a, b, op);
}

int main() {
    int a, b;
    char op;
    cin >> a >> op >> b;

    cout << computeWithFunctionPointer(a, b, applyOperation, op) << '\n';
    return 0;
}
