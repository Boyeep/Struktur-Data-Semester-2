#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

class QueueWithTwoStacks {
private:
    stack<int> inStack;
    stack<int> outStack;

    void moveIfNeeded() {
        if (!outStack.empty()) {
            return;
        }
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    void push(int x) {
        inStack.push(x);
    }

    void pop() {
        moveIfNeeded();
        if (outStack.empty()) {
            cout << "Queue kosong" << '\n';
            return;
        }
        outStack.pop();
    }

    void front() {
        moveIfNeeded();
        if (outStack.empty()) {
            cout << "Queue kosong" << '\n';
            return;
        }
        cout << outStack.top() << '\n';
    }

    void size() {
        cout << inStack.size() + outStack.size() << '\n';
    }
};

int main() {
    int q;
    cin >> q;

    QueueWithTwoStacks qu;
    while (q--) {
        string command;
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            qu.push(x);
        } else if (command == "pop") {
            qu.pop();
        } else if (command == "front") {
            qu.front();
        } else if (command == "size") {
            qu.size();
        }
    }

    return 0;
}
