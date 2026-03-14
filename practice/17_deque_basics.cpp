#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;

    deque<int> dq;
    while (q--) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        } else if (command == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        } else if (command == "pop_front") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else {
                dq.pop_front();
            }
        } else if (command == "pop_back") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else {
                dq.pop_back();
            }
        } else if (command == "front") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else {
                cout << dq.front() << '\n';
            }
        } else if (command == "back") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else {
                cout << dq.back() << '\n';
            }
        } else if (command == "print") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else {
                for (int i = 0; i < static_cast<int>(dq.size()); ++i) {
                    cout << dq[i] << (i + 1 == static_cast<int>(dq.size()) ? '\n' : ' ');
                }
            }
        }
    }

    return 0;
}
