#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void printBottomToTop(stack<char> s) {
    vector<char> items;
    while (!s.empty()) {
        items.push_back(s.top());
        s.pop();
    }
    for (int i = static_cast<int>(items.size()) - 1; i >= 0; --i) {
        cout << items[i];
    }
    cout << '\n';
}

int main() {
    string initial;
    cin >> initial;

    stack<char> mainStack;
    stack<char> secondStack;

    for (char c : initial) {
        mainStack.push(c);
    }

    int q;
    cin >> q;

    while (q--) {
        string command;
        cin >> command;

        if (command == "PULL") {
            int x;
            cin >> x;

            if (x > static_cast<int>(mainStack.size())) {
                cout << "Macaron Furina tidak sebanyak itu pls!" << '\n';
                continue;
            }

            queue<char> temp;
            for (int i = 1; i < x; ++i) {
                temp.push(mainStack.top());
                mainStack.pop();
            }

            secondStack.push(mainStack.top());
            mainStack.pop();

            while (!temp.empty()) {
                mainStack.push(temp.front());
                temp.pop();
            }
        } else if (command == "PUT") {
            while (!secondStack.empty()) {
                mainStack.push(secondStack.top());
                secondStack.pop();
            }
        } else {
            cout << "Perintah tidak valid" << '\n';
        }
    }

    printBottomToTop(mainStack);
    printBottomToTop(secondStack);
    return 0;
}
