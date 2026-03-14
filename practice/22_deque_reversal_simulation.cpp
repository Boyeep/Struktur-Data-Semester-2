#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;

    deque<int> dq;
    bool reversed = false;

    while (q--) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int x;
            cin >> x;
            if (!reversed) {
                dq.push_front(x);
            } else {
                dq.push_back(x);
            }
        } else if (command == "push_back") {
            int x;
            cin >> x;
            if (!reversed) {
                dq.push_back(x);
            } else {
                dq.push_front(x);
            }
        } else if (command == "pop_front") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else if (!reversed) {
                dq.pop_front();
            } else {
                dq.pop_back();
            }
        } else if (command == "pop_back") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else if (!reversed) {
                dq.pop_back();
            } else {
                dq.pop_front();
            }
        } else if (command == "reverse") {
            reversed = !reversed;
        } else if (command == "front") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else {
                cout << (!reversed ? dq.front() : dq.back()) << '\n';
            }
        } else if (command == "back") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else {
                cout << (!reversed ? dq.back() : dq.front()) << '\n';
            }
        } else if (command == "print") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
                continue;
            }

            if (!reversed) {
                for (int i = 0; i < static_cast<int>(dq.size()); ++i) {
                    cout << dq[i] << (i + 1 == static_cast<int>(dq.size()) ? '\n' : ' ');
                }
            } else {
                for (int i = static_cast<int>(dq.size()) - 1; i >= 0; --i) {
                    cout << dq[i] << (i == 0 ? '\n' : ' ');
                }
            }
        }
    }

    return 0;
}
