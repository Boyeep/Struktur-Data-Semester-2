#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;

    queue<int> one;
    queue<int> two;
    int nextTicket = 1;

    while (q--) {
        string command;
        cin >> command;

        if (command == "arrive") {
            string type;
            cin >> type;
            if (type == "A") {
                one.push(nextTicket++);
            } else {
                two.push(nextTicket++);
            }
        } else if (command == "serve") {
            if (!one.empty() && !two.empty()) {
                cout << one.front() << ' ' << two.front() << '\n';
                one.pop();
                two.pop();
            } else if (!one.empty()) {
                cout << one.front() << '\n';
                one.pop();
            } else if (!two.empty()) {
                cout << two.front() << '\n';
                two.pop();
            } else {
                cout << "Tidak ada pelanggan" << '\n';
            }
        } else if (command == "status") {
            cout << "A:" << one.size() << " B:" << two.size() << '\n';
        }
    }

    return 0;
}
