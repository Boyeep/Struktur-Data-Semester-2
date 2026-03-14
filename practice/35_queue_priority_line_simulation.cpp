#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;

    queue<string> normal;
    queue<string> priority;

    while (q--) {
        string command;
        cin >> command;

        if (command == "arrive") {
            string type, name;
            cin >> type >> name;
            if (type == "priority") {
                priority.push(name);
            } else {
                normal.push(name);
            }
        } else if (command == "serve") {
            if (!priority.empty()) {
                cout << priority.front() << '\n';
                priority.pop();
            } else if (!normal.empty()) {
                cout << normal.front() << '\n';
                normal.pop();
            } else {
                cout << "Queue kosong" << '\n';
            }
        } else if (command == "status") {
            cout << "priority=" << priority.size() << " normal=" << normal.size() << '\n';
        }
    }

    return 0;
}
