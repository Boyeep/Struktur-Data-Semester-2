#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;

    stack<int> values;
    stack<int> mins;

    while (q--) {
        string command;
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            values.push(x);
            if (mins.empty() || x <= mins.top()) {
                mins.push(x);
            }
        } else if (command == "pop") {
            if (values.empty()) {
                cout << "Stack kosong" << '\n';
            } else {
                if (values.top() == mins.top()) {
                    mins.pop();
                }
                values.pop();
            }
        } else if (command == "top") {
            if (values.empty()) {
                cout << "Stack kosong" << '\n';
            } else {
                cout << values.top() << '\n';
            }
        } else if (command == "min") {
            if (mins.empty()) {
                cout << "Stack kosong" << '\n';
            } else {
                cout << mins.top() << '\n';
            }
        }
    }

    return 0;
}
