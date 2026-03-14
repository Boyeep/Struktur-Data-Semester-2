#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;

    stack<string> backHistory;
    stack<string> forwardHistory;
    string current = "home";

    while (q--) {
        string command;
        cin >> command;

        if (command == "visit") {
            string page;
            cin >> page;
            backHistory.push(current);
            current = page;
            while (!forwardHistory.empty()) {
                forwardHistory.pop();
            }
        } else if (command == "back") {
            if (backHistory.empty()) {
                cout << "Tidak bisa back" << '\n';
            } else {
                forwardHistory.push(current);
                current = backHistory.top();
                backHistory.pop();
            }
        } else if (command == "forward") {
            if (forwardHistory.empty()) {
                cout << "Tidak bisa forward" << '\n';
            } else {
                backHistory.push(current);
                current = forwardHistory.top();
                forwardHistory.pop();
            }
        } else if (command == "current") {
            cout << current << '\n';
        }
    }

    return 0;
}
