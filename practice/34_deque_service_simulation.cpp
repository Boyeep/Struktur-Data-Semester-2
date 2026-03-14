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

        if (command == "add") {
            int x;
            cin >> x;
            if (!reversed) {
                dq.push_back(x);
            } else {
                dq.push_front(x);
            }
        } else if (command == "vip") {
            int x;
            cin >> x;
            if (!reversed) {
                dq.push_front(x);
            } else {
                dq.push_back(x);
            }
        } else if (command == "serve_front") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else if (!reversed) {
                cout << dq.front() << '\n';
                dq.pop_front();
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (command == "serve_back") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else if (!reversed) {
                cout << dq.back() << '\n';
                dq.pop_back();
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (command == "reverse") {
            reversed = !reversed;
        } else if (command == "print") {
            if (dq.empty()) {
                cout << "Deque kosong" << '\n';
            } else if (!reversed) {
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
